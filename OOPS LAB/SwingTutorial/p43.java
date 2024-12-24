/**
 * This program demonstrates how to use JSlider class to create a slider.
 */
import javax.swing.*;

public class p43 extends JFrame {
    public p43() {
        JSlider slider = new JSlider(JSlider.HORIZONTAL, 0, 50, 25);
        JPanel panel = new JPanel();
        panel.add(slider);
        add(panel);
    }

    public static void main(String s[]) {
        p43 f = new p43();
        f.pack();
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}