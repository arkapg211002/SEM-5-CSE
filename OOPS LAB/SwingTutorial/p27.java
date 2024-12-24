import javax.swing.*;

public class p27 {
    JFrame f;

    p27() {
        f = new JFrame();
        String name = JOptionPane.showInputDialog(f, "Enter Name");
    }

    public static void main(String[] args) {
        new p27();
    }
}