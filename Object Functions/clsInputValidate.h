#pragma once
#include "ClsDate.h"
#include <iostream>
#include <string>
#include <limits> // Add this line

using namespace std;

class clsInputValidate
{

public:

    static bool IsNumberBetween(short Number, short From, short To)
    {
        return Number >= From && Number <= To;
    }
    
    static bool IsNumberBetween(int Number, int From, int To)
    {
        return Number >= From && Number <= To;
    }
    
    static bool IsNumberBetween(float Number, float From, float To)
    {
        return Number >= From && Number <= To;
    }
    
    static bool IsNumberBetween(double Number, double From, double To)
    {
        return Number >= From && Number <= To;
    }

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        // Date >= From && Date <= To
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) && (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
        {
            return true;
        }
        
        // Date >= To && Dte <= From
        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) && (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
        {
            return true;
        }

        // If he reaches here, then none of the above conditions is true.
        return false;
    }

    static string ReadString()
    {
        string s1;
        // Usage of std::ws will extract allthe whitespace character

        getline(cin >> ws, s1);

        return s1;
    }

    static int ReadIntNumber(string ErrorMessage = "Invlaid Number. Please enter again:\n")
    {
        int x;
        while (!(cin >> x))
        {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << ErrorMessage ;
        }

        return x;
    }
    
    static float ReadFloatNumber(string ErrorMessage = "Invlaid Number. Please enter again:\n")
    {
        float x;
        while (!(cin >> x))
        {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << ErrorMessage ;
        }

        return x;
    }

    static double ReadDblNumber(string ErrorMessage = "Invlaid Number. Please enter again:\n")
    {
        double x;
        while (!(cin >> x))
        {
            cout << ErrorMessage ;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
        }

        return x;
    }

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within the range. Please enter again:\n")
    {
        int x = ReadIntNumber();

        while (! IsNumberBetween(x, From, To))
        {
            cout << ErrorMessage ;
            x = ReadIntNumber();        
        }
        return x;
    }

    static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within the range. Please enter again:\n")
    {
        double x = ReadDblNumber();

        while (! IsNumberBetween(x, From, To))
        {
            cout << ErrorMessage ;
            x = ReadDblNumber();        
        }
        return x;
    }

    static bool IsValidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }
    
};