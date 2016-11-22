#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int countDigits(string);
string printMoneyString(string);

int main()
{
	string input, finalString, studentID = "900662666", studentName = "Kyle Krattiger"; // Used for user input, verification
	int digits = 777;

	// Formalities...
	cout << "Student Name:    " << studentName << endl;
	cout << "Student ID:      " << studentID << endl;
	cout << endl;

	do
	{
		cout << "Please enter a number up to 12 digits long." << endl;
		cout << "This number may be positive or negative" << endl;
		cout << "and may include fractions (up to two decimal positions)" << endl;
		cout << "Sign and decimal dot(.) are not included in the digit count: ";
		cin >> input;

		digits = countDigits(input);
		if (digits > 12)
			cout << "Number must be 12 digits or less (excluding sign and decimal point)" << endl << endl;
	} while (digits > 12);

	finalString = printMoneyString(input);
	cout << "The currency value is:  " << finalString << endl;

	cin.ignore();
	cin.get();
	return 0;
}

int countDigits(string number)
{
	int count = 0;
	for (int i = 0; i <= number.length(); i++)
	{
		if (number[i] >= '0' && number[i] <= '9') // Only 0-9 should trigger this
			count++;
	}
	return count; // Inadvertently, this function also does error checking
}

string printMoneyString(string number)
{
	int digitCount = 0, // Keeps track of digits so it knows when to add a comma
		flag = 0; // Used to count decimal places 
	string finished = "$"; // Start with the dollar sign

	for (int x = 0; x <= number.length(); x++)
	{
		if (number[x] >= '0' && number[x] <= '9')
		{
			//      .append(<input>,<position>,<char_count>)
			finished.append(number,x,1);
			digitCount++;

			if (digitCount % 3 == 0)
				finished.append(","); // Double quotes, not single
		}
		else if (number[x] == '.')
		{
			if (finished.back() == ',') // Delete comma if there are no more digits to place after it
				finished.pop_back();
			finished.append(".");
			switch (number.length() - x)
			{
			case 1: // One digit after decimal
				finished.append(number, x + 1, 1);
				finished.append("0");
				break;
			case 2: // Two digits after decimal
				finished.append(number, x + 1, 2);
				break;
			case 0: // No digits, but decimal place
				finished.append("00");
				break;
			default: // >2 digits, give warning and append first two digits
				cout << "Only two decimal positions are allowed. Truncating the remainder ..." << endl;
				finished.append(number, x + 1, 2);
				break;
			}
			break;
		}
	}
	if (finished.back() == ',') // Delete comma if there are no more digits to place after it
		finished.pop_back(); // Easier to clean than to add more to the code
	if (finished[finished.length() - 3] != '.')
		finished.append(".00");
	
	return finished;
}