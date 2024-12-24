/**

Write a Java program to develop a stack of size 5, input choice and process as follows:
1: Push element
2: Pop element and display
0. Quit

When stack capacity is 5, display [Full-5] after detecting stack full exception and display [Empty] after detecting stack empty exception.

Note: Answer box is populated with guidelines and part codes. Use it for rapid development.

For example:

Input	
2
0

Result
[Empty]

*/

/* Import libraries */
import java.util.*;
import java.lang.*;
import java.io.*;

public class SimpleStack {
	public static void main(String args[]) {
            Scanner sc=new Scanner(System.in);
	    final int MAX = 5;    /* stack capacity */
            String[] st=new String[MAX];
            /* Instantiate GenSimpleStack */		
            GenSimpleStack<String> stack=new GenSimpleStack<String>(st);

            /* Read choice 0: Quit, 1: Push, 2: Pop */
            
            /* Loop until 0 is entered */
            while (true) {	// Don't forget to return when Quit requested
                /* Use try-catch */
                int ch=sc.nextInt();
                switch(ch)
                {
                    case 0:
                            System.exit(1);
                    case 1:
                            try
                            {
                                stack.push(sc.next());
                            }
                            catch(StackFullException e)
                            {
                                System.out.print(e);
                            }
                            break;
                    case 2:
                            try
                            {
                                stack.pop();
                            }
                            catch(StackEmptyException e)
                            {
                                System.out.print(e);
                            }
                            break;
                    
                }
            }    // end of while
	}    // end of main
} // End of class SimpleStack

/* Declare interfce IGenSimpleStack<T> */
interface IGenSimpleStack<T>
{
    public void push(T item) throws StackFullException;
    public void pop() throws StackEmptyException;
    public boolean isEmpty();
    public boolean isFull();
}

/* Declare GenSimpleStack<T> implementing interface IGenSimpleStack  */
class GenSimpleStack<T> implements IGenSimpleStack<T> {
	/* Declare Generic array */
        T[] data;
	/* Declare Top of stack */
	int tos;
        /* Declare Constructor */
        GenSimpleStack(T[] ds)
        {
            this.data=ds;
            tos=0;
        }
        /* Declare Push */
        public void push(T item) throws StackFullException
        {
            if(isFull()) throw new StackFullException(data.length);
            data[tos]=item;
            tos++;
        }
        /* Declare Pop */
        public void pop() throws StackEmptyException
        {
            if(isEmpty()) throw new StackEmptyException();
            tos--;
            System.out.print(data[tos]+" ");
        }
        /* Declare isFull */
        public boolean isFull()
        {
            return tos==data.length;
        }
        /* Declare isEmpty */
        public boolean isEmpty()
        {
            return tos==0;
        }
}
/* Declare StackFullException class */
class StackFullException extends Exception
{
    int size;
    StackFullException(int s)
    {
        super("StackFull");
        size=s;
    }
   
    /* Override toString() */
    public String toString()
    {
        return ("[Full-5] ");
    }
    
}
/* Declare StackEmptyException class */
class StackEmptyException extends Exception
{
    StackEmptyException()
    {
        super("StackEmpty");
    }
    /* Override toString() */
    public String toString()
    {
        return ("[Empty] ");
    }
}
