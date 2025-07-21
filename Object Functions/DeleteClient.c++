#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <limits>
using namespace std;


void DeleteClient()
{
    cout << "\nPlease enter account number: ";
    string AccountNumber;
    AccountNumber = clsInputValidate::ReadString();

    while (!(clsBankClient::IsClientExists(AccountNumber)))
    {
        cout << "\nClient has been not found.\nPlease try again with different account number: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    cout << "\nAre you sure you want to delete \'" << Client.FullName() << "\' ?\n";
    
    string UserAnswer;
    getline(cin >> ws, UserAnswer);

    if (UserAnswer == "yes" || UserAnswer == "y")
    {
        if (Client.Delete())
        {
            cout << "\nClient deleted successfully.\n";
            Client.Print();
        }
        else
        {
            cout << "\nAn error has been ocurred. Client has not been deleted successfully.";
        }
    }
    
    
}

int main()
{
    DeleteClient();


    return 0;
}