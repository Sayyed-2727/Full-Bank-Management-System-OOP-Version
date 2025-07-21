#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

class  clsAddNewClientScreen : protected clsScreen
{

private:

    
    static void _ReadClientInfo(clsBankClient& Client)
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

public:

    static void ShowAddNewClientScreen()
    {

        if (!(CheckAccessRights(clsUser::enPermissions::enAddNewClient)))
        {
            return;     // this will exit the function and it will not be proceeded.
        }

        _DrawScreenHeader("\tAdd New Client Screen");
        string AccountNumber = "";

        cout << "\nPlease enter your account number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExists(AccountNumber))
        {
            cout << "\nAccount number is already used.\nPlease choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(Client);
        
        clsBankClient::enSaveResults SaveResult;
        SaveResult = Client.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::SaveFailedEmptyRecord:
            cout <<"\nError!\nAccount has not been saved for being empty. Please try again...";
            break;
            
        case clsBankClient::enSaveResults::SaveFailedAccountNumberExists:
            cout <<"\nError!\nAccount has not been saved because this account number exists. Please try again...";
            break;
        
        case clsBankClient::enSaveResults::SaveSucceeded:
            cout <<"\n\n____________________________\n\nAccount added successfully!\n";
            _PrintClient(Client);
            break;
        }
    }

};