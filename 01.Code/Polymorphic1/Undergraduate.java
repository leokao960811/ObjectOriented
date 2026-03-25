public class Undergraduate extends Student {


    public Undergraduate(String name) {
        super(name);
    }


    public void saySomething() {
        super.saySomething();
        System.out.println("Is it Friday yet?\"");
    }


}