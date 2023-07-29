/**

Study the following program on method overloading, and write only the missing part in the answer window:

import java.util.Scanner;

????   // Your code

public class MethodOverloadTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
       
        // Inputs
        int n = sc.nextInt();
        double d = sc.nextDouble();
       
        // Instantiate MethodOverload class for using square methods
        MethodOverload mol = new MethodOverload();
       
        // Call square method
        System.out.printf("Square of %d: %d\n", n, mol.square(n) );
       
        // Call overloaded square method
        // BTW, overloading also possible with different number or order of parameters
        System.out.printf("Square of %f: %.2f\n", d, mol.square(d) ); // Overloaded method
    }
}

Input	Result
-2    Square of -2: 4
1.5   Square of 1.500000: 2.25

*/

// Do not write the full program. Write only the missing part

// Declare class MethodOverload
class MethodOverload {
        // Declare square method for returning area in integer
	int square(int n)
        {
            return (n*n);
        }
        // Declare square method for returning area in double
        double square(double d)
        {
            return (d*d);
        }
}
