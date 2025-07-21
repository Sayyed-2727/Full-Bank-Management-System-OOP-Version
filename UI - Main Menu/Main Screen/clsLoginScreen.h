#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsMainScreen.h"
using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

    static bool _Login()
    {
        bool LoginFailed = false;
        short UserTrials = 3;
        string UserName, Password;
        do
        {
            system("cls");
            _DrawScreenHeader("\t     Login Screen");   
          
            if (LoginFailed)
            {
                cout << "\n\nInvalid Username/Password!\n";
                --UserTrials;
                cout << "You have " << UserTrials << " trials left to login.\n";
            }
            
            if (UserTrials == 0)
            {
                cout << "\n\nSystem has been locked after 3 failed trial(s) to login. Please try again later...\n\n";
                return false;
            }

            UserName = clsInputValidate::ReadString("\nEnter Username: ");
            Password = clsInputValidate::ReadString("\nEnter Password: ");

            CurrentUser = clsUser::Find(UserName, Password);

            LoginFailed = CurrentUser.IsEmpty();
            
        } while (LoginFailed && UserTrials >0);

        cout << "\n\n\nLogging in......" << flush;
        Sleep(1500);

        CurrentUser.LoginRegister();
        clsMainScreen::ShowMainMenu();
        return true;
        
    }

    static bool _CheckUsernamePassword(string Username, string Password)
    {
        clsUser User = clsUser::Find(Username);

        if (User.getUserName() == Username && User.GetPassword() == Password)
        {
            return true;
        }

        return false;
        
    }

public:

    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t     Login Screen");   
        return _Login();
    }

};