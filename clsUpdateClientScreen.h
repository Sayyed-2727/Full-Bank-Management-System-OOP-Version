#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include <iomanip>
using namespace std;

class  clsUpdateClientScreen : protected clsScreen
{

private:

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

    enum enChoiceToUpdate {enFirstName = 1, enLastName = 2, enEmail = 3, enPhone = 4, enPinCode = 5, enAccountBalance = 6};

    static void ChoiceToUpdate(clsBankClient& Client)
    {
        char UserAnswer = 'n';
        short UserChoice;
        cout << "\nDo you want to Modify the whole client information? (y or n)\n";
        cin >> UserAnswer;

        if (toupper(UserAnswer) == 'Y')
        {
            ReadClientInfo(Client);
        }
        else
        {
            cout << "\nPlease choice the option you desire modifiy:\n";
            cout << "\n\t[1] First Name";
            cout << "\n\t[2] Last Name";
            cout << "\n\t[3] Email";
            cout << "\n\t[4] Phone Number";
            cout << "\n\t[5] Pin Code";
            cout << "\n\t[6] Account Balance\n\n";
            cin >> UserChoice;

            switch (UserChoice)
            {
            case enChoiceToUpdate::enFirstName:
                Client.setFirstName(clsInputValidate::ReadString("\nPlease enter your First Name: "));
                break;
            
            case enChoiceToUpdate::enLastName:
                Client.setLastName(clsInputValidate::ReadString("\nPlease enter your Last Name: "));
                break;
            
            case enChoiceToUpdate::enEmail:
                Client.setEmail(clsInputValidate::ReadString("\nPlease enter your Email: "));
                break;
            
            case enChoiceToUpdate::enPhone:
                Client.setPhone(clsInputValidate::ReadString("\nPlease enter your Phone: "));
                break;
            
            case enChoiceToUpdate::enPinCode:
                Client.setPinCode(clsInputValidate::ReadString("\nPlease enter your Pin Code: "));
                break;
            
            
            case enChoiceToUpdate::enAccountBalance:
                Client.setAccountBalance(clsInputValidate::ReadFloatNumber("","\nPlease enter your Account Balance: "));
                break;
            }
        }
        
        
    }

    static void ShowUpdateClientScreen()
    {
        if (!(CheckAccessRights(clsUser::enPermissions::enUpdateClient)))
        {
            return;     // this will exit the function and it will not be proceeded.
        }

        _DrawScreenHeader("\tUpdate Client Screen");
        string AccountNumber = "";
        cout << "\nPlease Enter client account number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!(clsBankClient::IsClientExists(AccountNumber)))
        {
            cout << "\nAccount Number is not found!\nPlease enter another account number: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        cout << "\nWe found the next client information: \n";
        _PrintClient(Client);

        cout << "\n\nUpdating client info....\n\n";
        cout << "___________________________________\n";

        // Add a method that could edit just a single member of user choice.
        
        ChoiceToUpdate(Client);
        
        clsBankClient::enSaveResults SaveResult;
        SaveResult = Client.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::SaveSucceeded:
            cout << "\nAccount Updated Successfully.\n";
            _PrintClient(Client);
            break;
        
        case clsBankClient::enSaveResults::SaveFailedEmptyRecord :
            cout << "\nAn error has ocurred! The client has not been save for being empty.\n";
            break;
        
        }
        
    }
};