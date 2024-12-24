/**
 * This program demonstrates the use of JLayeredPane class.
 */
import javax.swing.*;
import java.awt.*;

public class p53 extends JFrame {
    public p53() {
        super("LayeredPane Example");
        setSize(200, 200);
        JLayeredPane pane = getLayeredPane();
        // creating buttons
        JButton top = new JButton();
        top.setBackground(Color.white);
        top.setBounds(20, 20, 50, 50);
        JButton middle = new JButton();
        middle.setBackground(Color.red);
        middle.setBounds(40, 40, 50, 50);
        JButton bottom = new JButton();
        bottom.setBackground(Color.cyan);
        bottom.setBounds(60, 60, 50, 50);
        // adding buttons on pane
        //pane.add(bottom, 1);
        //pane.add(middle, 2);
        //pane.add(top, 3);

        // adding buttons on pane with different order
        pane.add(top, 3);
        pane.add(middle, 2);
        pane.add(bottom, 1);


    }

    public static void main(String[] args) {
        p53 panel = new p53();
        panel.setVisible(true);
        panel.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}