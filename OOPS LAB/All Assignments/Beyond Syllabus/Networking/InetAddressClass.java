// InetAddressClass

import java.io.*;
import java.net.*;

public class InetAddressClass{
	public static void main(String args[])
	{
		try
		{
			InetAddress ip=InetAddress.getByName("www.nptel.ac.in");
			System.out.println("Host : "+ip.getHostName());
			System.out.println("IP address : "+ip.getHostAddress());
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}