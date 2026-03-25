import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;
import java.util.LinkedList;


public class testAnimals {


    public static void moveAbout(List zoo) {
        System.out.println("===========================================");
        for (int i = 0; i < zoo.size(); i++) {
            Animal a = (Animal)zoo.get(i);
            a.roam();
        }
    }


    public static void soundOff(List zoo) {
        for (int i = 0; i < zoo.size(); i++) {
            Animal a = (Animal)zoo.get(i);
            a.makeNoise();
        }
    }


    public static void goToSleep(List zoo) {
        for (int i = 0; i < zoo.size(); i++) {
            Animal a = (Animal)zoo.get(i);
            a.sleep();
        }
        System.out.println("===========================================");
    }


    public static void main(String[] args) throws Exception {
        while (true) {

            List<Animal> animals = new LinkedList<Animal>();

            // open input file
            BufferedReader r = new BufferedReader(new FileReader("animals.txt"));

            // read first line
            String line = r.readLine();

            // loop over all input lines
            while (line != null) {
                Class theClass = Class.forName(line);
                Animal a = (Animal)theClass.newInstance();
                animals.add(a);
                // read next input line
                line = r.readLine();
            }

            moveAbout(animals);
            soundOff(animals);
            goToSleep(animals);

            System.out.println();
            System.out.println();

            Thread.sleep(3000);

        }
    }


}