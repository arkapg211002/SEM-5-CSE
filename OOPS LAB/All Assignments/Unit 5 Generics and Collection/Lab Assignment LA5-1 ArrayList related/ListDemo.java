/**
Please study the following program carefully which is responsible for inputting a few numbers, populate an array list, sort in descending order and perform binary search in the sorted list for the entered key.

You are required to supply the missing part in the answer window aligning with the expected outputs (refer the example).

import java.util.*;
public class ListDemo {
    
    ???? // Missing part

    public static void main(String[] args) {

        int key, index;       

        // Create Scanner objects
        Scanner sc = new Scanner(System.in);  // Handle inputs
        
        // Create a list of Integers
        ArrayList<Integer> al = new ArrayList<Integer>();

        // Enter few numbers in a line and populate the list
        populateList( sc, al );    
        
        // Display list
        displayList( "Original List", al );
        
        // Sort list in descending order
        sortListDesc( al );
        
        // Display sorted list
        displayList( "Sorted List", al );
        
        // Input key
        key = sc.nextInt();
        
        // Perform binary search for key in al
        index = binSearch(al, key);
        if (index >= 0)
            System.out.println("Position: " + index);
        else
            System.out.println("Not found");
        }
}

You can also click here to download the part program for necessary modifications and testing.

Hints: For sorting in reverse order, you may use Collections.reverseOrder() parameter while calling Collections.sort().

For example:

Input	

45 23 67 12
23

Result

Original List: 45 23 67 12
Sorted List: 67 45 23 12
Position: 2

*/


import java.util.*;
public class ListDemo {

        // Write your code here
        static void populateList(Scanner sc,ArrayList<Integer> list){
        int num;
        String line = sc.nextLine();
        Scanner scs = new Scanner(line);
        while(scs.hasNextInt()){
        num = scs.nextInt();
        list.add(num);
            }
            }
            static void displayList(String a,ArrayList<Integer> list){
                System.out.print(a+": ");
                for (int i=0;i<list.size();i++){
                System.out.print(list.get(i));
                if(i<list.size()-1){
                System.out.print(" ");
                }
                }
                System.out.println("");
                }
                static void sortListDesc(ArrayList<Integer> list){
                list.sort(Comparator.reverseOrder());
                }
                static int binSearch(ArrayList<Integer> list,int key){
                int low=0;
                int high = list.size()-1;
                while(low<=high){
                int mid = (low+high)/2;
                if(list.get(mid)==key)
                return mid;
                else if(list.get(mid)>key)
                low=mid+1;
                else
                high=mid-1;
                }
                return -1;
                }
                
                
	public static void main(String[] args) {
		// Create Scanner objects
		Scanner sc = new Scanner(System.in);  // Handle inputs
		int key, index;
		
		// Create a list of Integers
		ArrayList<Integer> al = new ArrayList<Integer>();

		// Enter few numbers in a line and populate the list
		populateList( sc, al );	
		
		// Display list
		displayList( "Original List", al );
		
		// Sort list in descending order
		sortListDesc( al );
		
		// Display sorted list
		displayList( "Sorted List", al );
		
		// Input key
		key = sc.nextInt();
		
		// Perform binary search for key in al
		index = binSearch(al, key);
		if (index >= 0)
			System.out.println("Position: " + index);
		else
			System.out.println("Not found");
	}
}
