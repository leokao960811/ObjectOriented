import foo.X;
import bar.Y;
import bar.Z;


public class Test {


    public static void main(String[] args) {
        X a = new X();
        Y b = new Y();
        Z c = new Z();

        c.processA(a);
        c.processB(b);
        b.processA(a);
        a.processA();
    }


}