// UDP Receiver

import java.io.*;
import java.net.*;
import java.util.*;
import java.lang.*;

public class UdpClient
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc=new Scanner(System.in);
		DatagramSocket ds=new DatagramSocket();
		InetAddress ip=InetAddress.getLocalHost();
		byte buffer[]=null;
		System.out.println("Client Started\n");
		while(true)
		{
			System.out.print("Enter text : ");
			String input=sc.nextLine();
			buffer=input.getBytes();
			DatagramPacket dp=new DatagramPacket(buffer,buffer.length,ip,1234);
			ds.send(dp);
			if(input.equals("exit"))
			{
				break;
			}
		}
	}
}