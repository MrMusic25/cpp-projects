#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void inputData(string names[], int scores[]);

void displayPlayerData(string names[], int scores[]);

float calculateAverageScore(int scores[]);

void displayAboveAverage(string names[], int scores[], float average);

int main()
{
	string names[10];
	int scores[10];
	
	inputData(names, scores);
	displayPlayerData(names, scores);

	float average = calculateAverageScore(scores);
	
	cout << endl;
	cout << "Average Score: " << fixed << setw(2) << average << endl;
	cout << endl;

	displayAboveAverage(names, scores, average);

	cout << "Press [Enter] to continue...";
	cin.ignore();
	cin.get();
	return 0;
}

void inputData(string names[], int scores[])
{
	for (int i = 0; i <= 9; i++)
	{
		cout << "Enter Player Name (Q to quit): ";
		cin >> names[i]; // Arrays passed by reference by default, so this should work fine

		if (tolower(names[i][0]) == 'q' && names[i].size() < 2)
			return;

		cout << "Enter score for " << names[i] << ": ";
		cin >> scores[i];
	}
	return;
}

float calculateAverageScore(int scores[])
{
	int count = 0, total = 0;
	for (int q = 0; q <= count; q++)
	{
		if (scores[q] != 0 && scores[q] != NULL) // Doesn't rely on sizeof() this way
		{
			total = total + scores[q];
			count++;
		}
	}
	return total / count;
}

void displayPlayerData(string names[], int scores[])
{
	cout << setfill(' ') << setw(6) << right << "Name";
	cout << "   Score" << endl;

	for (int y = 0; y <= sizeof(scores); y++)
	{
		cout << setfill(' ') << setw(8) << left << names[y] << " ";
		cout << setfill(' ') << setw(6) << right << scores[y] << endl;
	}
}

void displayAboveAverage(string names[], int scores[], float average)
{
	cout << "Players who scored above average" << endl;
	cout << setfill(' ') << setw(6) << right << "Name";
	cout << "   Score" << endl;

	for (int q = 0; q <= sizeof(scores); q++)
	{
		if (scores[q] > average)
		{
			cout << setfill(' ') << setw(8) << left << names[q] << " ";
			cout << setfill(' ') << setw(6) << right << scores[q] << endl;
		}
	}
}