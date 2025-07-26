#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include <Windows.h>
#include "clsCurrency.h"
using namespace std;

    class  clsFindCurrencyScreen : protected clsScreen
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

public:

    enum enFindCurrencyOption {FindByCode = 1, FindByCountry =2};

    static clsCurrency PerformFindOption(enFindCurrencyOption FindCurrencyOption)
    {

        switch (FindCurrencyOption)
        {
        case enFindCurrencyOption::FindByCode:
        {
            string Code = clsString::UpperAllString(clsInputValidate::ReadString("\nPlease enter the currency code: "));
            while (!(clsCurrency::IsCurrencyExistbyCode(Code)))
            {
            cout << "\nCurrency is not found!\nPlease enter again: ";
            Code = clsInputValidate::ReadString();
            }

            clsCurrency Currency =  clsCurrency::FindByCode(Code);
            
            return Currency;
        }
        
        case enFindCurrencyOption::FindByCountry:
        {
            string country = clsString::UpperAllString(clsInputValidate::ReadString("\nPlease enter the country name: "));
            while (!(clsCurrency::IsCurrencyExistbyCountry(country)))
            {
                cout << "\nCurrency is not found!\nPlease enter again: ";
                country = clsInputValidate::ReadString();
            }
            
            clsCurrency Currency =  clsCurrency::FindByCountry(country);
            return Currency;
        }
        }
    }

    static short ReadFindCurrencyOptions(string message)
    {
        cout << message;
        short SearchOption = clsInputValidate::ReadShortNumberBetween(1,2);
        return SearchOption;
    }

    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\tFind Currency Screen");
        
        clsCurrency Currency = PerformFindOption((enFindCurrencyOption) ReadFindCurrencyOptions("\n\n\nDo you want to search by [1] Code or [2] Country? "));
        
        if (!Currency.IsEmpty())
        {
            cout << "\n\nSearching for a currency......" << flush;
            Sleep(3000);
            system("cls");
            _PrintCurrency(Currency);
        }
        else
        {
            "\n\nCurrency has not been found!\n";
        }
        
    }
};