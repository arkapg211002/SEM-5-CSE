import java.awt.*;
import java.applet.*;

public class p2 extends Applet {
    @Override
    public void paint(Graphics g) {
        // g.drawString("Hello world from applet",150,150);
        g.draw3DRect(100, 100, 100, 100, true);

        // g.drawLine(100, 100, 200, 200);
        // g.drawOval(100, 100, 100, 100);
        // g.drawPolygon(new int[]{100, 200, 300}, new int[]{100, 200, 100}, 3);
        // g.drawRect(100, 100, 100, 100);
        // g.drawRoundRect(100, 100, 100, 100, 100, 100);
        // g.fill3DRect(100, 100, 100, 100, true);
        // g.fillOval(100, 100, 100, 100);
        // g.fillPolygon(new int[]{100, 200, 300}, new int[]{100, 200, 100}, 3);
        // g.fillRect(100, 100, 100, 100);
        // g.fillRoundRect(100, 100, 100, 100, 100, 100);
        g.setColor(Color.red);
    }
}

/*
 * <applet code="p2.class" width="300" height="300"> </applet>
 */