#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransactionsHistoryScreen.h"
using namespace std;

class  clsTransactionsScreen : protected clsScreen
{

private:
    
    enum enTransactionsMenuOptions {enDeposit = 1, enWithdraw = 2, enShowTotalBalances = 3, enTransfer = 4, enTransactionsHistory  = 5, enShowMainMenu = 6};

    static short _ReadTransactionsMenuOptions()
    {
        cout << endl << endl << setw(32) << left << "" << "what do you want to do?\n" << setw(32) << left << "" << "Please choice an option from 1 to 6: ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1,6);
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        // cout << "\nDeposit Screen will be here!\n";
        clsDepositScreen::ShowDepositScreen();
    }
    
    static void _ShowWithdrawScreen()
    {
        // cout << "\nWithdraw Screen will be here!\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        // cout << "\nTotal Balances Screen will be here!\n";
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransactionsHistoryScreen()
    {
        clsTransactionsHistoryScreen::ShowTransactionsHistoryScreen();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout <<"\n\nPress any key to go back to transactions menu.....";
        system("pause>0");
        ShowTransactionsMenu();
    }

    static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOptions)
    {
        switch (TransactionsMenuOptions)
        {
        case enTransactionsMenuOptions::enDeposit :
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenuOptions::enWithdraw :
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenuOptions::enShowTotalBalances :
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        
        case enTransactionsMenuOptions::enTransfer :
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        
        case enTransactionsMenuOptions::enTransactionsHistory :
        {
            system("cls");
            _ShowTransactionsHistoryScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenuOptions::enShowMainMenu :
        {
            // We won't code anything here, cuz it will return to main menu automatically
        }
        
        }
    }

public:

    static void ShowTransactionsMenu()
    {
        if (!(CheckAccessRights(clsUser::enPermissions::enTransactions)))
        {
            return;     // this will exit the function and it will not be proceeded.
        }

        system("cls");
        _DrawScreenHeader("\t    Transactions Screen");

        cout << "\n\n" << setw(48) << left << "" << "========================================================\n" ;
        cout << setw(48) << left << "" << "\t\t    Transactions Menu\n";
        cout << setw(48) << left << "" << "========================================================\n";
        cout << setw(42) << left << "" << "\t[1] Deposit." << endl;
        cout << setw(42) << left << "" << "\t[2] Withdraw." << endl;
        cout << setw(42) << left << "" << "\t[3] Total Balances." << endl;
        cout << setw(42) << left << "" << "\t[4] Transfer." << endl;
        cout << setw(42) << left << "" << "\t[5] Transactions History." << endl;
        cout << setw(42) << left << "" << "\t[6] Main Menu." << endl;
        cout << setw(48) << left << "" << "========================================================\n\n";

        _PerformTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsMenuOptions());
    }

};