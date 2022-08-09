import java.awt.BasicStroke;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GradientPaint;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JColorChooser;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class DrawFrame extends JFrame implements ItemListener, ActionListener {
    
    private String shapes[] = {"Line", "Oval", "Rectangle"};
    
    private DrawPanel drawPanel;
    
    private JButton undoButton;
    private JButton clearButton;
    private JComboBox<String> shapeChoices;
    private JCheckBox filledCheckBox;
    
    private JButton color1Button;
    private JButton color2Button;
    private JCheckBox gradientCheckBox;
    
    private JTextField lineWidthField;
    private JTextField dashLengthField;
    private JCheckBox dashedCheckBox;
    
    private Color color1;
    private Color color2;
    
    public DrawFrame() {
        super("Java 2D Drawings"); // title
        
        JPanel topPanel = new JPanel(new GridLayout(2, 1));
        topPanel.add(createStandardPanel());
        topPanel.add(createJava2dPanel());
        add(topPanel, BorderLayout.NORTH);
        
        JLabel statusLabel = new JLabel("(0,0)");
        
        add(statusLabel, BorderLayout.SOUTH);
        
        drawPanel = new DrawPanel(statusLabel);
        
        add(drawPanel);
        
        setDrawingPaint();
        setDrawingStroke();
    }
    
    private JPanel createStandardPanel() { // undo, clear, shape choices, and filled option
        JPanel standardOptions = new JPanel(new FlowLayout());
        
        undoButton = new JButton("Undo");
        undoButton.addActionListener(this);
        standardOptions.add(undoButton);
        
        clearButton = new JButton("Clear");
        clearButton.addActionListener(this);
        standardOptions.add(clearButton);
        
        standardOptions.add(new JLabel("Shape:"));
        shapeChoices = new JComboBox<String>(shapes);
        shapeChoices.addItemListener(this);
        standardOptions.add(shapeChoices);
        
        filledCheckBox = new JCheckBox("Filled");
        filledCheckBox.addItemListener(this);
        standardOptions.add(filledCheckBox);
        
        return standardOptions;
    }
    
    private JPanel createJava2dPanel() { // color options, line width, and dash length
        JPanel java2dOptions = new JPanel(new FlowLayout());
        
        gradientCheckBox = new JCheckBox("Use gradient");
        gradientCheckBox.addItemListener(this);
        java2dOptions.add(gradientCheckBox);
        
        color1Button = new JButton("1st Color...");
        color1Button.addActionListener(this);
        color1 = Color.BLACK;
        java2dOptions.add(color1Button);
        
        color2Button = new JButton("2nd Color...");
        color2Button.addActionListener(this);
        color2 = Color.BLACK;
        java2dOptions.add(color2Button);
        
        java2dOptions.add(new JLabel("Line width:"));
        lineWidthField = new JTextField("1.0", 2);
        lineWidthField.addActionListener(this);
        java2dOptions.add(lineWidthField);
        
        java2dOptions.add(new JLabel("Dash Length:"));
        dashLengthField = new JTextField("10", 2);
        dashLengthField.addActionListener(this);
        java2dOptions.add(dashLengthField);
        
        dashedCheckBox = new JCheckBox("Dashed");
        dashedCheckBox.addItemListener(this);
        java2dOptions.add(dashedCheckBox);
        
        return java2dOptions;
    }
    
    public void itemStateChanged(ItemEvent e) {
        if (e.getSource() == shapeChoices)
            drawPanel.setShapeType(shapeChoices.getSelectedIndex());
        else if (e.getSource() == filledCheckBox)
            drawPanel.setFilledShape(filledCheckBox.isSelected());
        else if (e.getSource() == gradientCheckBox)
            setDrawingPaint();
        else if (e.getSource() == dashedCheckBox);
            setDrawingStroke();
    }
    
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == undoButton) // undo button functionality
            drawPanel.clearLastShape();
        else if(e.getSource() == clearButton) // clear button functionality
            drawPanel.clearDrawing();
        else if(e.getSource() == color1Button) { // color 1 change dialogue box functionality
            Color temp = JColorChooser.showDialog(this, "Chose a color", color1);
            
            if (temp != null)
                color1 = temp;
                
            setDrawingPaint();
        }
        else if (e.getSource() == color2Button) { // color 2 change dialogue box functionality
            Color temp =
                JColorChooser.showDialog(this, "Choose a color", color2);
                
            if (temp != null)
                color2 = temp;
                
            setDrawingPaint();
        }
        else if (e.getSource() == lineWidthField) // line width functionality
            setDrawingStroke();
        else if (e.getSource() == dashLengthField) // dash length functionality
            setDrawingStroke();
    }
    
    private void setDrawingPaint() {
        if (gradientCheckBox.isSelected())
            drawPanel.setDrawingPaint(
                new GradientPaint(0, 0, color1, 50, 50, color2, true));
        else
            drawPanel.setDrawingPaint(color1);
    }
    
    private void setDrawingStroke() {
        float width = Float.parseFloat(lineWidthField.getText());
        
        if (dashedCheckBox.isSelected()) {
            float dashes[] =
                { Float.parseFloat(dashLengthField.getText()) };
                
            drawPanel.setDrawingStroke(new BasicStroke(
                width, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND,
                10, dashes, 0));
        }
        else
            drawPanel.setDrawingStroke(new BasicStroke(
                width,BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
    }
}
