import java.util.*;
import java.io.*;
import java.lang.*;
import java.sql.*;

public class InsertRecord
{
	public static void main(String args[])
	{
		Connection conn=null;
		Statement stmt=null;
		ResultSet rs=null;
		try{
			String username="root";
			String password="";
			String url="jdbc:mysql://localhost:3306/test";
			Class.forName("com.mysql.cj.jdbc.Driver").newInstance();
			conn=DriverManager.getConnection(url,username,password);
			System.out.println("Database Connected");
			stmt=conn.createStatement();
			stmt.execute("insert into javacourse values(04,'Jadu',88,'O')");
			stmt.execute("insert into javacourse values(05,'Madhu',79,'E')");
			stmt.execute("insert into javacourse values(03,'Shyam',80,'A')");
			
		}
		catch(SQLException e)
		{
			System.out.println("SQL Exception : "+e.getMessage());
			System.out.println("SQL state : "+e.getSQLState());
			System.out.println("Vendor error : "+e.getErrorCode());
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		finally
		{
			if(conn != null)
			{
				try 
				{
					conn.close();
					System.out.println("Database terminated");
				}
				catch(Exception e){}
			}
		}
	}
}