import java.net.*;
import java.io.*;
import java.util.*;

public class Client{
  public static void main(String[] args) throws IOException {
    
    Socket socket = null;
    Scanner scanner = new Scanner(System.in);
    
    try{
      socket = new Socket(InetAddress.getLocalHost(), 8030);
      PrintStream ps = new PrintStream(socket.getOutputStream());
      BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
      
      String msg = "";
  
      while( !msg.equals("exit"))
      {
	msg = br.readLine(); 
	System.out.println("> " + msg);
	System.out.print("< ");
	
	msg = scanner.nextLine();
	ps.println(msg);
	ps.flush();
      }
      ps.close();
      } catch (IOException e) {
	System.out.println("Error: " + e);
      } finally {
	  if(socket != null)
	    socket.close();
	}
  }
}
 
