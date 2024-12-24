// URLConnectionClass

import java.io.*;
import java.net.*;

public class URLConnectionClass
{
	public static void main(String args[])
	{
		try
		{
			URL url=new URL("https://nptel.ac.in/course.php");
			URLConnection urlcon=url.openConnection();
			InputStream str=urlcon.getInputStream();
			int i;
			while((i=str.read())!=-1)
			{
				System.out.println((char)i);
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}