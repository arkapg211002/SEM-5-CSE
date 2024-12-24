/**
 * Write a program to create a list of programming languages and frameworks. 
 * When the user selects a programming language, the list of frameworks should be displayed. 
 * Use JList and ActionListener.
 */
import javax.swing.*;
import java.awt.event.*;

public class p24 {
    p24() {
        JFrame f = new JFrame();
        final JLabel label = new JLabel();
        label.setHorizontalAlignment(JLabel.CENTER);
        label.setSize(500, 100);
        JButton b = new JButton("Show");
        b.setBounds(200, 150, 80, 30);
        final DefaultListModel<String> l1 = new DefaultListModel<>();
        l1.addElement("C");
        l1.addElement("C++");
        l1.addElement("Java");
        l1.addElement("PHP");
        final JList<String> list1 = new JList<>(l1);
        list1.setBounds(100, 100, 75, 75);
        DefaultListModel<String> l2 = new DefaultListModel<>();
        l2.addElement("Turbo C++");
        l2.addElement("Struts");
        l2.addElement("Spring");
        l2.addElement("YII");
        final JList<String> list2 = new JList<>(l2);
        list2.setBounds(100, 200, 75, 75);
        f.add(list1);
        f.add(list2);
        f.add(b);
        f.add(label);
        f.setSize(450, 450);
        f.setLayout(null);
        f.setVisible(true);
        b.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String data1 = "", data2 = "";
                if (list1.getSelectedIndex() != -1) {
                    data1 = "Programming language Selected: " + list1.getSelectedValue();
                    label.setText(data1);
                }
                if (list2.getSelectedIndex() != -1) {
                    data2 =data1 + ", FrameWork Selected: " + list2.getSelectedValue();
                    
                }
                label.setText(data2);
            }
        });
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String args[]) {
        new p24();
    }
}