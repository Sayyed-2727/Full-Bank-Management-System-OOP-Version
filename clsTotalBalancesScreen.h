#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
#include "ClsUtil.h"
using namespace std;


class clsTotalBalancesScreen : protected clsScreen
{

private:

    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << "| " << left << setw(20) << Client.AccountNumber();
        cout << "| " << left << setw(30) << Client.FullName();
        cout << "| " << left << setw(20) << Client.getAccountBalance();
    }


public:

    static void ShowTotalBalancesScreen()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") client(s)" << endl;
        cout << "\n_________________________________________________________________________________________________________________________\n\n";
        cout << "| " << left << setw(20) << "Account Number";
        cout << "| " << left << setw(30) << "Client Name";
        cout << "| " << left << setw(20) << "Balance";
        cout << "\n_________________________________________________________________________________________________________________________\n\n";

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
        {
            cout << "\t\t\t\tNo clients available in the system!" << endl;
        }
        else
        {
            for (clsBankClient c : vClients)
            {
                _PrintClientRecordBalanceLine(c);
                cout << endl;
            }
            
            cout << "______________________________________________________________________________________________________________________\n" << endl;
            cout << "\t\t\t\t\t\t\t\t\t Total balances = " << TotalBalances << endl;
            cout << "\t\t\t\t\t\t\t\t\t ( " << ClsUtil::NumberToText(TotalBalances) << ")\n" << endl; 
        }
    }


};