/**
Write a Java program to input marks in two courses and display their average after ignoring the fractional parts (if any).
Ensure to declare the main class as public. BTW, main class is the class having main() method.

Input	
50 31

Result
40

*/

import java.util.*;
public class ComputeAverage {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt(); /* Check comments in earlier program */
        int n2 = sc.nextInt();
        System.out.println((n1+n2)/2);
    }
}
