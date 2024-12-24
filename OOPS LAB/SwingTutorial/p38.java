import javax.swing.*;

public class p38 extends JFrame {
    JProgressBar jb;
    int i = 0;

    p38() {
        jb = new JProgressBar(0, 2000);
        jb.setBounds(40, 40, 160, 30);
        jb.setValue(0);
        jb.setStringPainted(true);
        add(jb);
        setSize(250, 150);
        setLayout(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public void iterate() {
        while (i <= 2000) {
            jb.setValue(i);
            i = i + 20;
            try {
                Thread.sleep(100);
            } catch (Exception e) {
            }
        }
    }

    public static void main(String[] args) {
        p38 m = new p38();
        m.setVisible(true);
        m.iterate();
        // close the window when progressbar reach 100%
        m.dispose();
        
    }
}