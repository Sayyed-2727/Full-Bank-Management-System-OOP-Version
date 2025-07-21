#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
using namespace std;


class clsTransactionsHistoryScreen : protected clsScreen
{

private:

    static void _PrintTransactionRecord(clsBankClient::stTransactionsHistory Transaction)
    {
        cout << setw(10) << left << "" << "| " << left << setw(20) << Transaction.DateTime;
        cout << setw(10) << left << "" << "| " << left << setw(5) << Transaction.SourceAccount;
        cout << setw(10) << left << "" << "| " << left << setw(5) << Transaction.DestinationAccouunt;
        cout << setw(10) << left << "" << "| " << left << setw(15) << Transaction.TransactionAmount;
        cout << setw(10) << left << "" << "| " << left << setw(15) << Transaction.SourceBalance;
        cout << setw(10) << left << "" << "| " << left << setw(15) << Transaction.DestinationBalannce;
        cout << setw(10) << left << "" << "| " << left << setw(10) << Transaction.Username;
    }

public:

    static void ShowTransactionsHistoryScreen()
    {
       
        system("cls");
        vector <clsBankClient::stTransactionsHistory> vTransactions = clsBankClient::GetTransactionsHistoryList();
        string Title = "\t   Transactions History Screen";
        string SubTitle = "\t   (" + to_string(vTransactions.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\n" << setw(10) << left << "" << "_____________________________________________________________________________________________________________________________________________________________________\n\n";
        cout << setw(10) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << setw(10) << left << "" << "| " << left << setw(5) << "S.Acc";
        cout << setw(10) << left << "" << "| " << left << setw(5) << "D.Acc";
        cout << setw(10) << left << "" << "| " << left << setw(15) << "Amount";
        cout << setw(10) << left << "" << "| " << left << setw(15) << "S.Balance";
        cout << setw(10) << left << "" << "| " << left << setw(15) << "D.Balance";
        cout << setw(10) << left << "" << "| " << left << setw(10) << "Username";
        cout << "\n" << setw(10) << left << "" << "_____________________________________________________________________________________________________________________________________________________________________\n\n";

        if (vTransactions.size() == 0)
        {
            cout << "\t\t\t\tNo Transactions History available in the system!" << endl;
        }
        else
        {
            for (clsBankClient::stTransactionsHistory Transaction : vTransactions)
            {
                _PrintTransactionRecord(Transaction);
                cout << endl;
            }
            
            cout << "\n" << setw(10) << left << "" << "_____________________________________________________________________________________________________________________________________________________________________\n\n";
        }
        
    }


};