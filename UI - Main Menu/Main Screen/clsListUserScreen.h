#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsListUserScreen : protected clsScreen
{

private:

    static void _PrintUserRecordLine(clsUser User)
    {
        cout << setw(10) << left << "" << "| " << left << setw(10) << User.getUserName();
        cout << setw(10) << left << "" << "| " << left << setw(35) << User.FullName();
        cout << setw(10) << left << "" << "| " << left << setw(30) << User.getEmail();
        cout << setw(10) << left << "" << "| " << left << setw(15) << User.getPhone();
        cout << setw(10) << left << "" << "| " << left << setw(5) << User.GetPassword();
        cout << setw(10) << left << "" << "| " << left << setw(15) << User.GetPermissions();

    }

public:

    static void ShowUsersList() 
    {
        system("cls");
        vector <clsUser> vUsers = clsUser::GetUsersList();
        string Title = "\t   User List Screen";
        string SubTitle = "\t   (" + to_string(vUsers.size()) + ") Users(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n" << setw(10) << left << "" << "_____________________________________________________________________________________________________________________________________________________________________\n\n";
        cout << setw(10) << left << "" << "| " << left << setw(10) << "User Name";
        cout << setw(10) << left << "" << "| " << left << setw(35) << "Full Name";
        cout << setw(10) << left << "" << "| " << left << setw(30) << "Email";
        cout << setw(10) << left << "" << "| " << left << setw(15) << "Phone";
        cout << setw(10) << left << "" << "| " << left << setw(5) << "Password";
        cout << setw(10) << left << "" << "| " << left << setw(15) << "Permissions";
        cout << "\n" << setw(10) << left << "" << "_____________________________________________________________________________________________________________________________________________________________________\n\n";

        if (vUsers.size() == 0)
        {
            cout << "\t\t\t\tNo Users available in the system!" << endl;
        }
        else
        {
            for (clsUser c : vUsers)
            {
                _PrintUserRecordLine(c);
                cout << endl;
            }
            
            cout << "\n" << setw(10) << left << "" << "_____________________________________________________________________________________________________________________________________________________________________\n\n";
        }
        
    }

};