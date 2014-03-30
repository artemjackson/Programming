import shapes.*;
import materials.*;

import java.util.Scanner;

public class GuessTheBody {
	public static void main(String args[])
	{
	        Material material = new Material();
	        Shape shape=new Shape();

	        Body body = new Body();
	        body.setRandomMaterial();
	        body.setRandomShape();
		//System.out.println(body.getMaterial());
		//System.out.println(body.getShape());
		rules();
	        play(body);
	}

	private static void rules(){
		System.out.println("RULES:");
		System.out.println("If you want to ask properties - press 'a' and enter a nuber of a question");
		System.out.println("If you want to write your answer - press 'w' and enter the material and shape (e.g. Ice Cube)");
		System.out.println("Guess the body with few steps!");
	}

	private static void play(Body body) {
        	int counter = 0;
		String[]  allPossibleProperties = {"brilliant",  "primitive", "heavy", "rough", "light", "round", "empty",  "angular", "smooth", "expensive",  "volumetric"};
        	
		Scanner scanner = new Scanner(System.in);
        	
        	String[] materialProperties = body.getMaterialProperties();
        	String[] shapeProperties = body.getShapeProperties();
		String[] allBodyProperties = new String[materialProperties.length + shapeProperties.length];
		
		for(int i = 0; i < materialProperties.length; ++i)
		{
			allBodyProperties[i] = materialProperties[i];
		}
		for(int i = 0; i < shapeProperties.length; ++i)
		{
			allBodyProperties[materialProperties.length + i] = shapeProperties[i];
		}		

		String answ = "";
		boolean win = false;
		
		while( !win ){
			answ = scanner.nextLine();
			if( answ.equals("a") ){
        			while( isNumber(answ) || answ.equals("a") )
        			{
          				System.out.println("You can ask: ");
          				for(int i = 0; i < allPossibleProperties.length; ++i)
           				System.out.println(i+1 + ". Is it " + allPossibleProperties[i] + "?");

					answ = scanner.nextLine();
					
					if( isNumber(answ) ){
						int checker = 0;
           	 				for(int i = 0; i < allBodyProperties.length; ++i){
           	 					if( allBodyProperties[i].equals( allPossibleProperties[ Integer.parseInt(answ) - 1 ] ) ){
								System.out.println("May be yes..."); 
								checker++;
							}
	 
						
						}

						if(checker == 0)
							System.out.println("I think no..");
            				
						++counter;
					}
 	      			}
			}
			
			if( answ.equals("w") ){
				System.out.println("Enter materual:");
				String word1 = scanner.nextLine();
				System.out.println("Enter shape:");
				String word2 = scanner.nextLine();
					
				if( word1.equals( body.getMaterial() ) || word2.equals( body.getShape() ) ){
					if( word1.equals( body.getMaterial() ) && word2.equals( body.getShape() ) ){
						win = true;
						System.out.println("You are abslolutly right!");
					} else System.out.println("So close..");						
				}else System.out.println("None");	
			}
		}
		
		if(win)
			System.out.println("Congratulations! You won with " + counter + " hints!");
	}

	private static boolean isNumber(String word){
		for(int i = 0; i < word.length(); ++i)		
			if( !Character.isDigit( word.charAt(i) ) )
				return false;
		return true;	
	}
}
