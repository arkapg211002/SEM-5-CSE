import java.applet.*;
import java.awt.*;

public class first extends Applet
{
    @Override
    public void paint(Graphics g)
    {
        g.drawString("Hello world from applet",150,150);
    }
}

/* 
<applet code="first.class" width="300" height="300"> 
</applet> 
*/  