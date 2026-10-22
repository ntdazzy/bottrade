// Apply observed names/storage widths. These are analysis annotations.
// @category EX5Research
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.ParameterImpl;
import ghidra.program.model.listing.Variable;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;

public class AnnotateTwister extends GhidraScript {
    private Address at(String text) {
        return toAddr(Long.parseUnsignedLong(text, 16));
    }
    private DataType nativeType(String code) {
        switch (code) {
            case "i": return new IntegerDataType();
            case "j": return new UnsignedIntegerDataType();
            case "l": return new LongLongDataType();
            case "u": return new UnsignedLongLongDataType();
            case "d": return new DoubleDataType();
            case "b": return new BooleanDataType();
            case "v": return new VoidDataType();
            default: return new PointerDataType(new VoidDataType(), 8, currentProgram.getDataTypeManager());
        }
    }
    private void variables(Path path) throws Exception {
        StructureDataType view = new StructureDataType("MqlStringAnalysisView", 0);
        view.setExplicitPackingValue(1);
        view.add(new DWordDataType(), "opaque", "Analysis field");
        view.add(new PointerDataType(new WideChar16DataType(), 8, currentProgram.getDataTypeManager()), "text", "Observed buffer pointer");
        for (String line : Files.readAllLines(path)) {
            String[] row = line.split("\\t");
            Address address = at(row[0]);
            DataType type = row[2].equals("double") ? new DoubleDataType()
                : row[2].equals("bool") ? new BooleanDataType()
                : row[2].equals("long") ? new LongLongDataType()
                : row[2].equals("ulong") ? new UnsignedLongLongDataType()
                : row[2].equals("string") ? view : new IntegerDataType();
            clearListing(address, address.add(type.getLength() - 1));
            createData(address, type);
            createLabel(address, row[1], true);
        }
    }
    @Override
    public void run() throws Exception {
        Path metadata = Path.of(getScriptArgs()[0]);
        variables(metadata.resolve("inputs.tsv"));
        variables(metadata.resolve("predefined.tsv"));
        if (Files.exists(metadata.resolve("state.tsv"))) variables(metadata.resolve("state.tsv"));
        int labels = 0;
        for (String line : Files.readAllLines(metadata.resolve("native-labels.tsv"))) {
            String[] row = line.split("\\t");
            Address address = at(row[0]);
            createLabel(address, row[1], true);
            if (row[1].equals("__chkstk")) {
                if (!currentProgram.getMemory().contains(address)) {
                    MemoryBlock block = currentProgram.getMemory().createUninitializedBlock("stack_probe_symbol", address, 1, false);
                    block.setRead(true);
                    block.setExecute(true);
                }
                Function function = getFunctionAt(address);
                if (function == null) {
                    function = currentProgram.getFunctionManager().createFunction("__chkstk", address, new AddressSet(address), SourceType.ANALYSIS);
                }
                function.setCallFixup("alloca_probe");
                function.setReturnType(new VoidDataType(), SourceType.ANALYSIS);
            }
            labels++;
        }
        int signatures = 0;
        for (String line : Files.readAllLines(metadata.resolve("native-signatures.tsv"))) {
            String[] row = line.split("\\t", -1);
            Address entry = at(row[0]);
            if (!currentProgram.getMemory().contains(entry)) {
                MemoryBlock block = currentProgram.getMemory().createUninitializedBlock("native_symbol_" + row[0], entry, 1, false);
                block.setRead(true);
                block.setExecute(true);
            }
            Function function = getFunctionAt(entry);
            if (function == null) {
                function = currentProgram.getFunctionManager().createFunction(row[1], entry, new AddressSet(entry), SourceType.ANALYSIS);
            }
            function.setCallingConvention("__fastcall");
            function.setReturnType(nativeType(row[2]), SourceType.ANALYSIS);
            ArrayList<Variable> parameters = new ArrayList<>();
            if (!row[3].isEmpty()) {
                String[] types = row[3].split(",");
                for (int i = 0; i < types.length; i++) {
                    parameters.add(new ParameterImpl("arg_" + i, nativeType(types[i]), currentProgram));
                }
            }
            function.replaceParameters(parameters, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.ANALYSIS);
            function.setVarArgs(Boolean.parseBoolean(row[4]));
            function.setNoReturn(Boolean.parseBoolean(row[5]));
            signatures++;
        }
        println("TWISTER_ANNOTATIONS inputs=28 predefined=8 native_labels=" + labels);
        println("TWISTER_NATIVE_SIGNATURES " + signatures);
    }
}
