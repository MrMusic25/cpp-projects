#include <iostream>
#include <fstream>

using namespace std;

// Prototypes for functions
int read(fstream file, int integers, int arraySize);
void sort(int integers, int itemCount);
int findSmallest(int integers, int start, int end);
void swap(int integers, int a, int b);
void print(fstream file, int integers, int itemCount);

int main()
{
	int integers[8192]; // Maximum size
	const char inputFile[9] = "data.dat", outputFile[11] = "output.dat";
	fstream inFile(inputFile), outFile(outputFile);
	
	return 0;
}

// Output file, array of integers, total number of integers in file
void print(ostream file, int integers[], int itemCount)
{

}

// Input file of integers, the array of integers (pass by reference), and size of array (legacy reasons)
// Returns number of integers found in file
int read(istream file, int integers[], int arraySize)
{

}

// Array of integers, and the total number of integers from the input file
void sort(int integers[], int itemCount)
{

}

// Array of integers, start index, end index
// Returns the index with the smallest integer
int findSmallest(int integers[], int start, int end)
{

}

// Array of integers, index of element being swapped, index of element to swap with
void swap(int integers[], int a, int b)
{

}