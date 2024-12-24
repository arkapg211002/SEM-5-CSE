class StackFullException extends Exception {
	int  size;
	
	StackFullException(int s) {
		super("StackFull");
		size = s;
	}
	
	public String toString() {
		return("Stack Full (max: " + size + "): Cannot push more");
	}
}

class StackEmptyException extends Exception {
	int  size;
	
	StackEmptyException() {
		super("StackEmpty");
	}
	
	public String toString() {
		return("Stack empty: Cannot pop more");
	}
}
