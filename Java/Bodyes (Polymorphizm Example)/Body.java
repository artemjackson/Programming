import shapes.*;
import materials.*;

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

    	private Material material;
    	private Shape shape;
}
