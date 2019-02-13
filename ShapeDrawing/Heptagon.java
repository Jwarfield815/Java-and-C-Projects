// Heptagon.java
// Class Heptagon definition
import java.lang.Math;

public class Heptagon
{
   private Point point1; // first endpoint
   private Point point2; // second endpoint
   private Point point3; // third endpoint
   private Point point4; // fourth endpoint
   private Point point5; // fifth endpoint
   private Point point6; // sixth endpoint
   private Point point7; // seventh endpoint

   // eight-argument constructor
   public Heptagon(double x1, double y1, double x2, double y2,
      double x3, double y3, double x4, double y4, double x5, 
      double y5, double x6, double y6, double x7, double y7) 
   {
      point1 = new Point(x1, y1);
      point2 = new Point(x2, y2);
      point3 = new Point(x3, y3);
      point4 = new Point(x4, y4);
      point5 = new Point(x5, y5);
      point6 = new Point(x6, y6);
      point7 = new Point(x7, y7);
   } 

   // return point1
   public Point getPoint1() 
   {
      return point1;
   }

   // return point2
   public Point getPoint2() 
   {
      return point2;
   } 

   // return point3
   public Point getPoint3() 
   {
      return point3;
   }

   // return point4
   public Point getPoint4() 
   {
      return point4;
   }

   public Point getPoint5()
   {
      return point5;
   }
   
   public Point getPoint6()
   {
      return point6;
   }
   
   public Point getPoint7()
   {
      return point7;
   }
   
   public double getArea()
   {
      double area;
      final double PI;
      double side = Math.abs(getPoint1().getX() - getPoint2().getX());
      int n = 7;
      
      PI = Math.PI;
      
      area = (n * (side * side)) / (4 * (Math.tan(PI/n)));
      
      return area;
   }
   // return string representation of a heptagon object
   @Override
   public String toString() 
   {
      double side = Math.abs(getPoint1().getX() - getPoint2().getX());
       return String.format("\n%s:\n%s %s %4.2f \n%s:%4.2f ", 
         "Coordinates of Heptagon are", getCoordinatesAsString(),
         "Side length", side,
         "Area ", getArea());
      
   } 

   // return string containing coordinates as strings
   public String getCoordinatesAsString() 
   {
      return String.format(
         "%s, %s, %s, %s, %s, %s, %s\n", point1, point2, point3, point4, point5, point6, point7);
   }
}
