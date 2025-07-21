#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include <iomanip>
using namespace std;

class  clsDeleteClientScreen : protected clsScreen
{

private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n______________________________\n";
        cout << "\nFirstName       : " << Client.getFirstName();
        cout << "\nLastName        : " << Client.getLastName();
        cout << "\nFullName        : " << Client.FullName();
        cout << "\nEmail           : " << Client.getEmail();
        cout << "\nPhone           : " << Client.getPhone();
        cout << "\nAccount Number  : " << Client.AccountNumber();
        cout << "\nPinCode         : " << Client.getPinCode();
        cout << "\nAccount Balance : " << Client.getAccountBalance();
        cout << "\n______________________________\n";
    }

public:

    static void ShowDeleteClientScreen()
    {
        if (!(CheckAccessRights(clsUser::enPermissions::enDeleteClient)))
        {
            return;     // this will exit the function and it will not be proceeded.
        }

        _DrawScreenHeader("\tDelete Client Screen");
        cout << "\nPlease enter account number: ";
        string AccountNumber;
        AccountNumber = clsInputValidate::ReadString();
        
        while (!(clsBankClient::IsClientExists(AccountNumber)))
        {
            cout << "\nClient has been not found.\nPlease try again with different account number: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        
        char UserAnswer = 'n';
        cout << "\nAre you sure you want to delete \'" << Client.FullName() << "\' ?\n";
        cin >> UserAnswer;
        if (toupper(UserAnswer) == 'Y')
        {
            if (Client.Delete())
            {
                cout << "\nClient deleted successfully.\n";
                _PrintClient(Client);
            }
            else
            {
                cout << "\nAn error has been ocurred. Client has not been deleted successfully.\n";
            }
        }
        else
        {
            cout << "\nDon't worrry! The operation has been canceled successfully!\n";
        }
        
    }

};