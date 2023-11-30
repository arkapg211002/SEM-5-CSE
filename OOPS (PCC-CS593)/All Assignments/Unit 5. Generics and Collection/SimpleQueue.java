import java.util.*;
import java.io.*;
import java.lang.*;

public class SimpleQueue {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        final int MAX = 5;
        String q[] = new String[MAX];
        GenSimpleQueue<String> queue = new GenSimpleQueue<String>(q);

        while (true) {
            int ch = sc.nextInt();
            switch (ch) {
                case 0:
                    System.exit(0);
                case 1:
                    try {
                        queue.enqueue(sc.next());
                    } catch (QueueFullException e) {
                        System.out.print(e);
                    }
                    break;
                case 2:
                    try {
                        queue.dequeue();
                    } catch (QueueEmptyException e) {
                        System.out.print(e);
                    }
                    break;
            }
        }
    }
}

interface IGenSimpleQueue<T> {
    public void enqueue(T item) throws QueueFullException;
    public void dequeue() throws QueueEmptyException;
    public boolean isEmpty();
    public boolean isFull();
}

class GenSimpleQueue<T> implements IGenSimpleQueue<T> {
    T[] data;
    int front, rear;
    
    GenSimpleQueue(T[] ds) {
        this.data = ds;
        front = rear = 0;
    }

    public void enqueue(T item) throws QueueFullException {
        if (isFull()) throw new QueueFullException(data.length);
        data[rear] = item;
        rear = (rear + 1) % data.length;
    }

    public void dequeue() throws QueueEmptyException {
        if (isEmpty()) throw new QueueEmptyException();
        System.out.print(data[front] + " ");
        front = (front + 1) % data.length;
    }

    public boolean isEmpty() {
        return front == rear;
    }

    public boolean isFull() {
        return (rear + 1) % data.length == front;
    }
}

class QueueFullException extends Exception {
    int size;
    
    QueueFullException(int size) {
        super("Queue Full");
        this.size = size;
    }

    public String toString() {
        return ("[Full-" + size + "] ");
    }
}

class QueueEmptyException extends Exception {
    QueueEmptyException() {
        super("Queue Empty");
    }

    public String toString() {
        return ("[Empty] ");
    }
}
