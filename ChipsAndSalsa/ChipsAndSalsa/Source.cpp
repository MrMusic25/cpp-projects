#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string salsaTypes[] = { "Mild", "Medium", "Sweet", "Hot", "Zesty" };
	float salsaSales[sizeof(salsaTypes)], totalSales = 0;
	int highest = 0, lowest = 0;

	for (int i = 0; i <= sizeof(salsaTypes) - 1; i++)
	{
		cout << "Please enter the number of jars sold of " << salsaTypes[i] << " salsa: ";
		cin >> salsaSales[i];
	}

	cout << " Salsa   Jars Sold" << endl;
	for (int j = 0; j <= sizeof(salsaTypes) - 1; j++)
	{
		cout << setfill(' ') << setw(7) << right << salsaTypes[j];
		cout << "   ";
		cout << setfill(' ') << fixed << setw(2) << salsaSales[j];
		cout << endl;
	}

	for (int q = 0; q <= sizeof(salsaTypes) - 1; q++)
		totalSales += salsaSales[q];

	totalSales = totalSales / sizeof(salsaTypes);
	cout << " Average number of jars sold: ";
	cout << fixed << setw(2) << totalSales << endl;

	for (int m = 0; m <= sizeof(salsaTypes) - 1; m++)
	{
		for (int n = 0; n <= sizeof(salsaTypes) - 1; n++)
		{
			if (salsaSales[n] < salsaSales[highest])
			{
				highest = n;
				break;
			}
		}
	}

	for (int m = 0; m <= sizeof(salsaTypes) - 1; m++)
	{
		for (int n = 0; n <= sizeof(salsaTypes) - 1; n++)
		{
			if (salsaSales[n] > salsaSales[lowest])
			{
				lowest = n;
				break;
			}
		}
	}

	cout << "Lowest selling salsa: " << salsaTypes[highest] << endl;
	cout << "Highest selling salsa: " << salsaTypes[lowest] << endl;
	return 0;
}