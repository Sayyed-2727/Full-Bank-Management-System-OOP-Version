#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewUserScreen : protected clsScreen
{

private:

    static int _ReadPermissionstoSet()
    {
        char UserAnswer = 'n';
        int UserPermissions = 0;

        cout << "\nDo you want to give the user full access? ";
        cin >> UserAnswer;

        if (toupper(UserAnswer) == 'Y')
        {
            return -1;
        }
        
        cout << "\nDo you want to give access to:\n";
        
        cout << "\nShow Client List: (y/n) ";
        cin >> UserAnswer;
        if (toupper(UserAnswer) == 'Y')
        {
            UserPermissions += clsUser::enPermissions::enListClients;
        }
        
        cout << "\nAdd New Client: (y/n) ";
        cin >> UserAnswer;
        if (toupper(UserAnswer) == 'Y')
        {
            UserPermissions += clsUser::enPermissions::enAddNewClient;
        }
        
        cout << "\nDelete Client: (y/n) ";
        cin >> UserAnswer;
        if (toupper(UserAnswer) == 'Y')
        {
            UserPermissions += clsUser::enPermissions::enDeleteClient;
        }
        
        cout << "\nUpdate Client: (y/n) ";
        cin >> UserAnswer;
        if (toupper(UserAnswer) == 'Y')
        {
            UserPermissions += clsUser::enPermissions::enUpdateClient;
        }
        
        cout << "\nFind Client: (y/n) ";
        cin >> UserAnswer;
        if (toupper(UserAnswer) == 'Y')
        {
            UserPermissions += clsUser::enPermissions::enFindClient;
        }
        
        cout << "\nManage Transactions Menu: (y/n) ";
        cin >> UserAnswer;
        if (toupper(UserAnswer) == 'Y')
        {
            UserPermissions += clsUser::enPermissions::enTransactions;
        }
        
        cout << "\nManage Users: (y/n) ";
        cin >> UserAnswer;
        if (toupper(UserAnswer) == 'Y')
        {
            UserPermissions += clsUser::enPermissions::enManageUsers;
        }
        
        cout << "\nShow Login Register: (y/n) ";
        cin >> UserAnswer;
        if (toupper(UserAnswer) == 'Y')
        {
            UserPermissions += clsUser::enPermissions::enLoginRegister;
        }

        return UserPermissions;
        
    }
    
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter First Name: ";
        User.setFirstName(clsInputValidate::ReadString());
        
        cout << "\nEnter Last Name: ";
        User.setLastName(clsInputValidate::ReadString());
        
        cout << "\nEnter Email: ";
        User.setEmail(clsInputValidate::ReadString());
        
        cout << "\nEnter Phone: ";
        User.setPhone(clsInputValidate::ReadString());
        
        cout << "\nEnter Password: ";
        User.SetPassword(clsInputValidate::ReadString());

        cout << "\nEnter Permissions: ";
        User.SetPermissions(_ReadPermissionstoSet());
 
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

public:

    static void ShowAddNewUserScreen()
    {
        _DrawScreenHeader("\tAdd New User Screen");
        string UserName = "";

        cout << "\nPlease enter your UserName: ";
        UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExists(UserName))
        {
            cout << "\nUsername is already used.\nPlease choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(User);
        
        clsUser::enSaveResults SaveResult;
        SaveResult = User.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::enSaveFailedEmptyObject:
            cout <<"\nError!\nUser has not been saved for being empty. Please try again...";
            break;
            
        case clsUser::enSaveResults::enSaveFailedUserExists:
            cout <<"\nError!\nUser has not been saved because this Username exists. Please try again...";
            break;
        
        case clsUser::enSaveResults::enSaveSucceeded:
            cout <<"\n\n____________________________\n\nUser has been added successfully!\n";
            _PrintUser(User);
            break;
        }
    }

};