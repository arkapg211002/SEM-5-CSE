/*

Write a Java program SimpleGUI.java to develop a simple GUI for capturing a whole number and display the sum of digits.
Display ERROR in case of invalid input number. Default positions are okay and absolute positions can be skipped as long
as the display is visible 

*/

import java.util.*;
import java.lang.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;

public class SimpleGUI implements ActionListener
{
	JFrame f;
	JLabel l;
	JTextField t;
	JButton b;
	JLabel res;
	
	SimpleGUI()
	{
		f=new JFrame("Simple GUI");
		
		l=new JLabel("Enter whole number");
		l.setBounds(50,50,200,20);
		f.add(l);
		
		t=new JTextField();
		t.setBounds(50,80,200,20);
		f.add(t);
		
		b=new JButton("Submit");
		b.setBounds(50,120,95,30);
		b.addActionListener(this);
		f.add(b);
		
		res=new JLabel("Result : ");
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
			displayResult(t.getText());
	}
	
	public void displayResult(String a)
	{
		if(a.isEmpty())
			res.setText("Result : Input Field Empty");
		else
		{
			try
			{
				int n=Integer.parseInt(a);
				if(n<0)
					res.setText("ERROR");
				else{
					int s=0;
					while(n>0)
					{
						s+=(n%10);
						n/=10;
					}
					res.setText("Result : Sum of digits of "+t.getText()+" is -> "+Integer.toString(s));
					t.setEditable(false);
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
		new SimpleGUI();
	}
}