#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include <iomanip>
#include <Windows.h>
using namespace std;

class  clsFindUserScreen : protected clsScreen
{

private:

public:

    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\tFind User Screen");
        string UserName = "";
        cout << "\nPlease Enter Username: ";
        UserName = clsInputValidate::ReadString();

        while (!(clsUser::IsUserExists(UserName)))
        {
            cout << "\nUsername is not found!\nPlease enter another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        
        if (!User.IsEmpty())
        {
            cout << "\n\nSearching for a user......" << flush;
            Sleep(3000);
            cout << "\n\nWe found the next user information: \n";
            _PrintUser(User);
        }
        else
        {
            "\n\nUser has not been found!\n";
        }
        
    }
};