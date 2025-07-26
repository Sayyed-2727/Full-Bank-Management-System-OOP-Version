#pragma once 
#include <iostream>
#include "clsUser.h"
#include "clsBankClient.h"
#include "Global.h"
#include "ClsDate.h"
using namespace std;


class clsScreen
{

protected:

    static void _DrawScreenHeader(string Title, string SubTitile = "")
    {
        cout << "\n" << setw(23) << left << "" << "\t\t\t\t________________________________________________________\n\n";
        cout << setw(23) << left << "" <<  "\t\t\t\t\t" << Title << "\n";
        if (SubTitile != "")
        {
            cout << "\n" << setw(23) << left << "" << "\t\t\t\t\t" << SubTitile << "\n";
        }
        
        cout << setw(23) << left << "" << "\t\t\t\t________________________________________________________" << "\n";
        ShowUserName();
        Show2dayDate();
    }

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

    static void _PrintClientShort(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n______________________________\n";
        cout << "\nFullName        : " << Client.FullName();
        cout << "\nAccount Number  : " << Client.AccountNumber();
        cout << "\nAccount Balance : " << Client.getAccountBalance();
        cout << "\n______________________________\n";
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n______________________________\n";
        cout << "\nFirstName       : " << User.getFirstName();
        cout << "\nLastName        : " << User.getLastName();
        cout << "\nFullName        : " << User.FullName();
        cout << "\nEmail           : " << User.getEmail();
        cout << "\nPhone           : " << User.getPhone();
        cout << "\nUsername        : " << User.getUserName();
        cout << "\nPassword        : " << User.GetPassword();
        cout << "\nPermissions     : " << User.GetPermissions();
        cout << "\n______________________________\n";
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t\t\t_______________________________________________________";
            cout << "\n\n\t\t\t\t\t\t\t\t\t   ACCESS DENIED!\n\n\t\t\t\t\t\t\t\tPlease contact your administrator....";
            cout << "\n\t\t\t\t\t\t\t_______________________________________________________\n\n\n\n\n\n";
            return false;
        }
        else
        {
            return true; 
        }
        
    }

    static void Show2dayDate()
    {
        cout << "\n" << setw(23) << left << "" << "\t\t\t\tDate: " <<clsDate::DateToString(clsDate());
    }

    static void ShowUserName()
    {
        cout << "\n" << setw(23) << left << "" << "\t\t\t\tUser: " <<CurrentUser.getUserName();
    }
};