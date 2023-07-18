/**
Write a Java program to input a number and display the reverse of that number.
  
Input	
173
  
Result
371

*/

import java.util.Scanner;
public class RevNum {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        int s = 0;
        int rem; 
        /* Shape up the logic */
        /* Hints: Calculate remainder over 10 */
        /* Progressively divide by 10 until n value is 0 */
        
        while(n>0)
        {
            rem=n%10;
            s=(s*10)+rem;
            n/=10;
        }
        System.out.println( s );
        
    }
}
