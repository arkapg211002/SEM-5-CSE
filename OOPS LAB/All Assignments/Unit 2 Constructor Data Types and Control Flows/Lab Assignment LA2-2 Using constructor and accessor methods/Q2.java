/**

Write a Java method fact(int n) for returning factorial value for small n within 20.

Avoid writing a full program / class or main() method or error handling for this simple program.



Notes:

1. Display output as instructed and as given in the example (if any). Avoid displaying extra characters or input / output prompts 
while taking input or displaying output, which are otherwise needed for an interactive program.


2. Ensure to indent all programs properly for readbaility. Under curly braces (blocks), ensure to start each line with TAB character(s). 
Please also ensure to write 1-2 comments in small programs and more while writing medium to large programs. 

3. Powered with Programming Assistant Grading Assistant (PAGA) solution for automatically checking your assignments. Press "Check" only when you are ready.
For example:

Test	   Result
fact(5)  120



*/
long fact(long n) {    // may return large numbers
     if (n<0)           // For negative numbers
         return -1;          // No factorial for negative number
     else if (n==0 || n==1)        // For 0 value
         return 1;
     else                       // Otherwise
         return(n*fact(n-1));
}
