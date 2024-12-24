class GenSimpleStack<T> implements IGenSimpleStack<T> {
	private T[] data;	// Generic array
	private int tos;	// Top of stack
	
	GenSimpleStack(T[] arrayRef) {	// Actual array parameter
		data = arrayRef;		// Empty array
		tos = 0;	// 1st available [position in the empty array
	}	

	public void push(T obj) throws StackFullException {	// Push element
		if (isFull())		// Prevent overflow: Exception handling
			throw new StackFullException(data.length);
			
		data[tos] = obj;
		tos++;
	}

	public T pop() throws StackEmptyException {		// Pop element
		if (isEmpty())		// Prevent underflow: Exception handling
			throw new StackEmptyException();
			
		tos--;
		return data[tos];
	}

	public boolean isFull() {				// Check whether stack is full
		return tos==data.length;
	}

	public boolean isEmpty() {				// Check whether stack is empty
		return tos==0;
	}

}
