import java.util.*;
import java.io.*;
import java.lang.*;
import java.sql.*;

public class Connect {
	public static void main(String args[])
	{
		Connection conn=null;
		try
		{
			String username="root";
			String password="";
			String url="jdbc:mysql://localhost:3306/test";
			Class.forName("com.mysql.cj.jdbc.Driver").newInstance();
			conn=DriverManager.getConnection(url,username,password);
			System.out.println("Database Connected");
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		finally
		{
			if(conn!=null)
			{
				try
				{
					conn.close();
					System.out.println("Database terminated");
				}
				catch(Exception e)
				{}
			}
		}
	}
}

/*

Compile

javac -cp mysql.jar;.Connect1.java
java -cp mysql.jar;. Connect1

*/