/**
 * JToggleButton with ItemListener Example
 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class p50 extends JFrame implements ItemListener {
    public static void main(String[] args) {
        new p50();
    }

    private JToggleButton button;

    p50() {
        setTitle("JToggleButton with ItemListener Example");
        setLayout(new FlowLayout());
        setJToggleButton();
        setAction();
        setSize(200, 200);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private void setJToggleButton() {
        button = new JToggleButton("ON");
        add(button);
    }

    private void setAction() {
        button.addItemListener(this);
    }

    public void itemStateChanged(ItemEvent eve) {
        if (button.isSelected())
            button.setText("OFF");
        else
            button.setText("ON");
    }
}