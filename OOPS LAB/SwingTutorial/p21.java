import javax.swing.*;

public class p21 {
    JFrame f;

    p21() {
        f = new JFrame();
        String data[][] = { { "101", "Amit", "670000" },
                { "102", "Jai", "780000" },
                { "101", "Sachin", "700000" } };
        String column[] = { "ID", "NAME", "SALARY" };
        JTable jt = new JTable(data, column);
        jt.setBounds(30, 40, 200, 300);
        JScrollPane sp = new JScrollPane(jt);
        f.add(sp);
        f.setSize(300, 400);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        new p21();
    }
}