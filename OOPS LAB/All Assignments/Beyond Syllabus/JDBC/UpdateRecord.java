import java.util.*;
import java.io.*;
import java.lang.*;
import java.sql.*;

public class UpdateRecord
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
			Class.forName("com.mysql.cj.jdbc.Driver");
			conn=DriverManager.getConnection(url,username,password);
			System.out.println("Database Connected");
			stmt=conn.createStatement();
			stmt.execute("update javacourse set Name='Arka' where Name='Arkapratim'");
			rs=stmt.executeQuery("desc javacourse");
			System.out.println(rs);
		}
	
		catch(SQLException e)
		{
			System.out.println("SQL Error : "+e.getMessage());
			System.out.println("SQL State : "+e.getSQLState());
			System.out.println("vendor error : "+e.getErrorCode());
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		finally
		{
			if(conn !=null)
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
