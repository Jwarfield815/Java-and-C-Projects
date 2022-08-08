// Name: Jonathan Warfield
// Date: 01/25/2019
// Description: Enter a binary number, and this program converts it to decimal

import java.util.Scanner;

public class BinaryToDecimal
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        
        int bit = 1; // bit positional value
        int decimal = 0; // decimal value
        
        // prompt for and read in a binary number
        System.out.print("Enter a binary number: ");
        int binary = 0;
        if(input.hasNextInt() )
            binary = input.nextInt(); // if there is another number
        
        // convert to decimal equivalent
        while(binary != 0)
        {
            decimal += binary % 10 * bit;
            binary /= 10;
            bit *=2;
        }
        
        System.out.printf("\nDecimal is: %d%n", decimal);
    }
}