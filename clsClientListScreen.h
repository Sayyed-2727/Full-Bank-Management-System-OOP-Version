#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsClientListScreen : protected clsScreen
{

private:

    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << "| " << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(25) << Client.FullName();
        cout << "| " << left << setw(20) << Client.getPhone();
        cout << "| " << left << setw(28) << Client.getEmail();
        cout << "| " << left << setw(15) << Client.getPinCode();
        cout << "| " << left << setw(15) << Client.getAccountBalance();
    }

public:

    static void ShowClienList()
    {

        if (!(CheckAccessRights(clsUser::enPermissions::enListClients)))
        {
            return;     // this will exit the function and it will not be proceeded.
        }
        
        system("cls");
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t   Client List Screen";
        string SubTitle = "\t   (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n____________________________________________________________________________________________________________________________\n\n";
        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(25) << "Client Name";
        cout << "| " << left << setw(20) << "Phone";
        cout << "| " << left << setw(28) << "Email";
        cout << "| " << left << setw(15) << "Pin Code";
        cout << "| " << left << setw(15) << "Balance";
        cout << "\n____________________________________________________________________________________________________________________________\n\n";

        if (vClients.size() == 0)
        {
            cout << "\t\t\t\tNo clients available in the system!" << endl;
        }
        else
        {
            for (clsBankClient c : vClients)
            {
                _PrintClientRecordLine(c);
                cout << endl;
            }
            
            cout << "\n__________________________________________________________________________________________________________________________\n\n";
        }
        
    }

};