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
        System.out.println("Material properties: " + this.material.property);
        System.out.println("Shape properties: " + this.shape.property);
    }

    private Material material;
    private Shape shape;
}
