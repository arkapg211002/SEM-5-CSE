/**

Study the following program with real-life example where the child buys a new car and stays in the existing home. Write only the missing part in the answer window:

class Parent {   
    public void home() {
        System.out.println("Existing home");
    }
    public void car() {
        System.out.println("Existing car");
    }   
}

?????

public class TestOverride {
    public static void main(String[] args) {
        Child c1 = new Child();
        c1.home();
        c1.car();
    }
}

Result
Existing home
New Car


*/

// Do not write the full program. Write only the missing part
// Declare Child class 
class Child extends Parent { 
        // Declare car() method
	public void car() {
                // Display "New car"
                System.out.println("New Car");
	}	
}
