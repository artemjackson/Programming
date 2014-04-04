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
		
		else	
			System.out.println("Error. No arguments are inputеed\n");
	}

	private static boolean check(String str){
		Pattern p = Pattern.compile("[А-Яа-я]{1,}");  
        	Matcher m = p.matcher(str);  
        	return m.matches(); 
	}

	private static Double countVowelsProportion(String str){
		int vowels = 0;
		
		for(int i = 0; i < str.length(); ++i)
			if( isVowel(str.charAt(i)))
				++vowels;
		
		Double proportion = (double)vowels/(double)str.length();
		return proportion;
	}

	private static boolean isVowel(char ch){
		switch (ch){
			case 'а': return true;
			case 'у': return true;
			case 'о': return true;
			case 'ы': return true;
			case 'и': return true;
			case 'э': return true;
			case 'я': return true;
			case 'ю': return true;
			case 'ё': return true;
			case 'е': return true;		
		}
		return false;
	}

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
	}
}
