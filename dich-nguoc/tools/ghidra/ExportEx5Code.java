// Export C-like descriptions of captured code. This does not recreate MQ5 source.
// @category EX5Research
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import java.nio.file.Files;
import java.nio.file.Path;
import java.io.BufferedWriter;

public class ExportEx5Code extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length > 2 && currentProgram.getMemory().getBlock(args[2]) == null) {
            throw new IllegalStateException("Required captured data block is missing: " + args[2]);
        }
        Path candidates = Path.of(args[0]);
        Path output = Path.of(args[1]);
        if (Files.isDirectory(candidates)) {
            candidates = candidates.resolve(currentProgram.getName() + ".seeds.txt");
        }
        if (Files.isDirectory(output)) {
            output = output.resolve(currentProgram.getName().replaceFirst("\\.bin$", "") + ".c");
        }
        if (Files.exists(output)) {
            throw new IllegalArgumentException("Output already exists");
        }
        int seeded = 0;
        for (String line : Files.readAllLines(candidates)) {
            if (line.isBlank()) continue;
            Address address = toAddr(Long.parseUnsignedLong(line.trim(), 16));
            if (currentProgram.getMemory().contains(address)) {
                disassemble(address);
                if (getFunctionAt(address) == null && createFunction(address, null) != null) seeded++;
            }
        }
        analyzeChanges(currentProgram);
        DecompInterface decompiler = new DecompInterface();
        int completed = 0, failed = 0;
        try (BufferedWriter writer = Files.newBufferedWriter(output)) {
            writer.write("/* UNVERIFIED C-LIKE DECOMPILATION OF CAPTURED NATIVE CODE.\n");
            writer.write(" * Not original MQ5 source. Names, types and external calls may be unresolved.\n");
            writer.write(" * No claim of complete recovery or compilable trading logic.\n */\n\n");
            if (!decompiler.openProgram(currentProgram)) {
                throw new IllegalStateException(decompiler.getLastMessage());
            }
            FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
            while (functions.hasNext() && !monitor.isCancelled()) {
                Function function = functions.next();
                if (currentProgram.getMemory().getBlock(function.getEntryPoint()) == null ||
                    !currentProgram.getMemory().getBlock(function.getEntryPoint()).isInitialized()) {
                    continue;
                }
                DecompileResults result = decompiler.decompileFunction(function, 20, monitor);
                writer.write("\n/* Address: " + function.getEntryPoint() + " */\n");
                if (result.decompileCompleted() && result.getDecompiledFunction() != null) {
                    writer.write(result.getDecompiledFunction().getC());
                    writer.write("\n");
                    completed++;
                } else {
                    writer.write("/* DECOMPILATION FAILED: " + result.getErrorMessage().replace("*/", "* /") + " */\n");
                    failed++;
                }
            }
        } finally {
            decompiler.dispose();
        }
        Files.writeString(output.resolveSibling(output.getFileName() + ".summary.json"),
            "{\"seeded\":" + seeded + ",\"completed\":" + completed + ",\"failed\":" + failed + "}\n");
        println("EX5_EXPORT seeded=" + seeded + " completed=" + completed + " failed=" + failed);
    }
}
