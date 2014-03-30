package shapes;

import java.util.Random;
import java.util.ArrayList;

public class Sphere extends Shape3D
{
	public Sphere()
	{
		property.add("smooth");
		property.add("round");
		property.add("empty");
	}
	
	@Override
	public String[] getProperties()
    	{
		ArrayList<String> temp = new ArrayList<String>();

		Random rand = new Random();
       		
		int i = rand.nextInt(10);				
		if(i > 7)
			temp.add(property.get(0));

		i = rand.nextInt(10);
		if(i > 5)		
			temp.add(property.get(1));
		
		i = rand.nextInt(10);
		if(i > 3)		
			temp.add(property.get(2));

		if(temp.size() == 0){
			i = rand.nextInt(3);
			temp.add(property.get(i));
		}
		
		
		String[] output = new String[temp.size()];
		temp.toArray(output);
		return output;
	}
}

