import shapes.*;
import materials.*;
import java.util.Scanner;

public class GuessTheBody {

    public static void main(String args[])
    {
        Material material = new Material();
        Shape shape=new Shape();

        Body body = new Body();
        body.setMaterial(material.getRandomParameter());
        body.setShape(shape.getRandomShape());

        body.printAllProperties();
        body.play();


    }
}
