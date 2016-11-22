#include <iostream>
using namespace std;

void sortArray(int[10]);

int valuePosition(int[10], int);

int main()
{
	int storage[10], checkValue;

	for (int i = 0; i <= 9; i++)
	{
		cout << "Please enter an integer and press [Enter]: ";
		cin >> storage[i];
	}
	sortArray(storage);

	cout << "Sorted array:" << endl;
	for (int j = 0; j <= sizeof(storage)/4 - 1; j++)
	{
		cout << storage[j] << ", ";
	}
	cout << endl;

	cout << "Please enter a number to search for and press [Enter]: ";
	cin >> checkValue;

	int location = valuePosition(storage, checkValue);
	if (location == -1)
	{
		cout << "Number not found" << endl;
	}
	else
	{
		cout << "Number found in position " << location << endl;
	}

	cout << "Press [Enter] to continue...";
	cin.ignore();
	cin.get();
	return 0;
}

void sortArray(int refArray[10])
{
	int temp = 0;
	for (int x = 0; x <= sizeof(refArray)/4 - 1; x++)
	{
		for (int y = 0; y <= sizeof(refArray)/4 - 1; y++)
		{
			if (refArray[x] < refArray[y])
			{
				temp = refArray[y];
				refArray[y] = refArray[x];
				refArray[x] = temp;
				break;
			}
		}
	}
}

int valuePosition(int refArray[10], int number)
{
	for (int a = 0; a <= sizeof(refArray)/4 - 1; a++)
	{
		if (refArray[a] == number)
			return a;
	}
	return -1;
}
