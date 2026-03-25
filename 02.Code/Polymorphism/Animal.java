public abstract class Animal {


    public void sleep() {
        System.out.println(name() + ": ZZZ!");
    }


    public abstract void makeNoise();
    public abstract String name();
    public abstract void roam();


}