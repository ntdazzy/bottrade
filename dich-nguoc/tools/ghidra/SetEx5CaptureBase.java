// Keep absolute addresses equal to the captured tester process.
// @category EX5Research
import ghidra.app.script.GhidraScript;
import java.nio.file.Files;
import java.nio.file.Path;

public class SetEx5CaptureBase extends GhidraScript {
    @Override
    public void run() throws Exception {
        Path metadata = Path.of(getScriptArgs()[0]);
        String value = Files.readString(metadata.resolve(currentProgram.getName() + ".base.txt")).trim();
        currentProgram.setImageBase(toAddr(Long.parseUnsignedLong(value, 16)), true);
        println("EX5_BASE " + currentProgram.getName() + " " + value);
    }
}
