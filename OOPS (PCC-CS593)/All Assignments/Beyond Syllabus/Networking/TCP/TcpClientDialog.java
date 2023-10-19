// TCP Client

import java.util.*;
import java.io.*;
import java.lang.*;
import java.net.*;

public class TcpClientDialog
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc=new Scanner(System.in);
		Socket s=new Socket("localhost",6666);
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());
		System.out.println("Client Started\n");
		while(true)
		{
			System.out.print("Enter text : ");
			String str=sc.nextLine();
			dout.writeUTF(str);
			dout.flush();
			if(str.equals("exit")==true)
			{
				dout.close();
				s.close();
				break;
			}
		}
	}
}