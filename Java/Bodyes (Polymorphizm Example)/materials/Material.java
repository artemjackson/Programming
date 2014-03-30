package materials;

import java.util.ArrayList;

public class Material{
	public Material(){
		property = new ArrayList<String>();
	}	
	
	public void addProperty(String newProperty){
		property.add(newProperty);
	}
	
	public void deleteProperty(String deletingProperty){
		int possition = getPropertyPossition(deletingProperty);
	
		if(possition != -1 )		
			property.remove(possition);
	}

	public boolean hasProperty(String desiredProperty){
		return property.contains(desiredProperty);
	}

	private int getPropertyPossition(String desiredProperty){
		return property.indexOf(desiredProperty);
	}
	
	public String[] getProperties()
    	{
		String[] output = new String[property.size()];
		property.toArray(output);
		return output;
	}

	protected ArrayList<String> property; 
}


