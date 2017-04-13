#include <iostream>
#include <fstream>

using namespace std;

// Prototypes for functions
int read(ifstream& inFile, int integers[], int arraySize);
void sort(int integers[], int itemCount);
int findSmallest(int integers[], int start, int end);
void swap(int integers[], int a, int b);
void print(ofstream& outFile, int integers[], int itemCount);

int main()
{
	int integers[8192]; // Maximum size
	const char inputFile[9] = "data.dat", outputFile[11] = "output.dat";
	ifstream inFile;
	ofstream outFile;
	
	inFile.open(inputFile);
	int itemCount = read(inFile, integers, sizeof(integers));
	inFile.close();
	
	sort(integers, itemCount);
	outFile.open(outputFile, ofstream::app); // Append
	print(outFile, integers, itemCount);
	outFile.close();

	return 0;
}

// Output file, array of integers, total number of integers in file
void print(ofstream& outFile, int integers[], int itemCount)
{
	for (int k = 0; k <= itemCount; k++)
	{
		outFile << integers[k] << endl;
	}
}

// Input file of integers, the array of integers (pass by reference), and size of array (legacy reasons)
// Returns number of integers found in file
int read(ifstream& inFile, int integers[], int arraySize)
{
	int j=0,n;
	while (inFile >> n)
	{
		integers[j] = n;
		j++;
	}
	return j;
}

// Array of integers, and the total number of integers from the input file
void sort(int integers[], int itemCount)
{
	int pos = 0;
	int smallpos;
	while (pos <= itemCount) {
		smallpos = findSmallest(integers, pos, itemCount);
		swap(integers, pos, smallpos);
		pos++;
	}
}

// Array of integers, start index, end index
// Returns the index with the smallest integer
int findSmallest(int integers[], int start, int end)
{
	int i = start, smallest = 0;
	for (; i <= end; i++)
	{
		if (integers[i] < integers[smallest])
			smallest = i;
	}
	return i;
}

// Array of integers, index of element being swapped, index of element to swap with
void swap(int integers[], int a, int b)
{
	int temp = integers[a];
	integers[a] = integers[b];
	integers[b] = temp;
}