// Recover stack arguments using tags measured at each call site.
// @category EX5Research
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.Function;
import ghidra.program.model.pcode.HighFunctionDBUtil;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;

public class OverrideMqlDispatchCalls extends GhidraScript {
    private DataType valueType(String tag) {
        switch (tag) {
            case "0x520004": return new IntegerDataType();
            case "0x530014": return new UnsignedIntegerDataType();
            case "0x540005":
            case "0x550005": return new LongLongDataType();
            case "0x560015": return new UnsignedLongLongDataType();
            case "0x580007": return new DoubleDataType();
            case "0x590008": return new PointerDataType(new VoidDataType(), 8, currentProgram.getDataTypeManager());
            default: throw new IllegalArgumentException("Unverified argument tag: " + tag);
        }
    }
    @Override
    public void run() throws Exception {
        int count = 0;
        for (String line : Files.readAllLines(Path.of(getScriptArgs()[0]))) {
            String[] row = line.split("\\t", -1);
            Address call = toAddr(Long.parseUnsignedLong(row[0], 16));
            Function owner = getFunctionContaining(call);
            if (owner == null) throw new IllegalStateException("No owner at " + call);
            FunctionDefinitionDataType signature = new FunctionDefinitionDataType("mql_call_" + row[0]);
            signature.setReturnType(new LongLongDataType());
            signature.setCallingConvention("__fastcall");
            ArrayList<ParameterDefinition> parameters = new ArrayList<>();
            parameters.add(new ParameterDefinitionImpl("context", new PointerDataType(new VoidDataType(), 8, currentProgram.getDataTypeManager()), null));
            parameters.add(new ParameterDefinitionImpl("operation", new IntegerDataType(), null));
            parameters.add(new ParameterDefinitionImpl("argument_count", new IntegerDataType(), null));
            String[] tags = row[2].isEmpty() ? new String[0] : row[2].split(",");
            if (tags.length != Integer.parseInt(row[1])) throw new IllegalArgumentException("Argument count mismatch");
            for (int i = 0; i < tags.length; i++) {
                parameters.add(new ParameterDefinitionImpl("type_" + i, new UnsignedIntegerDataType(), null));
                parameters.add(new ParameterDefinitionImpl("value_" + i, valueType(tags[i]), null));
            }
            signature.setArguments(parameters.toArray(new ParameterDefinition[0]));
            HighFunctionDBUtil.writeOverride(owner, call, signature);
            count++;
        }
        println("MQL_DISPATCH_CALL_OVERRIDES " + count);
    }
}
