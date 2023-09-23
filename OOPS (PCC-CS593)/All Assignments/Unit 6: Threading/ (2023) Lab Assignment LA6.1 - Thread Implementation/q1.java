/**

Observe the following program carefully which is expected to create thread and compute factorial:


???

public class TestRunnable {
    public static void main(String[] args) {
        System.out.println("Main Thread: Started");
        
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        MyThread mt1=new MyThread("Factorial", n); //Construct a runnable object

        Thread nt1=new Thread(mt1); //Construct a thread on that object
        nt1.start(); //Start running the thread

        System.out.println("Main Thread: Ended");
     }
}


Replace ??? with suitable lines so that the program can run as illustrated in the example.

Write only the missing part in the answer window. Avoid writing the full program / class, main() method, input / output handling or validation of inputs.

For example:

Input	
4

Result
Main Thread: Started
Main Thread: Ended
Factorial Thread: Started
Factorial Thread: 24
Factorial Thread: Ended

*/


import java.util.*;

class MyThread implements Runnable{
    String name;
    Thread thrd;
    int n;
    
    MyThread(String name,int n){
        this.name=name;
        this.n=n;
    }
    public void run(){
        System.out.println(name+" Thread: Started");
        int i,sum=1;
        for(i=n;i>0;i--){
            sum=sum*i;
        }
        if(n>=0)
        System.out.println(name+" Thread: "+sum);
        else
        System.out.println(name+" Thread: ERROR");
        System.out.println(name+" Thread: Ended");
    }
}


