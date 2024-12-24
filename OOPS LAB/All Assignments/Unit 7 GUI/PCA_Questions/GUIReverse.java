/*

Write a Java program GUIReverse.java to develop a simple java application for capturing a whole number and display
its reverse value. Display "ERROR" in case of invalid number input. Default positions are okay and you may skip 
absolute positions for the displays as long as every item is visible. 

You can import the built-in packages, however not to declare your own package inside the program. Declare the main 
class as public.

*/

import java.util.*;
import java.io.*;
import java.lang.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class GUIReverse implements ActionListener
{
	JFrame f;
	JLabel l;
	JTextField t1;
	JButton b;
	JLabel res;
	
	GUIReverse()
	{
		f=new JFrame("GUI Reverse");
		
		l=new JLabel("Enter the whole number");
		l.setBounds(50,50,200,20);
		f.add(l);
		
		t1=new JTextField();
		t1.setBounds(50,80,200,20);
		f.add(t1);
		
		b=new JButton("Submit");
		b.setBounds(50,120,95,30);
		b.addActionListener(this);
		f.add(b);
		
		res=new JLabel("Result: ");
		res.setBounds(50,160,200,20);
		f.add(res);
		
		f.setLayout(null);
		f.setSize(500,500);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setVisible(true);		
		
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getActionCommand().equals("Submit"))
		{
			displayResult(t1.getText());
		}
	}
	
	public void displayResult(String a)
	{
		int n;
		if(a.isEmpty())
		{	
			res.setText("Result : Empty Input Field");
		}
		else
		{
			try
			{
				n=Integer.parseInt(a);
				if(n<0)
				{
					res.setText("ERROR");
				}
				else
				{
					String b=new StringBuilder(a).reverse().toString();
					t1.setEditable(false);
					res.setText("Result : "+b);
				}
			}
			catch(Exception e)
			{
				res.setText("ERROR");
			}
		}
	}
	
	public static void main(String args[]) throws Exception
	{
		new GUIReverse();
	}
	
}

