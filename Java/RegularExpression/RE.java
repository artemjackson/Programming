import java.util.Map;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

import java.util.TreeMap;
import java.util.Comparator;

import java.util.regex.Matcher;  
import java.util.regex.Pattern; 

public class RE {
	public static void main(String args[]){
		if(args.length > 0){
			TreeMap<String, Double> map = null;

			for(int i = 0; i < args.length; ++i){
				if( check(args[i]) ){
					if(map == null)
						map = new TreeMap<String, Double>();
				
					Double proportion = countVowelsProportion(args[i]);
					map.put(args[i], proportion);			
				}				
			}
			System.out.print("Words in order of portion of vowels in it:\n");
			print(map);
		}
		else	
			System.out.println("Error. No arguments are inputеed\n");
	}
	
	/**
	 *	Checking if there are only russian vawels in word
	 */
	private static boolean check(String str){
		Pattern p = Pattern.compile("[А-Яа-я]{1,}");  
        	Matcher m = p.matcher(str);  
        	return m.matches(); 
	}
	
	/**
	 *	Counting portion of vawels in whole word 
	 */
	private static Double countVowelsProportion(String str){
		int vowels = 0;
		
		for(int i = 0; i < str.length(); ++i)
			if( isVowel( Character.toString(str.charAt(i)) ))
				++vowels;
		
		Double proportion = (double)vowels/(double)str.length();
		return proportion;
	}
	
	/**
	 *	Checking if this letter is russian vowel
	 */
	private static boolean isVowel(String s){
		Pattern p = Pattern.compile("[аеёиоуыэюяAЕЁИОУЫЭЮЯ]");  
        	Matcher m = p.matcher(s);  
        	return m.matches(); 
	}
	
	/**
	 *	Outputing to console words in order of increasing of vowels portion in word
	 */
	private static void print(Map map){
		List<Map.Entry> list = new ArrayList<Map.Entry>(map.entrySet());
		Collections.sort(list, new Comparator() {
                	public int compare(Object o1, Object o2) {
                 		Map.Entry e1 = (Map.Entry) o1;
                 		Map.Entry e2 = (Map.Entry) o2;
                 		return ((Comparable) e1.getValue()).compareTo(e2.getValue());
             		}
         	});

		for (Map.Entry e : list)
        		System.out.println(e.getKey());
			/* If you want to check correctness of 
			 * this output please, uncomment follow line
			 * It will show you a word and it's vowel portion
			 */
			// System.out.println(e.getKey() + " " + e.getValue());
	}
}
