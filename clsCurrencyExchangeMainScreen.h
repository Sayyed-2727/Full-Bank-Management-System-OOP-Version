#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <string>
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;


class clsCurrencyExchangeMainScreen : protected clsScreen
{

private:

    static void _ShowListCurrenciesScreen()
    {
        // cout << "\nList currencies Screen Will be here....\n\n";
        clsListCurrenciesScreen::ShowCurrenciesList();
    }

    static void _ShowFindCurrenciesScreen()
    {
        // cout << "\nFind currencies Screen Will be here....\n\n";
        clsFindCurrencyScreen::ShowFindUserScreen();
    }

    static void _ShowUpdateRatesScreen()
    {
        // cout << "\nUpdate rates Screen Will be here....\n\n";
        clsUpdateCurrencyScreen::ShowUpdateCurrencyRateScreen();
    }
    
    static void _ShowCurrenciesCalculatorScreen()
    {
        // cout << "\nCurrency Calculator Screen Will be here....\n\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _GoBackToCurrencyExchangeScreen()
    {
        cout <<"\n\nPress any key to go back to Currency Exchange Menu.....";
        system("pause>0");
        ShowCurrencyExchangeMainMenu();
    }

    static short _ReadCurrencyExchangeMenuOptions()
    {
        cout << endl << endl << setw(48) << left << "" << "what do you want to do?\n" << setw(48) << left << "" << "Please choice an option from 1 to 5: ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1,5);
        return Choice;
    }

    enum enCurrencyExchangeMenuOptions {enListCurrencies = 1, enFindCurrencies = 2, enUpdateRate = 3, enCurrencyCalculator = 4, enShowMainMenu = 5};
    
    static void _PerformTransactionsMenuOption(enCurrencyExchangeMenuOptions CurrencyExchangeMenuOptions)
    {
        switch (CurrencyExchangeMenuOptions)
        {
        case enCurrencyExchangeMenuOptions::enListCurrencies :
        {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        }

        case enCurrencyExchangeMenuOptions::enFindCurrencies :
        {
            system("cls");
            _ShowFindCurrenciesScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        }

        case enCurrencyExchangeMenuOptions::enUpdateRate :
        {
            system("cls");
            _ShowUpdateRatesScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        }
        
        case enCurrencyExchangeMenuOptions::enCurrencyCalculator :
        {
            system("cls");
            _ShowCurrenciesCalculatorScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        }
        

        case enCurrencyExchangeMenuOptions::enShowMainMenu :
        {
            // We won't code anything here, cuz it will return to main menu automatically
        }
        
        }
    }


public:

    static void ShowCurrencyExchangeMainMenu()
    {
        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Main Screen");

        cout << "\n\n" << setw(48) << left << "" << "========================================================\n" ;
        cout << setw(48) << left << "" << "\t\t Currency Exchange Menu\n";
        cout << setw(48) << left << "" << "========================================================\n";
        cout << setw(42) << left << "" << "\t[1] List Currencies." << endl;
        cout << setw(42) << left << "" << "\t[2] Find Currency." << endl;
        cout << setw(42) << left << "" << "\t[3] Update Rate." << endl;
        cout << setw(42) << left << "" << "\t[4] Currency Calculator." << endl;
        cout << setw(42) << left << "" << "\t[5] Main Menu." << endl;
        cout << setw(48) << left << "" << "========================================================\n\n";

        _PerformTransactionsMenuOption((enCurrencyExchangeMenuOptions)_ReadCurrencyExchangeMenuOptions());

    }


};