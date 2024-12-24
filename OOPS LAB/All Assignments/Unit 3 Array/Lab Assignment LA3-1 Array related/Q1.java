/**

Partial Java program (click here to view) is internally stored in this system to input a few integers
and form an array. Write the missing method find(int key, int arr[]) to check whether a specific number 
is existing or not. Ensure to take inputs only when a number is existing in the input stream. 

Avoid displaying extra characters or input / output prompts while taking input or displaying output.



Input	
10
21 10 5

Result

Found

*/

/* Need static method declaration as it is called from static main() method */
public static boolean find(int key,int arr[])
{
    for(int n: arr)
    {
        if(n==key)
        {
            return true;
        }
    }
    return false;
}
