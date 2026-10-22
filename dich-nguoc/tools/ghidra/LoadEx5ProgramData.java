// Import captured program data and verified native function ranges.
// Labels here are analysis labels, not recovered author variable names.
// @category EX5Research
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.CommentType;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;
import java.nio.file.Files;
import java.nio.file.Path;
import java.io.InputStream;
import java.util.Base64;
import java.nio.charset.StandardCharsets;

public class LoadEx5ProgramData extends GhidraScript {
    private Address address(String text) {
        return toAddr(Long.parseUnsignedLong(text, 16));
    }
    @Override
    public void run() throws Exception {
        Path metadata = Path.of(getScriptArgs()[0]);
        for (String line : Files.readAllLines(metadata.resolve("data.tsv"))) {
            String[] fields = line.split("\\t", 2);
            Path source = Path.of(fields[1]);
            if (!source.isAbsolute()) source = metadata.resolve(source).normalize();
            try (InputStream input = Files.newInputStream(source)) {
                MemoryBlock block = currentProgram.getMemory().createInitializedBlock(
                    "captured_program_data", address(fields[0]), input, Files.size(source), monitor, false);
                block.setRead(true);
                block.setWrite(true);
                block.setExecute(false);
            }
        }
        StructureDataType stringView = new StructureDataType("MqlStringAnalysisView", 0);
        stringView.setExplicitPackingValue(1);
        stringView.add(new DWordDataType(), "opaque", "Not an author variable name");
        stringView.add(new PointerDataType(new WideChar16DataType(), 8, currentProgram.getDataTypeManager()),
            "text", "Pointer checked against captured UTF-16 text");
        if (stringView.getLength() != 12) throw new IllegalStateException("String view must be 12 bytes");
        int strings = 0, references = 0, functions = 0;
        for (String line : Files.readAllLines(metadata.resolve("strings.tsv"))) {
            String[] fields = line.split("\\t", -1);
            Address start = address(fields[0]);
            int length = Integer.parseInt(fields[1]);
            currentProgram.getListing().createData(start, new UnicodeDataType(), (length + 1) * 2);
            createLabel(start, "literal_" + fields[0], true);
            String text = new String(Base64.getDecoder().decode(fields[2]), StandardCharsets.UTF_8);
            currentProgram.getListing().setComment(start, CommentType.EOL, text);
            strings++;
        }
        for (String line : Files.readAllLines(metadata.resolve("refs.tsv"))) {
            String[] fields = line.split("\\t");
            Address start = address(fields[0]);
            createData(start, stringView);
            createLabel(start, "string_ref_" + fields[0], true);
            references++;
        }
        for (String line : Files.readAllLines(metadata.resolve("functions.tsv"))) {
            String[] fields = line.split("\\t");
            Address begin = address(fields[0]), end = address(fields[1]).subtract(1);
            disassemble(begin);
            if (getFunctionAt(begin) == null) {
                currentProgram.getFunctionManager().createFunction(null, begin, new AddressSet(begin, end), SourceType.ANALYSIS);
            } else {
                getFunctionAt(begin).setBody(new AddressSet(begin, end));
            }
            functions++;
        }
        println("EX5_DATA strings=" + strings + " references=" + references + " verified_native_ranges=" + functions);
    }
}
