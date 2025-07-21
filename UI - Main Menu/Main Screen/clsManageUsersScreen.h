#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListUserScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;

class  clsManageUsersScreen : protected clsScreen
{

private:
    
    enum enManageUsersMenuOptions {enListUsers = 1, enAddNewUser = 2, enDeleteUser = 3, enUpdateUser = 4, enFindUser = 5, enMainMenu = 6};

    static short _ReadManageUsersMenuOptions()
    {
        cout << endl << endl << setw(32) << left << "" << "what do you want to do?\n" << setw(32) << left << "" << "Please choice an option from 1 to 6: ";
        return clsInputValidate::ReadShortNumberBetween(1,6);
    }

    static void PerformManageUsersMenuOption(enManageUsersMenuOptions ManageUsersMenuOptions)
    {
        switch (ManageUsersMenuOptions)
        {
        case enManageUsersMenuOptions::enListUsers:
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        
        case enManageUsersMenuOptions::enAddNewUser:
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenu();
            break;
        
        case enManageUsersMenuOptions::enDeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenu();
            break;
        
        case enManageUsersMenuOptions::enUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenu();
            break;
        
        case enManageUsersMenuOptions::enFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;
        
        case enManageUsersMenuOptions::enMainMenu:
            /* We'll do nothing here as the function will return to the main menu automatically if there's no code here. */
            break;
        }
    }

    static void _GoBackToManageUsersMenu()
    {
        cout << "\n\nPlease press any key to go back to manage users menu....";
        system("pause>0");
        ShowManageUsersMenu();
    }

    // Firstly we'll make what called (stubs) => design first every function without any deployment to test the flow first

    static void _ShowListUsersScreen()
    {
        // cout << "\nList Users Screen Will Be Here.....";
        clsListUserScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        // cout << "\nAdd New User Screen Will Be Here.....";
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        // cout << "\nDelete User Screen Will Be Here.....";
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        // cout << "\nUpdate User Screen Will Be Here.....";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }
    
    static void _ShowFindUserScreen()
    {
        // cout << "\nFind User Screen Will Be Here.....";
        clsFindUserScreen::ShowFindUserScreen();
    }

public:

    static void ShowManageUsersMenu()
    {

        if (!(CheckAccessRights(clsUser::enPermissions::enManageUsers)))
        {
            return;     // this will exit the function and it will not be proceeded.
        }

        system("cls");
        _DrawScreenHeader("\t   Manage Users Screen");

        cout <<  "\n\n" << setw(48) << left << "" << "========================================================\n" ;
        cout << setw(48) << left << "" << "\t\t    Manage Users Menu\n";
        cout << setw(48) << left << "" << "========================================================\n";
        cout << setw(42) << left << "" << "\t[1] List Users.\n";
        cout << setw(42) << left << "" << "\t[2] Add New User.\n";
        cout << setw(42) << left << "" << "\t[3] Delete User.\n";
        cout << setw(42) << left << "" << "\t[4] Update User.\n";
        cout << setw(42) << left << "" << "\t[5] Find User.\n";
        cout << setw(42) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(48) << left << "" << "========================================================\n\n";

        PerformManageUsersMenuOption((enManageUsersMenuOptions) _ReadManageUsersMenuOptions());
    }

};