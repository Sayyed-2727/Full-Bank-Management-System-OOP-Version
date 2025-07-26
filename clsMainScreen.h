#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
using namespace std;


class clsMainScreen : protected clsScreen
{
private:

    enum enMainMenuOptions {enShowClientList = 1, enAddNewClient = 2, enDeleteClient = 3, enUpdateClientInfo = 4, enFindClient = 5, enTransactions = 6, enManageUsers = 7, enLoginRegisterHistory = 8, enCurrencyExchange = 9, enLogout = 10};

    static short _ReadMainMenuOption()
    {
        cout << endl << endl << setw(40) << left << "" << "what do you want to do?\n" << setw(40) << left << "" << "Please choice an option from 1 to 10: ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1,10);
        return Choice;
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClienList();
    }

    static void _ShowAddNewClientsScreen()
    {
        // cout << "\nClient List Screen Will be here...\n";
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        // cout << "\nClient List Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        // cout << "\nClient List Screen Will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientsScreen()
    {
        // cout << "\nClient List Screen Will be here...\n";
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenu()
    {
        // cout << "\nClient List Screen Will be here...\n";
        clsTransactionsScreen::ShowTransactionsMenu();
    }

    static void _ShowManageUsersMenu()
    {
        // cout << "\nClient List Screen Will be here...\n";
        clsManageUsersScreen::ShowManageUsersMenu();
    }

    // static void _ShowEndScreen()
    // {
    //     cout << "\nClient List Screen Will be here...\n";
    // }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeMainScreen::ShowCurrencyExchangeMainMenu();
    }

    static void _Logout()
    {
        cout << "\n\n\nLogging out......" << flush;
        Sleep(1500);
        CurrentUser = clsUser::Find("","");
        // Then it will go back to main function
        // We need to add the log in screen again to can log in again
        // clsLoginScreen::ShowLoginScreen();  => it's not allowed to put this func here, will give an error (circular Dependency)
    }

    static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case enMainMenuOptions::enShowClientList:
        {
            system("cls");
            _ShowAllClientsScreen();
            GoBackToMainMenue();
            break;
        }
        
        case enMainMenuOptions::enAddNewClient:
        {
            system("cls");
            _ShowAddNewClientsScreen();
            GoBackToMainMenue();
            break;
        }
        
        case enMainMenuOptions::enDeleteClient:
        {
            system("cls");
            _ShowDeleteClientScreen();
            GoBackToMainMenue();
            break;
        }
        
        case enMainMenuOptions::enUpdateClientInfo:
        {
            system("cls");
            _ShowUpdateClientScreen();
            GoBackToMainMenue();
            break;
        }
        
        case enMainMenuOptions::enFindClient:
        {
            system("cls");
            _ShowFindClientsScreen();
            GoBackToMainMenue();
            break;
        }
        
        case enMainMenuOptions::enTransactions:
        {
            system("cls");
            _ShowTransactionsMenu();
            GoBackToMainMenue();
            break;
        }
        
        case enMainMenuOptions::enManageUsers:
        {
            system("cls");
            _ShowManageUsersMenu();
            GoBackToMainMenue();
            break;
        }
        
        case enMainMenuOptions::enLoginRegisterHistory:
        {
            system("cls");
            _ShowLoginRegisterScreen();
            GoBackToMainMenue();
            break;
        }

        case enMainMenuOptions::enCurrencyExchange:
        {
            system("cls");
            _ShowCurrencyExchangeScreen();
            GoBackToMainMenue();
            break;
        }
        
        case enMainMenuOptions::enLogout:
        {
            system("cls");
            _Logout();
            // Login();
            break;
        }
        }

    }

public:

    static  void GoBackToMainMenue()
    {
        cout << endl << setw(32) << left << ""<<"Press any key to go back to Main Menue... ";
        system("pause>0");
        ShowMainMenu();
    }

    static void ShowMainMenu()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << "\n\n "<< setw(15) << left << "" << "\t\t\t===========================================================================" << endl;
        cout << setw(20) << left << ""<< "\t\t\t\t\t\t\tMain Menu" << endl;
        cout << setw(20) << left << ""<< "\t\t\t===========================================================================" << endl;
        cout << setw(20) << left << ""<< "\t\t\t[1] Show Client List." << endl;
        cout << setw(20) << left << ""<< "\t\t\t[2] Add New Client." << endl;
        cout << setw(20) << left << ""<< "\t\t\t[3] Delete Client." << endl;
        cout << setw(20) << left << ""<< "\t\t\t[4] Update Client Info." << endl;
        cout << setw(20) << left << ""<< "\t\t\t[5] Find Client." << endl;
        cout << setw(20) << left << ""<< "\t\t\t[6] Transactions." << endl;
        cout << setw(20) << left << ""<< "\t\t\t[7] Manage Users." << endl;
        cout << setw(20) << left << ""<< "\t\t\t[8] Login Register History." << endl;
        cout << setw(20) << left << ""<< "\t\t\t[9] Currency Exchange." << endl;
        cout << setw(20) << left << ""<< "\t\t\t[10] Logout." << endl;
        cout << setw(20) << left << ""<< "\t\t\t===========================================================================\n" << endl;

        _PerformMainMenuOption((enMainMenuOptions) _ReadMainMenuOption());
    }


};