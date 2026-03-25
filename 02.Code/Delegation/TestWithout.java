import java.util.List;
import java.util.LinkedList;


public class TestWithout {


    public static void printList(List<String> items) {
        System.out.println("Grocery List");
        System.out.println("------------\n");
        int index = 1;
		for (String item : items) {
            System.out.println(String.format("%3d. %s", index++, item));
        }
        System.out.println();
    }


    public static void main(String[] args) {
        List<String> g = new LinkedList<String>();
        g.add("Granola");
        g.add("Milk");
        g.add("Eggs");
        printList(g);
        g.remove("Milk");
        printList(g);
    }


}