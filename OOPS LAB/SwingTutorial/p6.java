import javax.swing.*;

class p6 {
    public static void main(String args[]) {
        JFrame f = new JFrame("Label Example");
        JLabel l1, l2;
        l1 = new JLabel("First Label.");
        l1.setBounds(50, 50, 100, 30);
        l2 = new JLabel("Second Label.");
        l2.setBounds(50, 100, 100, 30);
        l1.setHorizontalAlignment(JLabel.CENTER);
        l2.setHorizontalAlignment(JLabel.CENTER);
        f.add(l1);
        f.add(l2);
        f.setSize(300, 300);
        f.setLayout(null);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}