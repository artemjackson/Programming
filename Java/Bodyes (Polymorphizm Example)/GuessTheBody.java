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
		String[]  allPossibleProperties = {"brilliant", "heavy", "rough", "light", "angular", "smooth", "round"};
        	
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
		
		String word = "";
		boolean win = false;
		
		while( !win ){
			word = scanner.nextLine();
			if( word.equals("a") ){
        			while( isNumber(word) || word.equals("a") )
        			{

          				System.out.println("You can ask: ");
          				for(int i = 0; i < allPossibleProperties.length; ++i)
           				System.out.println(i+1 + ". Is it " + allPossibleProperties[i] + "?");

					word = scanner.nextLine();
					
					if( isNumber(word) ){
						int checker = 0;
           	 				for(int i = 0; i < allBodyProperties.length; ++i){
           	 					if( allBodyProperties[i].equals( allPossibleProperties[ Integer.parseInt(word) - 1 ] ) ){
								System.out.println("It has this property!"); 
								checker++;
							}
	 
						
						}

						if(checker == 0)
							System.out.println("It hasn't this property!");
            				
						++counter;
					}
 	      			}
			}
			
			if( word.equals("w") ){ 
				System.out.println("Enter materual:");
				word = scanner.nextLine();

				if( word.equals( body.getMaterial() ) ){
					System.out.println("Enter shape:");	
					word = scanner.nextLine();
					if( word.equals( body.getShape() ) ){
						win = true;
						System.out.println("You are abslolutly right!");
					}
				}else System.out.println("So close..");
				
			}
		}
		
		System.out.println("Congratulations! You won with " + counter + " hints!");
	}

	private static boolean isNumber(String word){
		for(int i = 0; i < word.length(); ++i)		
			if( !Character.isDigit( word.charAt(i) ) )
				return false;
		return true;	
	}
}
