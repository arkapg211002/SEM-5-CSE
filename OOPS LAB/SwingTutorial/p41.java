/**
 * Color Chooser Example.
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class p41 extends JFrame implements ActionListener {
    JFrame f;
    JButton b;
    JTextArea ta;

    p41() {
        f = new JFrame("Color Chooser Example.");
        b = new JButton("Pad Color");
        b.setBounds(200, 250, 100, 30);
        ta = new JTextArea();
        ta.setBounds(10, 10, 300, 200);
        b.addActionListener(this);
        f.add(b);
        f.add(ta);
        f.setLayout(null);
        f.setSize(400, 400);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    Color initial = Color.CYAN;

    public void actionPerformed(ActionEvent e) {
        Color c = JColorChooser.showDialog(this, "Choose", initial);
        ta.setBackground(c);
        initial = c;
    }

    public static void main(String[] args) {
        new p41();
    }
}