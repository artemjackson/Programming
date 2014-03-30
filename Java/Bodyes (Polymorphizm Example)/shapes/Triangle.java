package shapes;

import java.util.Random;
import java.util.ArrayList;

public class Triangle extends Shape2D
{
	public Triangle()
	{
		property.add("angular");
		property.add("primitive");
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
		if(i > 3)		
			temp.add(property.get(1));

		if(temp.size() == 0){
			i = rand.nextInt(2);
			temp.add(property.get(i));
		}

		String[] output = new String[temp.size()];
		temp.toArray(output);
		return output;
	}
	
}
