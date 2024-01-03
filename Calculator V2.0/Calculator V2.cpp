#include <iostream>
using namespace std;

// Functions Declaration
void read2Numbers(double& dNum1, double& dNum2);
int Menu();
bool sum(double dNum1, double dNum2, double& dResult);
bool sub(double dNum1, double dNum2, double& dResult);
bool mul(double dNum1, double dNum2, double& dResult);
bool div(double dNum1, double dNum2, double& dResult);
void runCalculator();

int main()
{
    cout << "\t\t\t *** Welcome To Calaculator V2.0 ***\n\n";
    runCalculator();

}

// Read 2 Number From The User
void read2Numbers(double& dNum1, double& dNum2)
{
    while (true)
    {
        dNum1 = dNum2 = 0;

        cout << "\nPlease Enter 2 Numbers: ";
        cin >> dNum1 >> dNum2;

        if (cin.fail())
        {
            cout << "\nPlease Enter Correct Values\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
            break;
    }
    
}

// Display The Menu
int Menu()
{
    while (true)
    {
        int      iChoice = 0;
        cout << "\n*** Choice The Operation ***\n";
        cout << "1- Enter 1 For Sum       (+)\n";
        cout << "2- Enter 2 For Substract (-)\n";
        cout << "3- Enter 3 For Multiply  (*)\n";
        cout << "4- Enter 4 For Division  (/)\n";
        cout << "5- Enter 5 For Repeat\n\n";

        cout << "Enter The Choice Number: ";
        cin >> iChoice;

        if (cin.fail())
        {
            cout << "\nPlease Enter Correct Values\n";
            cin.clear();
            cin.ignore(1000, '\n');
            return Menu(); // if there are a problem repeat the function again
        }
        return iChoice;
    }

    
}

// Sum Number Which User Input It
bool sum(double dNum1, double dNum2, double& dResult)
{
    dResult = dNum1 + dNum2;
    return true;
}

// Substract Number Which User Input It
bool sub(double dNum1, double dNum2, double& dResult)
{
    dResult = dNum1 - dNum2;
    return true;
}

// Multiply Number Which User Input It
bool mul(double dNum1, double dNum2, double& dResult)
{
    dResult = dNum1 * dNum2;
    return true;
}

// Division Number Which User Input It
bool div(double dNum1, double dNum2, double& dResult)
{
    if (dNum2 == 0.0)
    {
        cout << "Can't Divide by ZERO\n";
        return false;
    }
    else
        dResult = dNum1 / dNum2;
    return true;
}

// Invoked All Function Here And Invoke this Function In The Main Only Once
void runCalculator()
{
    double      dNum1 = 0.0, dNum2 = 0.0, dResult = 0.0;
    int         iChoice = 0;
    bool        bFinish = false;

    while (!bFinish) // 
    {
        read2Numbers(dNum1, dNum2);
        iChoice = Menu();


        if (iChoice == 5)    continue;

        if (iChoice == 1)
            bFinish = sum(dNum1, dNum2, dResult);
        else if(iChoice == 2)
            bFinish = bFinish = sum(dNum1, dNum2, dResult);
        else if (iChoice == 3)
            bFinish = mul(dNum1, dNum2, dResult);
        else if (iChoice == 4)
            bFinish = div(dNum1, dNum2, dResult);

        if (bFinish)
            cout << "Result Of Operation = " << dResult << "\n";
    }
}
