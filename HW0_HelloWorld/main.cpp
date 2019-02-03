/*
Author:		Sean O'Dell
Class:		CSS 501
HW Name:	Hello World
Date:		9/30/18
*/

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

/*
Reasonable amount discussion:
 - The data type needed to be signed because negative values were allowed.
 - The data type needed to be larger than an int because otherwise the largest int could only have 
   a power value up to 1.  Since we are taking base and power values as int numerics, 1 did not seem reasonable.
 - Because negative power values need to be accepted, the result needs to allow for decimal values.
 - The data types fitting the above criteria are double and long double.  Either of these would be reasonable
   for this assignment given the instructions.  If provided with context on what these power value calculations
   were for, a determination between double and long double could have been made.  (if specified that only small
   integers would be used, the float data type might also be considered.)
The double type was chosen as the most applicable based on the information given.
*/

/*
I would like to see more 'tech' applied to public services to reduce error, and streamline processes.
*/
int main(int argc, const char * argv[]) {
	int baseNumber = 1;
	int powerNumber;
	double result;
	cout << "To quit this application enter '0' for the baseNumber." << endl;

	// Asks for user input and determines "power" result of the inputs
	while (true) {
		result = 1;
		cout << "What integer base number would you like to use? ";
		cin >> baseNumber;
		if (baseNumber == 0) break;
		cout << "What integer power number would you like to use? ";
		cin >> powerNumber;

		// determines result assuming a positive powerNumber
		for (int i = 0; i < abs(powerNumber); i++) {
			result *= baseNumber;
		}

		// handles negative powerNumber case
		if (powerNumber < 0) {
			result = 1 / result;
		}
		// handles power number is zero case
		else if (powerNumber == 0) {
			result = (baseNumber > 0) ? 1 : -1;
		}

		cout << to_string(baseNumber) + "^" + to_string(powerNumber) + " = ";
		cout << result << endl << endl;
	}

	return 0;
}