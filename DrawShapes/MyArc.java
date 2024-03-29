import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class MyArc {
    private double x1; // x coordinate of first endpoint
    private double y1; // y coordinate of first endpoint
    private double x2; // x coordinate of second endpoint
    private double y2; // y coordinate of second endpoint
    private Color myColor; // color of this shape
    private boolean filled;

    public MyArc() {
        this(0, 0, 0, 0, Color.BLACK, false);
    }

    public MyArc(int x1, int y1, int x2, int y2, Color color, boolean isFilled) {
        setX1(x1);
        setY1(y1);
        setX2(x2);
        setY2(y2);
        setColor(color);
        setFilled(isFilled);
    }

    public void setX1(int x1) {
        this.x1 = (x1 >= 0 ? x1 : 0); // using ?: as if...else
    }

    public double getX1() {
        return x1;
    }

    public void setX2(int x2) {
        this.x2 = (x2 >= 0 ? x2 : 0); // using ?: as if...else
    }

    public double getX2() {
        return x2;
    }

    public void setY1(int y1) {
        this.y1 = (y1 >= 0 ? y1 : 0); // using ?: as if...else
    }

    public double getY1() {
        return y1;
    }

    public void setY2(int y2) {
        this.y2 = (y2 >= 0 ? y2 : 0); // using ?: as if...else
    }

    public double getY2() {
        return y2;
    }

    public void setColor(Color color) {
        myColor = color;
    }

    public Color getColor() {
        return myColor;
    }

    public double getUpperLeftX() {
        return Math.min(getX1(), getX2());
    }

    public double getUpperLeftY() {
        return Math.min(getY1(), getY2());
    }

    public double getWidth() {
        return Math.abs(getX2() - getX1());
    }

    public double getHeight() {
        return Math.abs(getY2() - getY1());
    }

    public boolean isFilled() {
        return filled;
    }

    public void setFilled(boolean isFilled) {
        filled = isFilled;
    }

    public void draw(GraphicsContext gc)
    {
        if (isFilled())
        {
            gc.setFill(getColor());
            gc.fillArc(getUpperLeftX(), getUpperLeftY(), getWidth(), getHeight(), 100.0, 100.0, javafx.scene.shape.ArcType.OPEN);
        }
        else
        {
            gc.setStroke(getColor());
            gc.strokeArc(getUpperLeftX(), getUpperLeftY(), getWidth(), getHeight(), 100.0, 100.0, javafx.scene.shape.ArcType.OPEN);
        }
    }
}