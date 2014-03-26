import materials.*;
import shapes.*;

public class GuessTheBody{
	public static void main(String args[]){
		Material metall = new Metall();
		metall.addProperty("expensive");

		Body body = new Body();
		body.setMaterial(metall);
	}
}
