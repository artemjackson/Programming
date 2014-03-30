import shapes.*;
import materials.*;

import java.util.Random;

public class Body{
	
	public void setMaterial(Material newMaterial){
	        material = newMaterial;
	}
	
	public void setShape(Shape newShape){
	        shape = newShape;
	}

	public void setRandomMaterial(){
	        Random rand = new Random();
       		int i = rand.nextInt(3);

        	switch(i){
        	    	case 0:
        	        	material = new Metall(); break;
        	    	case 1:
        	        	material = new Wood(); break;
			case 2:
        	        	material = new Gold(); break;
        	}
    	}
	
	public void setRandomShape(){
	        Random rand = new Random();
       		int i = rand.nextInt(3);

        	switch(i){
        	    	case 0:
        	        	shape = new Sphere(); break;
        	    	case 1:
        	        	shape = new Triangle(); break;
			case 2:
   	     	        	shape = new Tetraider(); break;
        	}
	}
	public String getMaterial(){
		return material.getClass().getSimpleName();	
	}

	public String getShape(){
		return shape.getClass().getSimpleName();
	}

	public	String[] getMaterialProperties(){
		return material.getProperties();	
	}

	public String[] getShapeProperties(){
		return shape.getProperties();	
	}
	

    	private Material material;
    	private Shape shape;
}
