import java.util.Scanner;
import java.util.ArrayList;


public class MinMaxAvg {
	public static void main(String[] args){
		if(args.length != 0){
			ArrayList<Stat> operations = new ArrayList<Stat>();

			for(String arg: args)
			{
				switch(arg){
					case "Min": operations.add( new Min() ); break;
					case "Max": operations.add( new Max() ); break;
					case "Avg": operations.add( new Avg() ); break;
				}			
			}

			Scanner in = new Scanner(System.in);
		     	String s = in.next();
			
			
			while(!s.equals("!"))
			{
				for(Stat e: operations)
				{
					e.accomulate( Double.parseDouble(s) );
				}								
				s = in.next();
			}
			in.close();

			for(Stat e: operations)
			{
				e.postProcess( );
			}

			for(Stat e: operations)
			{
				System.out.println( e.result( ) );
			}
		}
		else System.out.println("Input some value..");
	} 
}

interface Stat{
	public void accomulate(double x);
 	public void postProcess();
	public double result();
}

class Min implements Stat{
	private double min;

	Min(){ min = Double.MAX_VALUE; };
	public void accomulate(double x){ min =  ( min > x ) ? x : min; };
	public void postProcess(){};
	public double result(){ return min; };
}

class Max implements Stat{
	private double max;
	
	Max(){ max = Double.MIN_VALUE; };	
	public void accomulate(double x){ max =  ( max < x ) ? x : max; };
	public void postProcess(){};
	public double result(){ return max; };
}

class Avg implements Stat{
	private double sum;
	private double number;
	private ArrayList<Double> container = new ArrayList<Double>();
	
	Avg(){ sum = 0; number = 0;};
	public void accomulate(double x){
		container.add(x); 
		number++;
	 };
	public void postProcess(){
		for(Double e: container)
			sum += e;
	};
	public double result(){ return sum/number; };
}
