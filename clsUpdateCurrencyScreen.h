#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include <Windows.h>
#include "clsCurrency.h"
using namespace std;

class  clsUpdateCurrencyScreen : protected clsScreen
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

    static void UpdateCurrency(clsCurrency Currency)
    {
        float NewRate = 0;
        cout << "\n\n\nUpdate Currency Rate\n";
        cout << "__________________________\n\n";
        NewRate = clsInputValidate::ReadFloatNumber("Enter new rate: ");
        
        cout << "\n\n\nUpdating the rate...\nPlease hold on a second..." << flush;
        Sleep(3000);
        system("cls");
        cout << "\n\n\nCurrency rate has been updated successfully!.\n\n";
        cout << "\nOld Currency card rate:";
        cout << "\n_______________________";
        _PrintCurrency(Currency);
        
        Currency.UpdateRate(NewRate);
        
        cout << "\n\n\nNew Currency card rate:";
        cout << "\n_______________________";
        _PrintCurrency(Currency);
    }


public:

    static void ShowUpdateCurrencyRateScreen()
    {
        _DrawScreenHeader("\tUpdate Currency Screen");
        
        string CurrencyCode = clsString::UpperAllString(clsInputValidate::ReadString("\n\n\nPlease enter currency code: "));
        while (!(clsCurrency::IsCurrencyExistbyCode(CurrencyCode)))
        {
            cout << "\nCurrency is not found!\nPlease enter again: ";
            CurrencyCode = clsInputValidate::ReadString();
        }
        
        system("cls");
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        char UserAnswer = 'n';
        cout << "\n\nAre you sure you want to update the rate of this currency? (y/n) ";
        cin >> UserAnswer;

        if (toupper(UserAnswer) != 'Y')
        {
            cout << "\n\nDon't worry!\nThe operation has been cancelled successfully.\n\n";
        }
        else
        {            
            UpdateCurrency(Currency);
        }
        
    }

};