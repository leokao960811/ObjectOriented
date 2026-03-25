public class Test {


    public static void main(String[] args) {
        GroceryList g = new GroceryList();
        g.addItem("Granola");
        g.addItem("Milk");
        g.addItem("Eggs");
        System.out.println("" + g);
        g.removeItem("Milk");
        System.out.println("" + g);
    }


}