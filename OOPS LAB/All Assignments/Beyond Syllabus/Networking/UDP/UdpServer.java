// UDP Server

import java.io.*;
import java.net.*;
import java.util.*;
import java.lang.*;

public class UdpServer
{
	public static void main(String args[]) throws Exception
	{
		DatagramSocket socket=new DatagramSocket(1234);
		byte receive[]=new byte[1024];
		DatagramPacket dp=null;
		System.out.println("Server started\n");
		while(true)
		{
			dp=new DatagramPacket(receive,receive.length);
			socket.receive(dp);
			System.out.println("Client : "+data(receive));
			if(data(receive).toString().equals("exit"))
			{
				System.out.println("Exiting ...");
				break;
			}
			receive=new byte[1024];
		}
	}
	
	public static StringBuilder data(byte a[])
	{
		if(a==null) return null;
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<a.length && a[i]!=0;i++)
		{
			sb.append((char)a[i]);
		}
		return sb;
	}
	
}