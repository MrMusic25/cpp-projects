// Template file to be used for most C++ projects
// USAGE: Create a new project, and then copy over this Main.cpp file. Rename it accordingly
#include <iostream>
#include <string>
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
	int num;
	cout << "Enter a number and press [Enter]: ";
	cin >> num;

	if (num < 0) num *= -1;
	cout << "Absolute value of number is: " << num << endl;
	pause();
	return 0;
}

/* * * * * * *
 * Functions *
 * * * * * * */