import java.io.*;
import java.util.*;
import java.lang.*;
import java.sql.*;

public class CreateTable
{
	public static void  main(String args[])
	{
		Connection conn=null;
		Statement stmt=null;
		ResultSet rs=null;
		try
		{
			String username="root";
			String password="";
			String url="jdbc:mysql://localhost:3306/test";
			Class.forName("com.mysql.cj.jdbc.Driver").newInstance();
			conn=DriverManager.getConnection(url,username,password);
			stmt=conn.createStatement();
			stmt.execute("create table javacourse(Roll Integer primary key, Name Varchar(30), Marks Integer not null, Grade Varchar(2))");
			
		}
		catch(SQLException e)
		{
			System.out.println("SQL Exception : "+e.getMessage());
			System.out.println("SQL State : "+e.getSQLState());
			System.out.println("Vendor Error : "+e.getErrorCode());
					
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		finally
		{
			if(conn != null)
			{
				try{
					conn.close();
					System.out.println("Database terminated");
				}
				catch(Exception e){}
			}
		}
	}
}