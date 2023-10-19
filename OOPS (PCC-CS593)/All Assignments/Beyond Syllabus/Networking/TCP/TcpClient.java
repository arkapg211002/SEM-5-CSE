// TCP Client

import java.util.*;
import java.io.*;
import java.lang.*;
import java.net.*;

public class TcpClient
{
	public static void main(String args[]) throws Exception
	{
		Socket s=new Socket("localhost",6666);
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());
		dout.writeUTF("Hello Sever");
		dout.flush();
		dout.close();
		s.close();
	}
}