#include <iostream>
#include <Windows.h> // Beep()
#include <cmath> // pow()

using namespace std;

int main() {
	// Init variables
	const int MAX_NUM_NOTES = 8 /* Number of notes/iterations */,
		      BEEP_LENGTH = 500 /* Default length of each beep in ms*/,
	          REF_NOTE_HZ = 440 /* Reference note, in Hz (440 = A) */;
	const double MAX_HZ_BOUNDRY = 30000.0,
		         MIN_HZ_BOUNDRY = 37.0; // Upper and lower boundries for successful sound
	double octave[MAX_NUM_NOTES], pitch[MAX_NUM_NOTES], hz[MAX_NUM_NOTES];

	// Program description
	cout << "This program will make " << MAX_NUM_NOTES << " beeps lasting " << BEEP_LENGTH << "ms, based on user input.\n"
		 << "User will be asked to enter octave and pitch of each note. They will be play successively.\n"
		 << "Notes can be entered as doubles or integers.\n\n";
	
	// Most work done in this loop
	for (int i = 0; i < MAX_NUM_NOTES; i++) {
		// Input the octave and pitch for each note
		cout << "Enter octave for note " << i + 1 << " and press [Enter]: ";
		cin >> octave[i];
		cout << "Enter pitch for note " << i + 1 << " and press [Enter]: ";
		cin >> pitch[i];

		// Perform calculation and check boundries
		// NOTE: Program exits if out of bounds
		hz[i] = REF_NOTE_HZ * pow(2, (octave[i] - 4) + (pitch[i] - 9) / 12);
		if (!(hz[i] >= MIN_HZ_BOUNDRY) && !(hz[i] <= MAX_HZ_BOUNDRY)) {
			cout << "Note " << i + 1 << " is out of bounds! Exiting... (Hz = " << hz[i] << ")]n";
			return 1;
		}
	}

	for (int j = 0; j < MAX_NUM_NOTES; j++) {
		cout << "\nNote " << j + 1 << ":\n  Octave: " << octave[j] << "\n  Pitch: " << pitch[j] << "\n  Hz: " << hz[j] << endl;
		Beep(hz[j], BEEP_LENGTH);
	}
	return 0;
}