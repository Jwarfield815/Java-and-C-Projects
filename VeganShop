/*
Name: Jonathan Warfield
Date: 9/20/18
Description: A shop where you can buy different types of food and use coupons
*/

#include <string>
#include <Windows.h>
#include <iostream>
#include <iomanip> //allows for setw to center text, and setprecision to keep numbers within a certain number of decimal points
#include <stdlib.h> //allows the clearing of the console
#include <ctime> //allows for randomizing by time
#include <limits>

using namespace std;

void menu();
void drinks();
void food();
void dessert();
void exit();
void pay();
void amount();
void coupons();

char c[10000]; //char that stores the number corresponding to each menu item that the user ordered
char coupon = ' ';
char choiceMenu = 0;
char choiceDrink = 0;
char choiceFood = 0;
char choiceDessert = 0;

double bisonDiscount = 1.0;
double subTotal = 0.0;
double tax = 0.0;
double fTotal = 0.0;
double money = 0.00;
double bayOfPigs = 10.0;
double duckx3 = 8.0;
double chickenBroth = 100.0;
double frog = 500.0;
double bison = 0.10;
double armadillo = 20.0;
double duck = 800.0;
double baconIceCream = 900.0;
double carmelizedPigEyes = 20.0;
double peep = 10000.0;
double fishStickCake = 10.0;

int couponChoice = 0;
int x = 0;

int main()
{
	system("color e2");

	amount();

	return 0;
}

void menu()
{
	//start menu
	cout << "You have $" << fixed << setprecision(2) << money << ", bon jore" << endl << "Your subtotal is $" << fixed << setprecision(2) << subTotal << ", bon Jore" << endl;
	cout << "Where would you like to go, bon jore?" << endl
		<< "*****************************************************" << endl
		<< "*                     MENU                          *" << endl
		<< "*                  1. DRINKS                        *" << endl
		<< "*                  2. FOOD                          *" << endl
		<< "*                  3. DESSERT                       *" << endl
		<< "*                  4. PAY                           *" << endl
		<< "*                  5. EXIT                          *" << endl
		<< "*****************************************************" << endl;
	cin >> choiceMenu;

	//takes you to the menu you choose
	switch (choiceMenu)
	{
	case '1':
	{
		drinks();//calls drinks function
		break;
	}
	case '2':
	{
		food();//calls food function
		break;
	}
	case '3':
	{
		dessert();//calls dessert function
		break;
	}
	case '4':
	{
		pay();//calls pay function
	}
	case '5':
	{
		exit();
	}
	default:
	{
		system("CLS");
		cout << "invalid input! Bon jore" << endl;
		menu();
		break;
	}
	} //end switch
}
void drinks()
{
	system("CLS");
	//drink menu
	cout << "What would you like to order, bon jour?" << endl;
	cout << "*****************************************************" << endl;
	cout << "*                 DRINK MENU                        *" << endl;
	cout << "*             1. DUCK DUCK DUCK          $" << fixed << setprecision(2) << setw(10) << duckx3 << "*" << endl;
	cout << "*             2. BAY OF PIGS             $" << fixed << setprecision(2) << setw(10) << bayOfPigs << "*" << endl;
	cout << "*             3. CHICKEN BROTH           $" << fixed << setprecision(2) << setw(10) << chickenBroth << "*" << endl;
	cout << "*             4. RETURN TO MENU         50 V-BUCKS  *" << endl;
	cout << "*****************************************************" << endl;
	cin >> choiceDrink;

	switch (choiceDrink)
	{
	case '1':
	{
		cout << "Excellent choice Sir/ma'am/other bon jore. I personally love the duck duck duck, bon jore" << endl;
		subTotal = subTotal + duckx3;
		money = money - duckx3;
		x++;//moves storage place over one
		c[x] = 1;//stores the item ordered
		Sleep(1500);
		system("CLS");
		menu();
		break;
	}
	case '2':
	{
		cout << "Excellent choice Sir/ma'am bon jore. I personally love the Bay of Pigs, bon jore" << endl;
		subTotal = subTotal + bayOfPigs;
		money = money - bayOfPigs;
		x++;//moves storage place over one
		c[x] = 2;//stores the item ordered
		Sleep(1500);
		system("CLS");

		menu();
		break;
	}
	case '3':
	{
		cout << "Excellent choice Sir/ma'am bon jore. I personally love the Chicken Broth, bon jore" << endl;
		subTotal = subTotal + chickenBroth;
		money = money - chickenBroth;
		x++;//moves storage place over one
		c[x] = 3;//stores the item ordered
		Sleep(1500);
		system("CLS");
		menu();
		break;
	}
	case '4':
	{
		system("CLS");
		menu();
	}
	default:
	{
		system("CLS");
		cout << "invalid input! Bon jore" << endl;
		drinks();
		break;
	}
	}//end switch
}
void food()
{
	system("CLS");
	//Food menu
	cout << "What would you like to order, bon jore?" << endl;
	cout << "*****************************************************" << endl;
	cout << "*                  FOOD MENU                        *" << endl;
	cout << "*                  1. FROG              $" << fixed << setprecision(2) << setw(10) << frog << "*" << endl;
	cout << "*                  2. BISON             $" << fixed << setprecision(2) << setw(10) << bison << "*" << endl;
	cout << "*                  3. ARMADILLO         $" << fixed << setprecision(2) << setw(10) << armadillo << "*" << endl;
	cout << "*                  4. DUCK              $" << fixed << setprecision(2) << setw(10) << duck << "*" << endl;
	cout << "*                  5. RETURN TO MENU                *" << endl;
	cout << "*****************************************************" << endl;
	cin >> choiceFood;
	switch (choiceFood)
	{
	case '1':
	{
		cout << "Excellent choice Sir/ma'am/other bon jore. I personally love the Frog, bon jore" << endl;
		subTotal = subTotal + frog;
		money = money - frog;
		x++;//moves storage place over one
		c[x] = 4;//stores the item ordered
		choiceDrink = 0;
		Sleep(1500);
		system("CLS");
		menu();
		break;
	}
	case '2':
	{
		cout << "Excellent choice Sir/ma'am bon jore. I personally love the Bison, bon jore" << endl;
		subTotal = subTotal + bison;
		money = money - bison;
		x++;//moves storage place over one
		c[x] = 5;//stores the item ordered
		Sleep(1500);
		system("CLS");
		menu();
		break;
	}
	case '3':
	{
		cout << "Excellent choice Sir/ma'am bon jore. I personally love the Armadillo, bon jore" << endl;
		subTotal = subTotal + armadillo;
		money = money - armadillo;
		x++;//moves storage place over one
		c[x] = 6;//stores the item ordered
		Sleep(1500);
		system("CLS");
		menu();
		break;
	}
	case '4':
	{
		cout << "Excellent choice Sir/ma'am bon jore. I personally love the Duck, bon jore";
		subTotal = subTotal + duck;
		money = money - duck;
		x++;//moves storage place over one
		c[x] = 7;//stores the item ordered
		Sleep(1500);
		system("CLS");
		menu();
		break;
	}
	case '5':
	{
		system("CLS");
		menu();
	}
	default:
	{
		system("CLS");
		cout << "invalid input! Bon jore" << endl;
		food();
		break;
	}
	}//end switch
}
void dessert()
{
	system("CLS");
	cout << "What would you like to order, bon jore?" << endl;
	cout << "*****************************************************" << endl;
	cout << "*                  FOOD MENU                        *" << endl;
	cout << "*             1. BACON ICE CREAM         $" << fixed << setprecision(2) << setw(10) << baconIceCream << "*" << endl;
	cout << "*             2. CARMELIZED PIG EYES     $" << fixed << setprecision(2) << setw(10) << carmelizedPigEyes << "*" << endl;
	cout << "*             3. PEEP                    $" << fixed << setprecision(2) << setw(10) << peep << "*" << endl;
	cout << "*             4. FISH STICK CAKE         $" << fixed << setprecision(2) << setw(10) << fishStickCake << "*" << endl;
	cout << "*             5. MENU                               *" << endl;
	cout << "*****************************************************" << endl;
	cin >> choiceFood;
	switch (choiceFood)
	{
	case '1':
	{
		cout << "Excellent choice Sir/ma'am/other bon jore. I personally love the Bacon Ice Cream, bon jore" << endl;
		subTotal = subTotal + baconIceCream;
		money = money - baconIceCream;
		x++;//moves storage place over one
		c[x] = 8;//stores the item ordered
		choiceDrink = 0;
		Sleep(1500);
		system("CLS");
		menu();
		break;
	}
	case '2':
	{
		cout << "Excellent choice Sir/ma'am bon jore. I personally love the Carmelized Pig Eyes, bon jore" << endl;
		subTotal = subTotal + carmelizedPigEyes;
		money = money - carmelizedPigEyes;
		x++;//moves storage place over one
		c[x] = 9;//stores the item ordered
		Sleep(1500);
		system("CLS");
		menu();
		break;
	}
	case '3':
	{
		cout << "Excellent choice Sir/ma'am bon jore. I personally love the Peep, bon jore" << endl;
		subTotal = subTotal + peep;
		money = money - peep;
		x++;//moves storage place over one
		c[x] = 10;//stores the item ordered
		Sleep(1500);
		system("CLS");
		menu();
		break;
	}
	case '4':
	{
		cout << "Terrible choice Sir/ma'am bon jore. I personally hate the fish stick cake, bon jore";
		subTotal = subTotal + fishStickCake;
		money = money - fishStickCake;
		x++;//moves storage place over one
		c[x] = 11;//stores the item ordered
		Sleep(1500);
		system("CLS");
		menu();
		break;
	}
	case '5':
	{
		system("CLS");
		menu();
	}
	default:
	{
		system("CLS");
		cout << "invalid input! Bon jore" << endl;
		dessert();
		break;
	}
	}//end switch
}
void exit()
{
	char answer = ' ';
	int hold;

	cout << endl << "You are about to exit, are you sure, bon jore?";
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		exit(0);
	}
	else
		system("CLS");
	menu();//returns the user to menu
}
void pay()
{
	int y = 1;

	if (subTotal == 0)//checks if the user actually ordered anything
	{
		cout << "You didn't order anything, ya joik, bon jore";
		menu();
	}
	//checks if they overspent themselves
	else if (money < 0)
	{
		cout << "Waaaaaiiiiiit.... You don't have enough to pay for this, bon jore." << endl << "Looks like you doin the dishes bub bon jore.";
	}
	//prints itemized receipt based on c[x]
	else
	{
		system("CLS");
		cout << "**********************************************" << endl;
		//prints an item to the receipt as long as x doesn't equal 0
		while (x != 0)
		{
			//each if/else if checks which number is stored in c and prints the corresponding menu item to the reciept
			if (c[y] == 1)
			{
				cout << "*Duck Duck Duck                   " << fixed << setprecision(2) << "$" << setw(10) << duckx3 << "*" << endl;
				x--;
				y++;
			}
			else if (c[y] == 2)
			{
				cout << "*Bay of Pigs                      " << fixed << setprecision(2) << "$" << setw(10) << bayOfPigs << "*" << endl;
				x--;
				y++;
			}
			else if (c[y] == 3)
			{
				cout << "*Chicken Broth                    " << fixed << setprecision(2) << "$" << setw(10) << chickenBroth << "*" << endl;
				x--;
				y++;
			}
			else if (c[y] == 4)
			{
				cout << "*Duck                             " << fixed << setprecision(2) << "$" << setw(10) << duck << "*" << endl;
				x--;
				y++;
			}
			else if (c[y] == 5)
			{
				cout << "*Bison                            " << fixed << setprecision(2) << "$" << setw(10) << armadillo << "*" << endl;
				x--;
				y++;
			}
			else if (c[y] == 6)
			{
				cout << "*Armadillo                        " << fixed << setprecision(2) << "$" << setw(10) << bison << "*" << endl;
				x--;
				y++;
			}
			else if (c[y] == 7)
			{
				cout << "*Frog                             " << fixed << setprecision(2) << "$" << setw(10) << frog << "*" << endl;
				x--;
				y++;
			}
			else if (c[y] == 8)
			{
				cout << "*Bacon Ice Cream                  " << fixed << setprecision(2) << "$" << setw(10) << baconIceCream << "*" << endl;
				x--;
				y++;
			}
			else if (c[y] == 9)
			{
				cout << "*Carmelied Pig Eyes               " << fixed << setprecision(2) << "$" << setw(10) << carmelizedPigEyes << "*" << endl;
				x--;
				y++;
			}
			else if (c[y] == 10)
			{
				cout << "*Peep                             " << fixed << setprecision(2) << "$" << setw(10) << peep << "*" << endl;
				x--;
				y++;
			}
			else if (c[y] == 11)
			{
				cout << "*Fish Stick Cake                  " << fixed << setprecision(2) << "$" << setw(10) << fishStickCake << "*" << endl;
				x--;
				y++;
			}
		} //end while

		cout << "*Sub-total                        " << fixed << "$" << setprecision(2) << setw(10) << subTotal << "*" << endl;

		//calculates random tax
		srand(time(0));
		tax = rand() % 100;
		cout << "*Tax is                           " << setw(10) << tax << "%" << "*" << endl;
		tax = tax * 0.01;

		//calculates total
		fTotal = subTotal + subTotal * tax;
		cout << "*Total is                         " << fixed << setprecision(2) << "$" << setw(10) << fTotal << "*" << endl;
		cout << "**********************************************" << endl;

		money = money - fTotal;
		if (money < 0)
			cout << "Looks like you're doing dishes bub, bon jore.";

		cout << "Thanks for coming in, have a most bodacious day! Bon jore.";
	}//end else
}
void amount()
{
	cout << "Welcome to the Very Vegan Venue, where you can get the best meat in town, bon jore." << endl
		<< "How much money in dollars do you have with you today, bon jore?" << endl;
	cin >> money;
	cout << "Do you have any coupons today, bon jore? y/n ";
	cin >> coupon;
	if (coupon == 'y' || coupon == 'Y')
	{
		cout << "Oh no, I mean GOOD! Bon jore" << endl;
		coupons();
	}
	else
	{
		system("CLS");
		menu();
	}

}
void coupons()
{
	//coupon menu
	cout << "Which coupon do you have, bon jore?" << endl
		<< "***********************************************************" << endl
		<< "*                    1. %50 OFF BISON                     *" << endl
		<< "*                  2. %2 OFF YOUR ORDER                   *" << endl
		<< "* 3. IDIOT! YOU KNOW I DIDN'T MEAN TO SAY I HAD A COUPON  *" << endl
		<< "***********************************************************" << endl;
	cin >> couponChoice;
	if (couponChoice == 1)
	{
		cout << "Your coupon will be applied while to the menu momentarily, bon jore";
		bison = 0.10 * 0.5;//reduces the price of bison if the person uses this coupon
		Sleep(1500);
		system("CLS");
		menu();
	}
	else if (couponChoice == 2)
	{
		//changes the value of all menu items if the person uses this coupon
		cout << "Your coupon will be applied to the menu momentarily, bon jore";
		bayOfPigs = 10.0 * 0.98;
		duckx3 = 8.0 * 0.98;
		chickenBroth = 100.0 * 0.98;
		frog = 500.0 * 0.98;
		bison = 0.10 * 0.98;
		armadillo = 20.0 * 0.98;
		duck = 800.0 * 0.98;
		baconIceCream = 900.0 * 0.98;
		carmelizedPigEyes = 20.0 * 0.98;
		peep = 10000.0 * 0.98;
		fishStickCake = 10.0 * 0.98;
		Sleep(1500);
		system("CLS");//clears the screen
		menu();//returns to menu
	}
	else if (couponChoice == 3)
	{
		cout << "OK, bon jore";
		system("CLS");
		menu();
	}
	else
	{
		cout << "Invalid choice, bon jore";
		system("CLS");
		coupons();
	}

}
