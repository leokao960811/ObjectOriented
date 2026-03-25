public class PhDStudent extends Student {


    public PhDStudent(String name) {
        super(name);
    }


    public void saySomething() {
        super.saySomething();
        System.out.println("Will this help me graduate?\"");
    }


}