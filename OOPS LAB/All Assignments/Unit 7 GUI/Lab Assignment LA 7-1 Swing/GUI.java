/*

Input admission count for CSE
Input admission count for CSBS

check for valid input
input should be positive integer

Display the total admission count

After correct display input fields cannot be changed

*/

import java.util.*;
import java.io.*;
import java.lang.*;
import javax.swing.*;
import java.awt.event.*;

public class GUI implements ActionListener
{
	JFrame f;
	JTextField t1,t2;
	JLabel l1,l2,res;
	JButton b;
	
	GUI()
	{
		f=new JFrame("GUI");
				
		l1=new JLabel("Enter admission count for CSE");
		l1.setBounds(50,50,300,20);
		f.add(l1);
		
		t1=new JTextField();
		t1.setBounds(50,90,200,20);
		f.add(t1);
		
		l2=new JLabel("Enter admission count for CSBS");
		l2.setBounds(50,150,300,20);
		f.add(l2);
		
		t2=new JTextField();
		t2.setBounds(50,180,200,20);
		f.add(t2);
		
		b=new JButton("Submit");
		b.setBounds(50,220,95,30);
		f.add(b);
		b.addActionListener(this);
		
		res=new JLabel("Result : ");
		res.setBounds(50,270,300,20);
		f.add(res);
		
		// should always be at the end
		f.setLayout(null);
		f.setSize(500,500);
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getActionCommand().equals("Submit"))
		{
			displayResult(t1.getText(),t2.getText());
		}
	}
	
	public void displayResult(String a,String b)
	{
		int n1,n2;
		if(a.isEmpty() || b.isEmpty())
		{
			res.setText("Result : Input Field empty");
		}
		else
		{
			try
			{
				n1=Integer.parseInt(a);
				n2=Integer.parseInt(b);
				if(n1<=0 || n2<=0)
				{
					res.setText("Result : Value cannot be less than 1");
				}
				else
				{
					int sum=n1+n2;
					String r=Integer.toString(sum);
					res.setText("Result : "+r);
					t1.setEditable(false);
					t2.setEditable(false);
				}
				
			}
			catch(Exception e)
			{
				res.setText("Result : Invalid input");
			}
		}
	}
	
	public static void main(String args[]) throws Exception
	{
		new GUI();
	}
}
