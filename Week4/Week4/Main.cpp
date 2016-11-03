// Template file to be used for most C++ projects
// USAGE: Create a new project, and then copy over this Main.cpp file. Rename it accordingly
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/* * * * * * * * * * *
 *  Global Variables *
 * * * * * * * * * * */



/* * * * * * * * * * * *
 * Function Prototypes *
 * * * * * * * * * * * */

void pause() { cout << "Press [Enter] to continue..." << endl;  cin.ignore(); cin.get(); }

int main()
{
	/*int num;
	cout << "Enter a number and press [Enter]: ";
	cin >> num;

	/* if (num < 0) num *= -1;
	cout << "Absolute value of number is: " << num << endl; *
	
	if (num >= 1 && num <= 100) { cout << "Number is within range." << endl; }
	else { cout << "Number is outside of range." << endl; } */
	float sales, taxPercent, salesTax, totalSales;
	string location;

	cout << "Please enter the sales total: ";
	cin >> sales;
	cout << "Please enter location ([V]entura, [L]os Angeles, or [O]ther): ";
	cin >> location;

	if (location == "L" || location == "l" ) { taxPercent = 0.0975;  }
	else if (location == "V" || location == "v" ) { taxPercent = 0.085; }
	else { taxPercent = 0.0725; }

	salesTax = sales * taxPercent; 
	totalSales = sales + salesTax;

	cout << endl; //Formatting
	cout << fixed;
	cout << "Pre-Total: $" << setprecision(2) << sales << endl;
	cout << "Sales Tax (" << setprecision(3) << taxPercent * 100 << "%): $";
	cout << setprecision(2) << salesTax << endl;
	cout << "Total Sales: $" << setprecision(2) << totalSales << endl << endl;

	pause();
	return 0;
}

/* * * * * * *
 * Functions *
 * * * * * * */