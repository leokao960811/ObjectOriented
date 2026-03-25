import java.util.List;
import java.util.LinkedList;


public class GroceryList {


    private List<String> items;


    public GroceryList() {
        items = new LinkedList<String>();
    }


    public void addItem(String item) {
        items.add(item);
    }


    public void removeItem(String item) {
        items.remove(item);
    }


    public String toString() {
        String result = "Grocery List\n------------\n\n";
        int index = 1;
		for (String item: items) {
            result += String.format("%3d. %s", index++, item) + "\n";
        }
        return result;
    }


}