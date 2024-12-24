// Sender Program

import java.io.*;
import java.net.*;

public class Sender{
	public static void main(String args[]) throws Exception
	{
		DatagramSocket ds=new DatagramSocket();
		String st="Hello world !!";
		InetAddress ip=InetAddress.getByName("127.0.0.1");
		DatagramPacket dp=new DatagramPacket(st.getBytes(),st.length(),ip,3000);
		ds.send(dp);
		ds.close();
	}
}