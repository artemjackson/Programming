import materials.*;
import shapes.*;

public class Body{
	public void setMaterial(Material newMaterial){	
		material = newMaterial;	
	}
	public void setShape(Shape newShape){
		shape = newShape;	
	}

	private Material material;
	private Shape shape;
}
