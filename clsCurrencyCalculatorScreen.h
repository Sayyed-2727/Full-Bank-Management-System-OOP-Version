#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include <Windows.h>
#include "clsCurrency.h"
using namespace std;

class  clsCurrencyCalculatorScreen : protected clsScreen
{

private:

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\n\n\nCurrency Card:";
        cout << "\n______________________________\n";
        cout << "\nCountry     : " << Currency.Country();
        cout << "\nCode        : " << Currency.CurrencyCode();
        cout << "\nName        : " << Currency.CurrencyName();
        cout << "\nRate (1$)   : " << Currency.Rate();
        cout << "\n______________________________\n";
    }

    static clsCurrency _GetCurrency(string Message)
    {
        string CurrencyCode = clsString::UpperAllString(clsInputValidate::ReadString(Message));
        while (!(clsCurrency::IsCurrencyExistbyCode(CurrencyCode)))
        {
            cout << "\nCurrency is not found!\nPlease enter again: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;
    }

    static void _PrintCalculationResults(float Amount, clsCurrency CurrencyOrig, clsCurrency CurrencyDest)
    {
        // if Currency Destionation is USD: 
        cout << "\n\n\nPlease wait while completing the process......\n\n" << flush;
        cout << "\n\nConverting from the below currency to USD :";
        _PrintCurrency(CurrencyOrig);
        Sleep(3000);
        cout << "\n" << Amount << " " << CurrencyOrig.CurrencyCode() << " = " << CurrencyOrig.ConvertToUSD(Amount) << " " << "USD";
        
        // if Currency Destionation is not USD: 
        if (CurrencyDest.CurrencyCode() != "USD")
        {
            cout << "\n\n\nConverting from USD to '" << CurrencyDest.CurrencyCode() << "' ....." << flush;
            Sleep(1500);
            _PrintCurrency(CurrencyDest);
            cout << "\n" << Amount << " " << CurrencyOrig.CurrencyCode() << " = " << CurrencyOrig.ConvertToAnotherCurrency(Amount, CurrencyDest) << " " << CurrencyDest.CurrencyCode();
        }
        
        cout << "\n\n\nConvertion has been done successfully!\n";

    }

public:

    static void ShowCurrencyCalculatorScreen()
    {
        char UserAnswer = 'n';

        do
        {
        system("cls");
        _DrawScreenHeader("\tCurrency Calculator Screen");

        clsCurrency CurrencyOrig = _GetCurrency("\n\n\nPlease enter a currency you want to convert from: ");
        clsCurrency CurrencyDest = _GetCurrency("\nPlease enter a currency you want to convert To: ");
        float AmountToConvert = clsInputValidate::ReadFloatNumber("\nPlease enter the amount you want to convert: ");

        _PrintCalculationResults(AmountToConvert, CurrencyOrig, CurrencyDest);
    
        cout << "\n\nDo you want to perform another calculation? (y/n) ";
        cin >> UserAnswer;
        
        } while (toupper(UserAnswer) == 'Y');
    
    }

};