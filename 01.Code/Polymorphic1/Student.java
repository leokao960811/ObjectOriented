import java.util.List;
import java.util.LinkedList;


public class Student {


    private String name;


    public Student(String name) {
        this.name = name;
    }


    public void saySomething() {
        System.out.print(name + " says \"");
    }


    public String toString() {
        return String.format("%14s : %s", getClass().getName(), name);
    }


}