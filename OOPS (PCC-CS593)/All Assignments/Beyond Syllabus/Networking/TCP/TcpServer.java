// TCP server

import java.util.*;
import java.io.*;
import java.lang.*;
import java.net.*;

public class TcpServer
{
	public static void main(String args[]) throws Exception{
		
		ServerSocket ss=new ServerSocket(6666);
		Socket s=ss.accept();
		DataInputStream dis=new DataInputStream(s.getInputStream());
		String str=(String)dis.readUTF();
		System.out.println("Client : "+str);
		ss.close();
			
	}
}