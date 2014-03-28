import shapes.*;
import materials.*;
<<<<<<< HEAD
=======
import java.util.Scanner;
>>>>>>> b196d9c921a008beac46910e0c7826bb991d6754

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
