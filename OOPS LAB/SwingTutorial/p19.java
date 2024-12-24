/**
 * Write a program to create a combo box component and add items to it.
 */

import javax.swing.*;

public class p19 {
    JFrame f;

    p19() {
        f = new JFrame("ComboBox Example");
        String country[] = { "India", "Aus", "U.S.A", "England", "Newzealand" };
        JComboBox cb = new JComboBox(country);
        cb.setBounds(50, 50, 90, 20);
        f.add(cb);
        f.setLayout(null);
        f.setSize(400, 500);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        new p19();
    }
}