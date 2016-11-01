#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Prototypes
int readDials(char &d1, char &d2, char &d3, char &d4, char &d5, char &d6, char &d7, char &d8);

int toDigit(char &digit);

void acknowledgeCall(char d1, char d2, char d3, char d4, char d5, char d6, char d7, char d8);

void pauseProgram();

int main()
{
    string studentID = "9006662666", studentName = "Kyle Krattiger";

    cout << "Student ID:     " << studentID << endl;
    cout << "Student Name:   " << studentName << endl;
    cout << endl;

    // Begin main program
    char c1, c2, c3, c4, c5, c6, c7, c8;
    int flag = 0;

    do
    {
        cout << "Enter a phone number (Q to quit): ";
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6 >> c7 >> c8;

        if (c1 == 'q' || c1 == 'Q')
        {
            break;
        }

        switch (readDials(c1,c2,c3,c4,c5,c6,c7,c8))
        {
        case 0:
            acknowledgeCall(c1,c2,c3,c4,c5,c6,c7,c8);
            break;
        case -1:
            cout << "ERROR - An invalid character was entered" << endl;
            break;
        case -2:
            cout << "ERROR - Phone number cannot start with 0" << endl;
            break;
        case -3:
            cout << "ERROR - Phone number cannot start with 555" << endl;
            break;
        case -4:
            cout << "ERROR - Hyphen is not in the right position" << endl;
            break;
        }
    } while (flag == 0);

    pauseProgram();
    return 0;
}

void pauseProgram()
{
    cout << "Press [Enter] to continue...";
    cin.ignore();
    cin.get();
}

int readDials(char &d1, char &d2, char &d3, char &d4, char &d5, char &d6, char &d7, char &d8)
{
    if (toDigit(d1) != 0)
    {
        return -1;
    }
    if (toDigit(d2) != 0)
    {
        return -1;
    }
    if (toDigit(d3) != 0)
    {
        return -1;
    }
    if (toDigit(d4) != 0)
    {
        return -1;
    }
    if (toDigit(d5) != 0)
    {
        return -1;
    }
    if (toDigit(d6) != 0)
    {
        return -1;
    }
    if (toDigit(d7) != 0)
    {
        return -1;
    }
    if (toDigit(d8) != 0)
    {
        return -1;
    }

    if (d1 == 5 && d2 == 5 && d3 == 5)
    {
        return -3;
    }

    if (d1 == 0)
        return -2;
    if (d4 != '-')
        return -4;

    return 0;
}

int toDigit(char &digit)
{
    digit = toupper(digit);

    if ( ! isdigit(digit))
    {
        switch(digit)
        {
        case 'A':
        case 'B':
        case 'C':
            digit = 2;
            break;
        case 'D':
        case 'E':
        case 'F':
            digit = 3;
            break;
        case 'G':
        case 'H':
        case 'I':
            digit = 4;
            break;
        case 'J':
        case 'K':
        case 'L':
            digit = 5;
            break;
        case 'M':
        case 'N':
        case 'O':
            digit = 6;
            break;
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
            digit = 7;
            break;
        case 'T':
        case 'U':
        case 'V':
            digit = 8;
            break;
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            digit = 9;
            break;
        default:
            return -1;
        }
    }
    return 0;
}

void acknowledgeCall(char d1, char d2, char d3, char d4, char d5, char d6, char d7, char d8)
{
    cout << "Phone Number Dialed: ";
    cout << d1 << d2 << d3 << d4 << d5 << d6 << d7 << d8 << endl;
}
