import java.util.*;

public class assgn4 {
    static class Student {
        int id;
        String name;
        int marks1, marks2, marks3;

        Student(int id, String name, int m1, int m2, int m3) {
            this.id = id;
            this.name = name;
            this.marks1 = m1;
            this.marks2 = m2;
            this.marks3 = m3;
        }
    }
    static class ResultTask extends Thread {
        Student student;

        ResultTask(Student s) {
            this.student = s;
        }
        
        @Override
        public void run() {
            try {
                int totalSubjects = 3;
                double average = (student.marks1 + student.marks2 + student.marks3) / totalSubjects;
                String result = (average >= 40) ? "PASS" : "FAIL";
                System.out.println("Student: " + student.name +  " | Avg: " + average + " | Result: " + result);
            } 
            catch (ArithmeticException e) {
                System.out.println("Error: Division by zero for student " + student.name);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Student> students = new ArrayList<>();

        try {
            System.out.print("Enter number of students: ");
            int n = sc.nextInt();

            for (int i = 0; i < n; i++) {
                System.out.println("\nEnter details for student " + (i + 1));

                System.out.print("ID: ");
                int id = sc.nextInt();

                System.out.print("Name: ");
                String name = sc.next();

                System.out.print("Marks 1: ");
                int m1 = sc.nextInt();

                System.out.print("Marks 2: ");
                int m2 = sc.nextInt();

                System.out.print("Marks 3: ");
                int m3 = sc.nextInt();

                students.add(new Student(id, name, m1, m2, m3));
            }
            // Create and start threads
            List<ResultTask> threads = new ArrayList<>();

            for (Student s : students) {
                ResultTask t = new ResultTask(s);
                threads.add(t);
                t.start();
            }
            // Wait for all threads to finish
            for (ResultTask t : threads) {
                try {
                    t.join();
                } 
                catch (InterruptedException e) {
                    System.out.println("Thread interrupted");
                }
            }
            System.out.println("\nAll results processed.");

        } 
        catch (InputMismatchException e) {
            System.out.println("Invalid input! Please enter correct data types.");
        }
        sc.close();
    }
}