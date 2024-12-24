/**
 * Write a program to create a tabbed pane with three tabs labeled “Main”, “Visit” and “Help”.
 */

import javax.swing.*;

public class p42 {
    JFrame f;

    p42() {
        f = new JFrame();
        JTextArea ta = new JTextArea(200, 200);
        ta.setEditable(true);
        JPanel p1 = new JPanel();
        p1.add(ta);
        p1.setAutoscrolls(true);
        ta.setText("This is the main tab");   
        // add and edit text in the text area in jpanel


        JPanel p2 = new JPanel();
        JPanel p3 = new JPanel();
        JTabbedPane tp = new JTabbedPane();
        tp.setBounds(50, 50, 200, 200);
        tp.add("main", p1);
        tp.add("visit", p2);
        tp.add("help", p3);
        f.add(tp);
        f.setSize(400, 400);
        f.setLayout(null);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        new p42();
    }
}