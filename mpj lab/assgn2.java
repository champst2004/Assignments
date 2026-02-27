import java.io.FileWriter;
import java.io.IOException;

public class assgn2 {
    interface Report {
        void saveToFile();
    }
    static abstract class Traffic {
        String number;
        int speed;

        Traffic(String number, int speed) {
            this.number = number;
            this.speed = speed;
        }

        abstract boolean checkViolation();
    }

    static class Record extends Traffic implements Report {

        Record(String number, int speed) {
            super(number, speed);
        }

        boolean checkViolation() {
            return speed > 70;
        }

        public void saveToFile() {
            try {
                FileWriter fw = new FileWriter("output.txt", true);
                fw.write("Vehicle: " + number + " | Speed: " + speed + " | Violation: " + checkViolation() + "\n");
                fw.close();
            } catch (IOException e) {
                System.out.println("File error");
            }
        }
    }
    public static void main(String[] args) {
        Record r1 = new Record("MH12AB1234", 80);
        Record r2 = new Record("MH14CD5678", 60);
        Record r3 = new Record("MH01XY9999", 95);

        r1.saveToFile();
        r2.saveToFile();
        r3.saveToFile();

        System.out.println("output.txt file created successfully.");
    }
}