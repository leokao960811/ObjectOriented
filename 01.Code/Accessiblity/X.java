package foo;


public class X {


    public    int m;
    protected int n;
    private   int o;


    public X() {
        m = 1;
        n = 2;
        o = 3;
    }


    public String calc1() {
        return "M + N = " + (m + n);
    }


    protected String calc2() {
        return "M + O = " + (m + o);
    }


    private String calc3() {
        return "N + O = " + (n + o);
    }


    public void processA() {
        System.out.println("A: A.m = " + m);
        System.out.println("A: A.n = " + n);
        System.out.println("A: A.o = " + o);
        System.out.println("A: calling A.calc1(): " + calc1());
        System.out.println("A: calling A.calc2(): " + calc2());
        System.out.println("A: calling A.calc3(): " + calc3());
    }


}