/*
Business Requirements
	1) Read 2 numbers from user
	2) Provide 4 options: + - * /
		- Can’t divide by zero
	3) Input Validations
		- Once in reading 2 numbers
		- Once in reading target operation
	4) Retry when fail from a reasonable step
*/

#include <iostream>
using namespace std;



int main()
{
	// Declare + initialize the variables 
	double	dNum1 = 0;
	double	dNum2 = 0;
	double	dResult = 0;
	int		iChoice = 0;

	// Welcome msg when the programme open
	cout << "====================================\n";
	cout << "=== Welcome To Our Calculator V1 ===\n";
	cout << "====================================\n";
	
	// goto point re-back here
	CalculateStartingPoint:

	// get the numbers from the user
	cout << "\nPlease Enter 2 numbers: ";
	cin >> dNum1 >> dNum2;

	// Input Validation
	// indicates that the input was of the wrong type or format
	if (cin.fail())
	{
		cout << "\nYou should enter correct values\n";
		// clears the error state of the cin object
		cin.clear();
		// discards any remaining characters in the input buffer up to
		cin.ignore(1000, '\n');
		goto CalculateStartingPoint;
	}

	MenuStartingPoint:

	// Display the menu
	cout << "\n=== Menu Options ===\n";
	cout << "1) Sum" << endl;
	cout << "2) Substract" << endl;
	cout << "3) Multiply" << endl;
	cout << "4) Division" << endl;
	cout << "5) Enter 2 number again\n\n";

	// choice the operation
	cout << "Enter the choice: ";
	cin >> iChoice;

	// Input Validation
	// indicates that the input was of the wrong type or format
	if (cin.fail())
	{
		cout << "You should enter correct values\n";
		// clears the error state of the cin object
		cin.clear();
		// discards any remaining characters in the input buffer up to
		cin.ignore(1000, '\n');
		goto MenuStartingPoint;
	}

	if (!(1 <= iChoice && iChoice <= 5))
	{
		cout << "Not valid choice, enter number between 1 to 5\n";
		goto MenuStartingPoint;
	}
	else
	{
		if (iChoice == 1)
		{
			dResult = dNum1 + dNum2;
			cout << "1) sum has been choosen!" << endl;
			cout << dNum1 << " + " << dNum2 << " = " << dResult << endl;
		}
		else if (iChoice == 2)
		{
			dResult = dNum1 - dNum2;
			cout << "2) substract has been choosen!" << endl;
			cout << dNum1 << " - " << dNum2 << " = " << dResult << endl;
		}
		else if (iChoice == 3)
		{
			dResult = dNum1 * dNum2;
			cout << "3) multiply has been choosen!\n";
			cout << dNum1 << " * " << dNum2 << " = " << dResult << endl;
		}
		else if(iChoice == 4)
		{
			cout << "4) division has been choosen\n";
			if (dNum2 == 0.0)
			{
				cout << "Sorry, Can't divide by ZERO!!\n";
				goto CalculateStartingPoint;
			}
			else
			{
				dResult = dNum1 / dNum2;
				cout << dNum1 << " / " << dNum2 << " = " << dResult << endl;
			}
		}
		else
		{
			goto CalculateStartingPoint;
		}
	}
	return 0;
}



