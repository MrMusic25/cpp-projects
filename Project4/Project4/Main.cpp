#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	float preConvert, postConvert;
	int choice;

	cout << "Student Name:   Kyle Krattiger\nStudent ID:     900662666" << endl;

	cout << "\nThis program converts temperatures from Fahrenheit to Celsius or Celsius to Fahrenheit\n\n";
	cout << "Type    1 to convert Fahrenheit to Celsius,\n        2 to convert Celsius to Fahrenheit:     ";
	cin >> choice;
	
	switch (choice)
	{
	case 1:
		cout << "Enter temperature in Fahrenheit:     ";
		cin >> preConvert;
		postConvert = (preConvert - 32) * 9 / 5;
		cout << fixed;
		cout << "In Celsius that's " << setprecision(3) << postConvert << endl;
		cout << endl;
		break;
	case 2:
		cout << "Enter temperature in Celsius:     ";
		cin >> preConvert;
		postConvert = preConvert * 9 / 5 + 32;
		cout << fixed;
		cout << "In Fahrenheit that's " << setprecision(3) << postConvert << endl;
		cout << endl;
		break;
	default:
		cout << "\nInvalid selection\n";
		break;
	}

	cout << "Press [Enter] to exit program...";
	cin.ignore();
	cin.get();
	return 0;
}