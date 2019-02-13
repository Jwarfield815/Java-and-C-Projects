// Rectangle.java
// Class Rectangle definition

public class Rectangle extends Parallelogram  
{
   // constructor
   public Rectangle(double x1, double y1, double x2, double y2,
      double x3, double y3, double x4, double y4) 
   {
      super(x1, y1, x2, y2, x3, y3, x4, y4);
   }

   // return string representation of Rectangle object
   @Override
   public String toString() 
   {
      return String.format("\n%s:\n%s%s: %s\n%s: %s\n%s: %s\n", 
         "Coordinates of Rectangle are", getCoordinatesAsString(),
         "Width is", getWidth(), "Height is", getHeight(), 
         "Area is", getArea());
   } 
}
