#include <iostream>
using namespace std;

int main()
{
	//for (int i = 10; i >= 0; i--)
	//{
	//	cout << i << " ";
	//}
	//cout << endl;

	/*char a = '*';
	for (int j = 50; j >= 0; j--)
	{
		cout << a;
	}
	cout << endl;
	cout << "This is a header, using 50 characters of type '" << a << "'" << endl;
	for (int j = 50; j >= 0; j--)
	{
		cout << a;
	}*/

	char a;
	int i, flag = 0;
	cout << "Enter the character you would like repeated: ";
	cin >> a;

	cout << "Enter the number of times you would like this repeated for the header: ";
	cin >> i;

	do
	{
		for (int j = 0; j <= i; j++) { cout << a; }
		cout << endl;

		if (flag == 0) { cout << " Here is your header!" << endl; }
		flag++;
	} while (flag != 2);
	
	cin.ignore();
	cin.get();
	return 0;
}