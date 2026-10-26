// Read-only retry of one captured function, retaining the earlier failed export.
// @category EX5Research
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.nio.file.Files;
import java.nio.file.Path;

public class ExportOneCapturedFunction extends GhidraScript {
    @Override public void run() throws Exception {
        String[] args=getScriptArgs();
        if(args.length!=3) throw new IllegalArgumentException("Expected absolute hex entry, new output path, timeout seconds");
        Address entry=toAddr(Long.parseUnsignedLong(args[0],16));
        Path output=Path.of(args[1]);int timeout=Integer.parseInt(args[2]);
        if(timeout<1 || timeout>300 || Files.exists(output)) throw new IllegalArgumentException("Invalid timeout or output already exists");
        Function function=getFunctionAt(entry);
        if(function==null || currentProgram.getMemory().getBlock(entry)==null || !currentProgram.getMemory().getBlock(entry).isInitialized()) throw new IllegalArgumentException("Not an existing captured function entry");
        DecompInterface decompiler=new DecompInterface();
        try {
            if(!decompiler.openProgram(currentProgram)) throw new IllegalStateException(decompiler.getLastMessage());
            DecompileResults result=decompiler.decompileFunction(function,timeout,monitor);
            String text="/* Read-only single-function retry. Address: "+entry+"; unverified C-like output. */\n";
            if(result.decompileCompleted() && result.getDecompiledFunction()!=null) text+=result.getDecompiledFunction().getC();
            else text+="/* DECOMPILATION FAILED: "+result.getErrorMessage().replace("*/","* /")+" */\n";
            Files.writeString(output,text);
            println("SINGLE_CAPTURED_FUNCTION entry="+entry+" completed="+result.decompileCompleted()+" timeout="+timeout);
        } finally { decompiler.dispose(); }
    }
}
