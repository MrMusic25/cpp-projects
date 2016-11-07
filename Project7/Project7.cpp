#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string names[10];
	int scores[10];
	
	for (int i = 0; i <= 9; i++)
	{
		cout << "Enter Player Name (Q to quit): ";
		cin >> names[i];
		
		if (tolower(names[i]) == 'q')
			break;
		
		cout << "Enter score for " << names[i] << ": ";
		cin >> scores[i];
	}
}