#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Normally I like putting this stuff all in a header file, but I didn't want to lose points for doing something "ahead of the class"

enum Month { January = 1 /* Makes life easier */, February, March, April, May, June, July, August, September, October, November, December};
string displayMonth(int); // Easiest way I could think of to display date while simultaneously using an enum for months

struct airport
{
	int landingsPerMonth;
	int takeOffsPerMonth;
	int maxLandings; // Per month
	int leastLandings; // Per Month
};

double averageLandings(airport[]); // These definitions assume "for the year"
double averageTakeOffs(airport[]);
int totalLandings(airport[]);
int totalTakeOffs(airport[]);

void maxMinPlanesLanded(airport[]); // Used to display the max and min landings this year, with the month in which it occurred

int main()
{
	string studentName = "Kyle Krattiger", studentID = "900662666";
	cout << "Student Name:   " << studentName << endl;
	cout << "Student ID:     " << studentID << endl;
	cout << endl;

	airport myAirport[12]; // Main array of objects

	// Input data for each 'object'
	for (int x = January; x <= December; x++)
	{
		cout << "Enter the number of planes that landed in " << displayMonth(x) << ": ";
		cin >> myAirport[x - 1].landingsPerMonth; // x - 1 because enum and x start with 1, not 0

		cout << "Enter the number of planes that departed in " << displayMonth(x) << ": ";
		cin >> myAirport[x - 1].takeOffsPerMonth;

		cout << "Enter the greatest number of planes that landed on a single day in " << displayMonth(x) << ": ";
		cin >> myAirport[x - 1].maxLandings;

		cout << "Enter the least number of planes that landed on a single day in " << displayMonth(x) << ": ";
		cin >> myAirport[x - 1].leastLandings;

		cout << endl; // Formatting, seperation
	}

	// Now, display the averages and other info
	
	// Starting with averages
	cout << "The average monthly landings for the year is ";
	cout << fixed;
	cout << setprecision(2) << averageLandings(myAirport) << endl;

	cout << endl; // Formatting
	cout << "The average monthly departures for the year is ";
	cout << fixed;
	cout << setprecision(2) << averageTakeOffs(myAirport) << endl;

	// Now the totals
	cout << endl;
	cout << "The total landings for the year is " << totalLandings(myAirport) << endl;
	cout << endl;
	cout << "The total departures for the year is " << totalTakeOffs(myAirport) << endl;
	cout << endl;

	// Let the function handle the rest, then "exit"
	maxMinPlanesLanded(myAirport);

	cin.ignore();
	cin.get();
	return 0;
}

string displayMonth(int input)
{
	switch (input)
	{
	case January:
		return "January";
	case February: // No need for break statements becase the return negates them
		return "February";
	case March:
		return "March";
	case April:
		return "April";
	case May:
		return "May";
	case June:
		return "June";
	case July:
		return "July";
	case August:
		return "August";
	case September:
		return "September";
	case October:
		return "October";
	case November:
		return "November";
	case December:
		return "December";
	default:
		return "ERR: Bad use of enum";
	}
}

double averageLandings(airport input[12])
{
	double total = 0;
	for (int a = January; a <= December; a++)
	{
		total += input[a - 1].landingsPerMonth;
	}

	return total / 12;
}

double averageTakeOffs(airport input[12]) // Local variables, so copy+pasting the function works out
{
	double total = 0;
	for (int a = January; a <= December; a++)
	{
		total += input[a - 1].takeOffsPerMonth;
	}

	return total / 12;
}

int totalLandings(airport input[12])
{
	/* Technically, I could have copy+pasted the average function above and removed the /12 from the return value, but 
	   I didn't realize that until I had already finished this function. Oh, well! */
	int total = 0;
	for (int i = January; i <= December; i++)
	{
		total += input[i - 1].landingsPerMonth;
	}
	return total;
}

int totalTakeOffs(airport input[12])
{
	int total = 0;
	for (int i = January; i <= December; i++)
	{
		total += input[i - 1].takeOffsPerMonth;
	}
	return total;
}

void maxMinPlanesLanded(airport input[12])
{
	int max = January, min = December;

	// Determine max and min
	for (int q = January; q <= December; q++)
	{
		if (input[q - 1].maxLandings > input[max - 1].maxLandings)
			max = q;
		if (input[q - 1].leastLandings < input[min - 1].leastLandings) // Why waste cycles?
			min = q;
	}

	cout << "The greatest number of planes that landed in a single day is " << input[max - 1].maxLandings << " which occured in the month of " << displayMonth(max) << endl;
	cout << endl;
	cout << "The lease number of planes that landed in a single day is " << input[min - 1].leastLandings << " which occured in the month of " << displayMonth(min) << endl;
}