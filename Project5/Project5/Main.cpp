#include <iostream>
#include <string>
using namespace std;

int main()
{
	char operatorr;
	float op1, op2;
	double sid = 9006662666;
	string sname = "Kyle Krattiger";

	cout << "Student Name:     " << sname << "\nStudent ID:     " << sid << "\n\n";

	cout << "Please input the first number: ";
	cin >> op1;

	cout << "Please input the operator: ";
	cin >> operatorr;

	cout << "Please enter the second number: ";
	cin >> op2;

	switch (operatorr)
	{
	case '+':
		cout << op1 << " + " << op2 << " = " << op1 + op2;
		break;
	case '-':
		cout << op1 << " - " << op2 << " = " << op1 - op2;
		break;
	case '*':
		cout << op1 << " * " << op2 << " = " << op1 * op2;
		break;
	case '/':
		cout << op1 << " / " << op2 << " = " << op1 / op2;
		break;
	default:
		cout << "Invalid operator!";
	}
	cout << endl;

	cout << "Press [Enter] to continue..." << endl;
	cin.ignore();
	cin.get();
	return 0;
}