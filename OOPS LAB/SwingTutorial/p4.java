import javax.swing.*;    
public class p4 {  
public static void main(String[] args) {  
    JFrame f=new JFrame("Button Example");  
    JButton b=new JButton("Click Here");  
    b.setBounds(50,100,95,30);  
    f.add(b);  
    f.setSize(400,400);  
    f.setLayout(null);  
    f.setVisible(true);   
    f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}  
}  