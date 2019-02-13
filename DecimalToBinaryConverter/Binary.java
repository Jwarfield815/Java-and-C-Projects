//Name: LeBron James
//Date: Hot
//Description: Want a Sprite Cranberry

import java.util.Scanner;

public class Binary
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        
        int bit = 1; //bit positional value
        int decimal = 0; //decimal value
        
        //prompt for and read in a binary number
        System.out.print("Enter a binary number: ");
        int binary = input.nextInt(); //binary value
        
        //convert to decimal equivalent
        while(binary != 0)
        {
            decimal += binary % 10 * bit;
            binary /= 10;
            bit *=2;
        }
        
        System.out.printf("Decimal is: %d%n", decimal);
    }
}