package bar;


import foo.X;


public class Y extends X {


    public Y() {
        m = 4;
        n = 5;
        // o = 6;
    }


    public String calc1() {
        return "M - N = " + (m - n);
    }


    protected String calc2() {
        // System.out.println("M - O = " + (m - o));
        return "M * N = " + (m * n);
    }


    private String calc3() {
        // System.out.println("N - O = " + (n - o));
        return "N / M = " + (n / m);
    }


    public void processA(X a) {
        System.out.println("B: A.m = " + a.m);
        System.out.println("B: A.n direct = " + super.n);
        //System.out.println("B: A.n = " + a.n);
        //System.out.println("B: A.o = " + a.o);
        System.out.println("B: calling A.calc1(): " + a.calc1());
        System.out.println("B: calling A.calc2() direct: " + super.calc2());
        //System.out.println("B: calling A.calc2(): " + a.calc2());
        //System.out.println("B: calling A.calc3(): " + a.calc3());
    }


}