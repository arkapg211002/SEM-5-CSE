import java.io.*;
import java.util.*;
import java.lang.*;
import java.net.*;
import java.text.*;

public class ServerConcurrent
{
	public static void main(String args[]) throws IOException
	{
		ServerSocket ss=new ServerSocket(5056);
		while(true)
		{
			Socket s=null;
			try
			{
				s=ss.accept();
				System.out.println("A new Client is created : "+s);
				DataInputStream dis=new DataInputStream(s.getInputStream());
				DataOutputStream dout=new DataOutputStream(s.getOutputStream());
				System.out.println("Assigning new client thread...");
				Thread t=new ClientHandler(s,dis,dout);
				t.start();
			}
			catch(Exception e)
			{
				s.close();
				System.out.println(e);
			}
		}
	}
}

class ClientHandler extends Thread{
	DateFormat fordate = new SimpleDateFormat("yyyy/MM/dd");
	DateFormat fortime = new SimpleDateFormat("hh:mm:ss");
	final DataInputStream dis;
	final DataOutputStream dout;
	final Socket s;
	
	public ClientHandler(Socket s, DataInputStream dis,DataOutputStream dout)
	{
		this.s=s;
		this.dis=dis;
		this.dout=dout;
	}
	
	public void run()
	{
		String received;
		String toreturn;
		while(true)
		{
			try{
				dout.writeUTF("What do you want? [Date / time]..\n"+"Type exit to terminate");
				received=dis.readUTF();
				if(received.equals("exit"))
				{
					System.out.println("Client "+this.s+" sends exit..");
					System.out.println("Closing this connection");
					this.s.close();
					System.out.println("Connection closed");
					break;
				}
				
				Date date=new Date();
				switch(received)
				{
					case "Date":
						toreturn = fordate.format(date);
						dout.writeUTF(toreturn);
						break;
					case "Time":
						toreturn = fortime.format(date);
						dout.writeUTF(toreturn);
						break;
					default:
						dout.writeUTF("Invalid Input");
						break;
				}
			}
			catch(IOException e)
			{
				System.out.println(e);
			}
		}
		
		try{
			this.dis.close();
			this.dout.close();
		}
		catch(IOException e)
		{
			System.out.println(e);
		}
	}
}
