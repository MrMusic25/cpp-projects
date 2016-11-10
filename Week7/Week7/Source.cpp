#include <iostream>
using namespace std;

int largestFloat(float numbers[]);
int smallestFloat(float numbers[]);

int main()
{
	float numbers[10];

	for (int i = 0; i <= 9; i++)
	{
		cout << "Please enter a number and press [Enter]: ";
		cin >> numbers[i];
	}

	int smallest = smallestFloat(numbers), largest = largestFloat(numbers);

	cout << "The largest number is: " << numbers[largest] << endl;
	cout << "The smallest number is: " << numbers[smallest] << endl;

	cin.ignore();
	cin.get();
	return 0;
}

int largestFloat(float numbers[])
{
	int large = 0;
	for (int x = 0; x <= sizeof(numbers); x++)
	{
		if (numbers[x] > numbers[large])
			large = x;
	}
	return large;
}

int smallestFloat(float numbers[])
{
	int small = sizeof(numbers);
	for (int a = 0; a <= sizeof(numbers); a++)
	{
		if (numbers[a] < numbers[small])
			small = a;
	}
	return small;
}