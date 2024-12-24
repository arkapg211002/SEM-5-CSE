/**
 *  appletviewer.java -- a simple applet viewer
 */

import java.applet.Applet;
import java.awt.Frame;
import java.awt.Graphics;
import javax.swing.*;
public class appletviewer extends JFrame {
    public static void main(String[] args) throws Exception {
        Class c = Class.forName(args[0]);

        appletviewer v = new appletviewer();
        v.setSize(400, 400);
        v.setLayout(null);
        v.setVisible(true);
        v.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Applet a = (Applet) c.newInstance();
        a.start();
        Graphics g = v.getGraphics();
        a.paint(g);
        a.stop();

    }

}