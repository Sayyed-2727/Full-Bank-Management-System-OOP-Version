#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <limits>
using namespace std;

void PrintClientRecordLine(clsBankClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber();
    cout << "| " << left << setw(25) << Client.FullName();
    cout << "| " << left << setw(20) << Client.getPhone();
    cout << "| " << left << setw(28) << Client.getEmail();
    cout << "| " << left << setw(15) << Client.getPinCode();
    cout << "| " << left << setw(15) << Client.getAccountBalance();
}

void ShowClienList()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") client(s)" << endl;
    cout << "\n_________________________________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(25) << "Client Name";
    cout << "| " << left << setw(20) << "Phone";
    cout << "| " << left << setw(28) << "Email";
    cout << "| " << left << setw(15) << "Pin Code";
    cout << "| " << left << setw(15) << "Balance";
    cout << "\n_________________________________________________________________________________________________________________________\n\n";

    if (vClients.size() == 0)
    {
        cout << "\t\t\t\tNo clients available in the system!" << endl;
    }
    else
    {
        for (clsBankClient c : vClients)
        {
            PrintClientRecordLine(c);
            cout << endl;
        }
        
        cout << "\n";
    }
    
    
}

int main()
{
    ShowClienList();

    return 0;
}