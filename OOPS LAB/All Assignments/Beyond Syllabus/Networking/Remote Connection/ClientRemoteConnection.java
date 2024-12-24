import java.util.*;
import java.io.*;
import java.lang.*;
import java.net.*;

public class ClientRemoteConnection
{
	public static void main(String args[]) throws Exception
	{
		System.out.println("Client Started\n");
		Socket s=new Socket("127.0.0.1",3333); // Any valid IP Address
		DataInputStream dis=new DataInputStream(s.getInputStream());
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s1="",s2="";
		while(true)
		{
			System.out.println("Client input : ");
			s1=br.readLine();
			if(s1.equals("exit")) break;
			dout.writeUTF(s1);
			dout.flush();
			s2=dis.readUTF();
			System.out.println("Server Says : "+s2);
		}
		dout.close();
		dis.close();
		s.close();
	}
}
