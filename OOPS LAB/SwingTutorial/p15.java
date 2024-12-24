/**
 * Write a program to create a frame with two check boxes C++ and Java. If C++ is selected, display a message “C++ selected” and if Java is selected, display a message “Java selected”.
 */

import javax.swing.*;
import java.awt.event.*;

public class p15 {
    p15() {
        JFrame f = new JFrame("CheckBox Example");
        final JLabel label = new JLabel();
        label.setHorizontalAlignment(JLabel.CENTER);
        label.setSize(400, 100);
        JCheckBox checkbox1 = new JCheckBox("C++");
        checkbox1.setBounds(150, 100, 50, 50);
        JCheckBox checkbox2 = new JCheckBox("Java");
        checkbox2.setBounds(150, 150, 50, 50);
        f.add(checkbox1);
        f.add(checkbox2);
        f.add(label);
        checkbox1.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent e) {
                label.setText("C++ Checkbox: "
                        + (e.getStateChange() == 1 ? "checked" : "unchecked"));
            }
        });
        checkbox2.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent e) {
                label.setText("Java Checkbox: "
                        + (e.getStateChange() == 1 ? "checked" : "unchecked"));
            }
        });
        f.setSize(400, 400);
        f.setLayout(null);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String args[]) {
        new p15();
    }
}