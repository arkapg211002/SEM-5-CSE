import java.awt.BorderLayout;
import java.awt.Container;
import javax.swing.JDesktopPane;
import javax.swing.JFrame;
import javax.swing.JInternalFrame;
import javax.swing.JLabel;

public class p54 extends JFrame {
    public p54() {
        CustomDesktopPane desktopPane = new CustomDesktopPane();
        Container contentPane = getContentPane();
        contentPane.add(desktopPane, BorderLayout.CENTER);
        desktopPane.display(desktopPane);

        setTitle("JDesktopPane Example");
        setSize(300, 350);
        setVisible(true);
    }

    public static void main(String args[]) {
        new p54();
    }
}

class CustomDesktopPane extends JDesktopPane {
    int numFrames = 3, x = 30, y = 30;

    public void display(CustomDesktopPane dp) {
        for (int i = 0; i < numFrames; ++i) {
            JInternalFrame jframe = new JInternalFrame("Internal Frame " + i, true, true, true, true);

            jframe.setBounds(x, y, 250, 85);
            Container c1 = jframe.getContentPane();
            c1.add(new JLabel("I love my country"));
            dp.add(jframe);
            jframe.setVisible(true);
            y += 85;
        }
    }
}