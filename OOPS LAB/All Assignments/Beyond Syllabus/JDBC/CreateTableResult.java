import java.util.*;
import java.io.*;
import java.lang.*;
import java.sql.*;

public class CreateTableResult
{
	public static void main(String args[])
	{
		Connection conn=null;
		Statement stmt=null;
		ResultSet rs=null;
		//int totalmarks=0,numstudent=0;
		//float avg=0.0f;
		//String name,roll,marks,grade;
		String tablename="";
		try{
			String username="root";
			String password="";
			String url="jdbc:mysql://localhost:3306/test";
			Class.forName("com.mysql.cj.jdbc.Driver");
			conn=DriverManager.getConnection(url,username,password);
			System.out.println("Database connected");
			stmt=conn.createStatement();
			stmt.execute("show tables");
			rs=stmt.getResultSet();
			System.out.println("\n\n------------ Result -----------\n");
			//int rows=0;
			while(rs.next())
			{
				tablename=rs.getString("Tables_in_test");
				System.out.println(tablename);
			}
			
			stmt.execute("create table class(Roll Integer, Name Varchar(100))");
			stmt.execute("show tables");
			rs=stmt.getResultSet();
			System.out.println("\n\n------------ Result -----------\n");
			//int rows=0;
			while(rs.next())
			{
				tablename=rs.getString("Tables_in_test");
				System.out.println(tablename);
			}
		}
		catch(SQLException e)
		{
			System.out.println("SQL Error : "+e.getMessage());
			System.out.println("SQL State : "+e.getSQLState());
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
				try{
					conn.close();
					System.out.println("Database terminated");
				}
				catch(Exception e){}
			}
		}
	}
}