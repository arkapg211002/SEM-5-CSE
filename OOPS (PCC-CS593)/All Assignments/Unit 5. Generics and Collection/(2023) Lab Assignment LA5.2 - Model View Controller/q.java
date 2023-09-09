/**

Leveraging MVC architecture, following program retrieves employee data, update and display view. Please download the partial code from here.

public class MVCNew {
	public static void main(String[] args) {
		Employee model = retrieveEmployeeFromDatabase();  // Model with existing data
		EmployeeView view = new EmployeeView();   	  // Empty view
		
		EmployeeController controller = new EmployeeController( model, view );
                controller.updateView();   			// Display initial view
		
		int newSal = (int) (controller.getEmployeeSalary() * 1.10) ; // 10% hike
		controller.setEmployeeSalary( newSal );   	// User triggers some changes
		controller.updateView();			// Display updated view
	}
	
	public static Employee retrieveEmployeeFromDatabase() {
		Employee s1 = new Employee();   // Empty Employee object
		s1.setId(1012349);
		s1.setName("Ayushman Khurana");
		s1.setSalary(150000);
		return(s1);
	}
}

class Employee {
	private int id;
	private String name;
	private int salary;
	
	public int getId() {
		return id;
	}
	
	public void setId( int id) {
		this.id=id;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName( String name) {
		this.name=name;
	}
	
	public int getSalary() {
		return salary;
	}
	
	public void setSalary( int salary) {
		this.salary=salary;
	}	
}

class EmployeeView {
	public void printEmployeeDetails(int id, String name, int salary) {
		System.out.println("Id: " + id + " | Name: " + name + " | Salary: " + salary);
	}
}

// write the missing part

Write only the missing part in the answer window so that the whole program can generate the expected view as illustrated in the example. 
Avoid re-writing the entire code as it is already stored in the system.

For example:

Result
Id: 1012349 | Name: Ayushman Khurana | Salary: 150000
Id: 1012349 | Name: Ayushman Khurana | Salary: 165000

*/

class EmployeeController{
    Employee model;
    EmployeeView view;
    EmployeeController(Employee model,EmployeeView view){
        this.model=model;
        this.view=view;
    }
    void updateView(){
        view.printEmployeeDetails(model.getId(),model.getName(),model.getSalary());
    }
    int getEmployeeSalary(){
        return model.getSalary();
    }
    void setEmployeeSalary(int salary){
        model.setSalary(salary);
    }
    
}
