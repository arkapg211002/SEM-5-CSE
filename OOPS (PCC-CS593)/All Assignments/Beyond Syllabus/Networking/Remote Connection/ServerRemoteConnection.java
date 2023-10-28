import java.io.*;
import java.lang.*;
import java.util.*;
import java.net.*;

public class ServerRemoteConnection
{
	public static void main(String args[]) throws Exception
	{
		System.out.println("Server Started\n");
		ServerSocket ss=new ServerSocket(3333,2,InetAddress.getByName("127.0.0.1")); // Any valid IP address
		Socket s=ss.accept();
		DataInputStream dis=new DataInputStream(s.getInputStream());
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s1="",s2="";
		while(true)
		{
			s1=dis.readUTF();
			if(s1.equals("exit")) break;
			System.out.println("Client : "+s1);
			System.out.println("What will server send ? : ");
			s2=br.readLine();
			dout.writeUTF(s2);
			dout.flush();
		}
		dis.close();
		dout.close();
		s.close();
		ss.close();
	}
}
