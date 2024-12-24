// Generic interafce
public interface IGenSimpleStack<T> {
	void push(T item) throws StackFullException;
	
	T pop() throws StackEmptyException;
	
	boolean isEmpty();
	
	boolean isFull();
}
