/**

Complete the Java program for dealing with different type of forms and ensure outputs as in the example. 
/// Create interface Form1 

interface Form1 { 

	public String base = "Form 1."; 

	abstract public void display1(); 

} 



// Create interface Form2 which extends Form1 

interface Form2 extends Form1 { 

	public String base = "Form 2."; 

	abstract public void display2(); 

} 



// Create class FormGen is created which implements Form2 

class FormGen implements Form2 { 

	public String base = "Form 3."; 

	//*******

	????? 

	//*******

} 



// Main class 

public class DemoForms { 

	public static void main(String[] args) { 

		// Instantiate FormGen and call display methods 

		FormGen form = new FormGen(); 

		form.display1(); 

		form.display2(); 

	} 

}

Provide only the missing part.
For example:

Result
What? Form 1.
What? Form 2.


*/

public void display1()
{
    System.out.println("What? "+Form1.base);
}
public void display2()
{
    System.out.println("What? "+Form2.base);
}


