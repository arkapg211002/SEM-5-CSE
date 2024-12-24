/**

Write a Java program to input n and add n number of integers. In case of InputMismatchException, display "ERROR". Click here for a sample program for handling this type of exceptions.



Avoid using any input or output prompts.

For example:

Input	
3
10 20 5

Result
35


*/


import java.util.*;
public class Solution
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n,s=0;
        n=sc.nextInt();
        try
        {
            for(int i=1;i<=n;i++)
            {
                int a=sc.nextInt();
                s=s+a;
            }
            System.out.println(s);     
        }
        catch(InputMismatchException e)
        {
            System.out.println("ERROR");
        }
    }
}
