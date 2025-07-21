#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include <iomanip>
#include <Windows.h>
using namespace std;

class  clsFindClientScreen : protected clsScreen
{

private:

   

public:

    static void ShowFindClientScreen()
    {

        if (!(CheckAccessRights(clsUser::enPermissions::enFindClient)))
        {
            return;     // this will exit the function and it will not be proceeded.
        }

        _DrawScreenHeader("\tFind Client Screen");
        string AccountNumber = "";
        cout << "\nPlease Enter client account number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!(clsBankClient::IsClientExists(AccountNumber)))
        {
            cout << "\nAccount Number is not found!\nPlease enter another account number: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        
        if (!Client.IsEmpty())
        {
            cout << "\n\nSearching for a client......" << flush;
            Sleep(3000);
            cout << "\n\nWe found the next client information: \n";
            _PrintClient(Client);
        }
        else
        {
            "\n\nClient has not been found!\n";
        }
        
    }
};