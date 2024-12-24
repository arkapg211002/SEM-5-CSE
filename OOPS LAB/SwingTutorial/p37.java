/**
 * Separator Example
 */

import javax.swing.*;
import java.awt.*;

public class p37 {
    public static void main(String args[]) {
        JFrame f = new JFrame("Separator Example");
        f.setLayout(new GridLayout(0, 1));
        JLabel l1 = new JLabel("Above Separator");
        l1.setHorizontalAlignment(JLabel.CENTER);
        f.add(l1);
        JSeparator sep = new JSeparator();
        f.add(sep);
        JLabel l2 = new JLabel("Below Separator");
        l2.setHorizontalAlignment(JLabel.CENTER);
        f.add(l2);
        f.setSize(400, 100);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}