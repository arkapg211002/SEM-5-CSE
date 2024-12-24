/**
 * Write a program to display a message “Hello, Welcome to Javatpoint.”
 */
import javax.swing.*;

public class p25 {
    JFrame f;

    p25() {
        f = new JFrame();
        JOptionPane.showMessageDialog(f, "Hello, Welcome to Javatpoint.");
    }

    public static void main(String[] args) {
        new p25();
    }
}