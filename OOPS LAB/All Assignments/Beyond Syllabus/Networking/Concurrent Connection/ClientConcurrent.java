import java.io.*;
import java.util.*;
import java.lang.*;
import java.net.*;

public class ClientConcurrent
{
	public static void main(String args[]) throws IOException
	{
		try
		{
			Scanner sc=new Scanner(System.in);
			InetAddress ip=InetAddress.getByName("localhost");
			Socket s=new Socket(ip,5056);
			DataInputStream dis=new DataInputStream(s.getInputStream());
			DataOutputStream dout = new DataOutputStream(s.getOutputStream());
			while(true)
			{
				System.out.println(dis.readUTF());
				String tosend = sc.nextLine();
				dout.writeUTF(tosend);
				if(tosend.equals("exit"))
				{
					System.out.println("Closing connection");
					break;
				}						
			}
			sc.close();
			dout.close();
			dis.close();
			s.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
