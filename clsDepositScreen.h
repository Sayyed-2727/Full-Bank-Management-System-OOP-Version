#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
using namespace std;


class clsDepositScreen : protected clsScreen
{

private:

public:

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t     Deposit Screen");
        string AccountNumber = clsInputValidate::ReadString("\nPlease enter your account number: ");

        while (!clsBankClient::IsClientExists(AccountNumber))
        {
            system("cls");
            cout << "\nClient with account number (" << AccountNumber << ") does not exist!\nPlease try again...\n" << endl;
            AccountNumber = clsInputValidate::ReadString("Please enter your account number: ");
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\nPlease enter the amount you want to deposit: ";
        double DepositedAmount = clsInputValidate::ReadDblNumber();

        char UserAnswer = 'n';
        cout << "\n\nAre you sure you want to perform this operation? (y/n)\n";
        cin >> UserAnswer;
        
        if (toupper(UserAnswer) == 'Y')
        {
            Client.Deposit(DepositedAmount);
            cout << "\nAmount deposited successfully!" << endl;
            cout << "New balance is: " << Client.getAccountBalance() << endl;  
        }
        else
        {
            cout <<"\nDon't worry! The operation has been cancelled successfully.";
        }
        
        
    }


};