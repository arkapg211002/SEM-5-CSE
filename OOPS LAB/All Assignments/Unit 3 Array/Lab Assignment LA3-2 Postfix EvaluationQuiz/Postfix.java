import java.util.*;
import java.lang.*;
import java.io.*;

public class Postfix
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc=new Scanner(System.in);
		String exp[]=new String(sc.nextLine()).split(" ");
		Stack<Integer>s=new Stack<Integer>();
		int e1,e2;
		for(int i=0;i<exp.length;i++)
		{
			String ch=exp[i];
			switch(ch)
			{
				case "+":
					s.push(s.pop()+s.pop());
					break;
				case "-":
					
					e1=s.pop();
					if(s.isEmpty()==true)
						e2=0;
					else
						e2=s.pop();
					s.push(e2-e1);
					break;
				case "/":
					
					e1=s.pop();
					e2=s.pop();
					s.push(e2/e1);
					break;
				case "*":
					s.push(s.pop()*s.pop());
					break;
				default:
					s.push(Integer.parseInt(ch));
			}
		}
		System.out.println(s.pop());
	}
}
