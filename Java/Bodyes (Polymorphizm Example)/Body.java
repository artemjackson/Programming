import shapes.*;
import materials.*;

import java.util.Scanner;

public class Body{
	public void setMaterial(Material newMaterial){
	        material = newMaterial;
	}
	
	public void setShape(Shape newShape){
	        shape = newShape;
	}

	public void printAllProperties() {
        	System.out.println("Material properties: ");
		String[] materialProperties = this.material.getProperties();
		for(Object o : materialProperties)
			System.out.println (o);
        	
		System.out.println("Shape properties: " );
		String[] shapeProperties = this.shape.getProperties();
		for(Object o : shapeProperties)
			System.out.println (o);
    }

    public int play() {
        int counter=0;
        Scanner scanner=new Scanner(System.in);
        String[]  allProperties = {"brilliant","heavy", "rough","light","angular","smooth","round"};

        String[] materialProperties = this.material.getProperties();
        String[] shapeProperties = this.shape.getProperties();

        while(counter<materialProperties.length+shapeProperties.length)
        {

            System.out.println("You can ask questions:");
            for(int i=0; i<allProperties.length; ++i)
                System.out.println(i+1 + ". " + allProperties[i]);

            String word = scanner.nextLine();

            for(int i=0; i<materialProperties.length; ++i){
                if (materialProperties[i].equals(word))
                    System.out.println("It has property: " + word);
            }

            for(int i=0; i<shapeProperties.length; ++i){
                if (shapeProperties[i].equals(word))
                    System.out.println("It has property: " + word);

            }
            ++counter;
        }

        return 0;
    }

    private Material material;
    private Shape shape;
}
