#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsCurrency.h"
#include <iomanip>

class clsListCurrenciesScreen : protected clsScreen
{

private:

    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << setw(10) << left << "" << "| " << left << setw(35)  << Currency.Country();
        cout << setw(10) << left << "" << "| " << left << setw(10)  << Currency.CurrencyCode();
        cout << setw(10) << left << "" << "| " << left << setw(40)  << Currency.CurrencyName();
        cout << setw(10) << left << "" << "| " << left << setw(15)  << Currency.Rate();
    }

public:

    static void ShowCurrenciesList() 
    {
        system("cls");
        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t   Currencies List Screen";
        string SubTitle = "\t   (" + to_string(vCurrencies.size()) + ") Currencies.";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\n" << setw(10) << left << "" << "_____________________________________________________________________________________________________________________________________________________________________\n\n";
        cout << setw(10) << left << "" << "| " << left << setw(35) << "Country";
        cout << setw(10) << left << "" << "| " << left << setw(10) << "Code";
        cout << setw(10) << left << "" << "| " << left << setw(40) << "Currency Name";
        cout << setw(10) << left << "" << "| " << left << setw(15) << "Rate";
        cout << "\n" << setw(10) << left << "" << "_____________________________________________________________________________________________________________________________________________________________________\n\n";

        if (vCurrencies.size() == 0)
        {
            cout << "\t\t\t\tNo Users available in the system!" << endl;
        }
        else
        {
            for (clsCurrency c : vCurrencies)
            {
                _PrintCurrencyRecordLine(c);
                cout << endl;
            }
            
            cout << "\n" << setw(10) << left << "" << "_____________________________________________________________________________________________________________________________________________________________________\n\n";
        }
        
    }

};