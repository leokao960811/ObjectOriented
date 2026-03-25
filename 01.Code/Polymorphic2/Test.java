import java.util.LinkedList;
import java.util.List;


public class Test {


    public static void main(String[] args) {

        List<Student> students = new LinkedList<Student>();

        students.add(new Undergraduate("Bilbo Baggins"));
        students.add(new Undergraduate("Samwise Gamgee"));
        students.add(new MastersStudent("Aargorn"));
        students.add(new MastersStudent("Gimli"));
        students.add(new MastersStudent("Legolas"));
        students.add(new PhDStudent("Gandalf the White"));
        students.add(new PhDStudent("Sauron the Dark Lord"));
        // students.add(new DualMajor("Saruman the (Formerly) White"));

		for (Student s: students) {
            System.out.println("" + s);
        }

        System.out.println();

        Asker a = new Asker();
        a.ask(students);

    }


}