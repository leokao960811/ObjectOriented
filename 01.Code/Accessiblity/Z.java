package bar;


import foo.X;


public class Z {


    public Z() {
    }


    public void processA(X a) {
        System.out.println("C: A.m = " + a.m);
        //System.out.println("C: A.n = " + a.n);
        //System.out.println("C: A.o = " + a.o);
        System.out.println("C: calling A.calc1(): " + a.calc1());
        //System.out.println("C: calling A.calc2(): " + a.calc2());
        //System.out.println("C: calling A.calc3(): " + a.calc3());
    }


    public void processB(Y b) {
        System.out.println("C: B.m = " + b.m);
        //System.out.println("C: B.n = " + b.n);
        //System.out.println("C: B.o = " + b.o);
        System.out.println("C: calling B.calc1(): " + b.calc1());
        //System.out.println("C: calling B.calc2(): " + b.calc2());
        //System.out.println("C: calling B.calc3(): " + b.calc3());
    }


}