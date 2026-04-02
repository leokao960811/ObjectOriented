import java.util.LinkedList;
import java.util.List;

public class DuckSimulator {

    public static void processDucks(List<Duck> ducks) {
		for (Duck d : ducks) {
            System.out.println("----------------------------------------");
            System.out.println("Name: " + d.getClass().getName());
            d.display();
            d.performQuack();
            d.performFly();
            d.swim();
        }
    }

    public static void main(String[] args) {

        List<Duck> ducks  = new LinkedList<Duck>();

        Duck model = new ModelDuck();

        ducks.add(new DecoyDuck());
        ducks.add(new MallardDuck());
        ducks.add(new RedHeadDuck());
        ducks.add(new RubberDuck());
        ducks.add(model);

        processDucks(ducks);

        // change the Model Duck's behavior dynamically
        model.setFlyBehavior(new FlyRocketPowered());
        model.setQuackBehavior(new Squeak());

        processDucks(ducks);
    }
}