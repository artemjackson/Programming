/**
 * Created by jackson on 26.04.14.
 */

import java.net.*;

public class Address {
    public static void main(String[] args)
    {
        InetAddress myIP = null;
        InetAddress bsuIP = null;

        try {
            myIP = InetAddress.getLocalHost();
            System.out.println("Мой IP-адрес: " + myIP.getHostAddress());
            bsuIP = InetAddress.getByName("www.bsu.by");
            System.out.println("IP-адреc BSU: " + bsuIP.getHostAddress());
        } catch(UnknownHostException e)
        {
            e.printStackTrace();
        }
        
        byte[] ip = {(byte)8,(byte)8,(byte)8,(byte)8};
    }
}
