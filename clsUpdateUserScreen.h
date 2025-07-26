#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include <iomanip>
using namespace std;

class  clsUpdateUserScreen : protected clsScreen
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


public:

    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter First Name: ";
        Client.setFirstName(clsInputValidate::ReadString());
        
        cout << "\nEnter Last Name: ";
        Client.setLastName(clsInputValidate::ReadString());
        
        cout << "\nEnter Email: ";
        Client.setEmail(clsInputValidate::ReadString());
        
        cout << "\nEnter Phone: ";
        Client.setPhone(clsInputValidate::ReadString());
        
        cout << "\nEnter PinCode: ";
        Client.setPinCode(clsInputValidate::ReadString());
        
        cout << "\nEnter Account Balance: ";
        Client.setAccountBalance(clsInputValidate::ReadFloatNumber());
    }

    enum enChoiceToUpdate {enFirstName = 1, enLastName = 2, enEmail = 3, enPhone = 4, enPassword = 5, enPermissions = 6};

    static void ChoiceToUpdate(clsUser& User)
    {
        char UserAnswer = 'n';
        short UserChoice;
        cout << "\nDo you want to Modify the whole User information? (y or n)\n";
        cin >> UserAnswer;

        if (toupper(UserAnswer) == 'Y')
        {
            _ReadUserInfo(User);
        }
        else
        {
            cout << "\nPlease choice the option you desire modifiy:\n";
            cout << "\n\t[1] First Name";
            cout << "\n\t[2] Last Name";
            cout << "\n\t[3] Email";
            cout << "\n\t[4] Phone Number";
            cout << "\n\t[5] Password";
            cout << "\n\t[6] Permissions\n\n";
            cin >> UserChoice;

            switch (UserChoice)
            {
            case enChoiceToUpdate::enFirstName:
                User.setFirstName(clsInputValidate::ReadString("\nPlease enter your First Name: "));
                break;
            
            case enChoiceToUpdate::enLastName:
                User.setLastName(clsInputValidate::ReadString("\nPlease enter your Last Name: "));
                break;
            
            case enChoiceToUpdate::enEmail:
                User.setEmail(clsInputValidate::ReadString("\nPlease enter your Email: "));
                break;
            
            case enChoiceToUpdate::enPhone:
                User.setPhone(clsInputValidate::ReadString("\nPlease enter your Phone: "));
                break;
            
            case enChoiceToUpdate::enPassword:
                User.SetPassword(clsInputValidate::ReadString("\nPlease enter your Password: "));
                break;
            
            
            case enChoiceToUpdate::enPermissions:
                User.SetPermissions(_ReadPermissionstoSet());
                break;
            }
        }
        
        
    }

    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\tUpdate User Screen");
        string UserName = "";
        cout << "\nPlease Enter Username: ";
        UserName = clsInputValidate::ReadString();

        while (!(clsUser::IsUserExists(UserName)))
        {
            cout << "\nUsername is not found!\nPlease enter another Username: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        cout << "\nWe found the next user information: \n";
        _PrintUser(User);

        cout << "\n\nUpdating User info....\n\n";
        cout << "___________________________________\n";

        // Add a method that could edit just a single member of user choice.
        
        ChoiceToUpdate(User);
        
        clsUser::enSaveResults SaveResult;
        SaveResult = User.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::enSaveSucceeded:
            cout << "\nUser Updated Successfully.\n";
            _PrintUser(User);
            break;
        
        case clsUser::enSaveResults::enSaveFailedEmptyObject :
            cout << "\nAn error has ocurred! The client has not been save for being empty.\n";
            break;
        
        }
        
    }

};