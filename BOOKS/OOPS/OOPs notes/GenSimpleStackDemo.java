class GenSimpleStackDemo {
	public static void main(String args[]) {
		int i;
		
		/** String stack **/
		System.out.println("Demonstrating String Stack ");
		String[] strs = new String[3];	// String array		
		GenSimpleStack<String> strStack = new GenSimpleStack<String>(strs);
		
		try {
			System.out.println("Pushing: alpha beta gamma");
			strStack.push("alpha");
			strStack.push("beta");
		    strStack.push("gamma");
		    // strStack.push("delta");
		        		        
			System.out.print("Popping: ");		        
			while (!strStack.isEmpty())
				System.out.print(strStack.pop() + " ");
			System.out.println();
						
		}
		
		catch (StackFullException exc) {
			System.out.println(exc);			
		}

		catch (StackEmptyException exc) {
			System.out.println(exc);			
		}
		
		System.out.println();
		
		/*** Integer Stack **/		
		System.out.println("Demonstrating Integer Stack ");
		Integer[] nums = new Integer[3];	// Integer array
		GenSimpleStack<Integer> intStack = new GenSimpleStack<Integer>(nums);
		
		try {
			System.out.println("Pushing: 10 20 30");
			intStack.push(10);
			intStack.push(20);
		    intStack.push(30);
		    // intStack.push(40);
		        		        		        
			System.out.print("Popping: ");		        
			while (!intStack.isEmpty())
				System.out.print(intStack.pop() + " ");
			System.out.println();
						
		}
		
		catch (StackFullException exc) {
			System.out.println(exc);			
		}

		catch (StackEmptyException exc) {
			System.out.println(exc);			
		}

		
	}
}



