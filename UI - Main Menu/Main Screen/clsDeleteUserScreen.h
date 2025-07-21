#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include <iomanip>
using namespace std;

class  clsDeleteUserScreen : protected clsScreen
{

private:

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


public:

    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\tDelete User Screen");
        cout << "\nPlease enter Username: ";
        string UserName;
        UserName = clsInputValidate::ReadString();
        
        while (!(clsUser::IsUserExists(UserName)))
        {
            cout << "\nUser has been not found.\nPlease try again with different Username: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        
        char UserAnswer = 'n';
        cout << "\nAre you sure you want to delete \'" << User.getUserName() << "\' ?\n";
        cin >> UserAnswer;
        if (toupper(UserAnswer) == 'Y')
        {
            if (User.Delete())
            {
                cout << "\nUser deleted successfully.\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nAn error has been ocurred. User has not been deleted successfully.\n";
            }
        }
        else
        {
            cout << "\nDon't worrry! The operation has been canceled successfully!\n";
        }
        
    }

};