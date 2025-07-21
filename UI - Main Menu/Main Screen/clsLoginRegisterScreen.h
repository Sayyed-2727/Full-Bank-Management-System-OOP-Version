#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsLoginRegisterScreen : protected clsScreen
{

private:

    static void _PrintLoginRegisters(clsUser::stLoginRegisterRecord Record)
    {
        cout << setw(10) << left << "" << "| " << left << setw(50) << Record.DateTime;
        cout << setw(10) << left << "" << "| " << left << setw(25) << Record.Username;
        cout << setw(10) << left << "" << "| " << left << setw(25) << Record.Password;
        cout << setw(10) << left << "" << "| " << left << setw(15) << Record.Permissions;
    }

public:

    static void ShowLoginRegisterScreen() 
    {

        if (!(CheckAccessRights(clsUser::enPermissions::enLoginRegister)))
        {
            return;     // this will exit the function and it will not be proceeded.
        }

        system("cls");
        vector <clsUser::stLoginRegisterRecord> vRecords = clsUser::GetLoginRegisterList();
        string Title = "\t   Login Register List Screen";
        string SubTitle = "\t   (" + to_string(vRecords.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n" << setw(10) << left << "" << "_____________________________________________________________________________________________________________________________________________________________________\n\n";
        cout << setw(10) << left << "" << "| " << left << setw(50) << "Date/Time";
        cout << setw(10) << left << "" << "| " << left << setw(25) << "Username";
        cout << setw(10) << left << "" << "| " << left << setw(25) << "Password";
        cout << setw(10) << left << "" << "| " << left << setw(15) << "Permissions";
        cout << "\n" << setw(10) << left << "" << "_____________________________________________________________________________________________________________________________________________________________________\n\n";

        if (vRecords.size() == 0)
        {
            cout << "\t\t\t\tNo Login Registers available in the system!" << endl;
        }
        else
        {
            for (clsUser::stLoginRegisterRecord Record : vRecords)
            {
                _PrintLoginRegisters(Record);
                cout << endl;
            }
            
            cout << "\n" << setw(10) << left << "" << "_____________________________________________________________________________________________________________________________________________________________________\n\n";
        }
        
    }

};