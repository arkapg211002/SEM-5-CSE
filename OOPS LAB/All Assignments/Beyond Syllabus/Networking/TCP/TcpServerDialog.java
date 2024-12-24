// TCP server

import java.util.*;
import java.io.*;
import java.lang.*;
import java.net.*;

public class TcpServerDialog
{
	public static void main(String args[]) throws Exception
	{
		System.out.println("Server Started\n");
		ServerSocket ss=new ServerSocket(6666);
		Socket s=ss.accept();
		DataInputStream dis=new DataInputStream(s.getInputStream());
		
		while(true)
		{
			String str=(String)dis.readUTF();
			if(str.equals("exit")==true)
			{
				System.out.println("Exiting ...");
				ss.close();
				break;
			}
			System.out.println("Client : "+str);
		}
	}
}