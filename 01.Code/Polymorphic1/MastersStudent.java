public class MastersStudent extends Student {


    public MastersStudent(String name) {
        super(name);
    }


    public void saySomething() {
        super.saySomething();
        System.out.println("Will this help me at work?\"");
    }


}