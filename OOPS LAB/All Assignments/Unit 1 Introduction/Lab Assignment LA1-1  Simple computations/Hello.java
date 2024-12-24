/**
Write a Java program to input user's name and greet the user as stated in the example. 
Study the given partial code, fill-in the required code and apply your understanding in solving the next problem.

Ensure to declare the main class as public. Obviously, main class is the class with main() method.

Input	
Mr. James Gosling

Result
Hello Mr. James Gosling!

*/

import java.util.Scanner;
public class Hello {
    public static void main(String args[]) {
        /* Create Scanner object for reading from keyboard */
        Scanner sc = new Scanner(System.in);
        
        /* Use nextLine() for string input and nextInt() for integer input */
        String name = sc.nextLine(); 
        
        /* Use + operator for concatenation */
        System.out.println("Hello " + name + "!"); 

        /* Close the Scanner object */        
        sc.close();
    }
}
