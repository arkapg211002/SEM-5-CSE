import java.util.*;
import java.io.*;
import java.lang.*;
import java.sql.*;

public class SelectRecord
{
	public static void main(String args[])
	{
		Connection conn=null;
		Statement stmt=null;
		ResultSet rs=null;
		int totalmarks=0,numstudent=0;
		float avg=0.0f;
		String name,roll,marks,grade;
		try{
			String username="root";
			String password="";
			String url="jdbc:mysql://localhost:3306/test";
			Class.forName("com.mysql.cj.jdbc.Driver");
			conn=DriverManager.getConnection(url,username,password);
			System.out.println("Database connected");
			stmt=conn.createStatement();
			stmt.execute("select * from javacourse");
			rs=stmt.getResultSet();
			System.out.println("\n\n------------ Result -----------\n");
			int rows=0;
			while(rs.next())
			{
				name=rs.getString("Name");
				roll=rs.getString("Roll");
				marks=rs.getString("Marks");
				grade=rs.getString("Grade");
				totalmarks+=Integer.parseInt(marks);
				rows+=1;
				System.out.println(name+" "+roll+" "+marks+" "+grade);
			}
			
			//rs.last();
			System.out.println("Total Marks : "+totalmarks);
			//numstudent=rs.getRow();
			avg=(float)totalmarks/(float)rows;
			System.out.println("Average MArks : "+avg);
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