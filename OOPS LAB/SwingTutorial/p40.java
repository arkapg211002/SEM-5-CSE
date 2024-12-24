/**
 * Write a program to create a frame using AWT. Implement ActionListener interface
 */
import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class p40 extends JFrame implements ActionListener {
    JButton b;
    Container c;

    p40() {
        c = getContentPane();
        c.setLayout(new FlowLayout());
        b = new JButton("color");
        b.addActionListener(this);
        c.add(b);
    }

    Color initialcolor = Color.RED;

    public void actionPerformed(ActionEvent e) {
        Color color = JColorChooser.showDialog(this, "Select a color", initialcolor);
        c.setBackground(color);
        initialcolor = color;
    }

    public static void main(String[] args) {
        p40 ch = new p40();
        ch.setSize(400, 400);
        ch.setVisible(true);
        ch.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}