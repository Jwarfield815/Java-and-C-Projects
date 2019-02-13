// Point.java
// Class Point definition

public class Point 
{ 
   private double x; // x coordinate
   private double y; // y coordinate
 
   // two-argument constructor
   public Point(double x, double y) 
   {
      this.x = x; 
      this.y = y;
   } 

   // return x
   public double getX()    
   {
      return x;
   } 

   // return y
   public double getY() 
   {
      return y;
   }
   
   // return string representation of Point object
   @Override
   public String toString() 
   {
      return String.format("(%.1f, %.1f)", getX(), getY());
   }
}

