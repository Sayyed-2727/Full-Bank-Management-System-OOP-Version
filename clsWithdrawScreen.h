#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
using namespace std;


class clsWithdrawScreen : protected clsScreen
{

private:

public:

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t     Withdraw Screen");
        string AccountNumber = clsInputValidate::ReadString("\nPlease enter your account number: ");

        while (!clsBankClient::IsClientExists(AccountNumber))
        {
            system("cls");
            cout << "\nClient with account number (" << AccountNumber << ") does not exist!\nPlease try again...\n" << endl;
            AccountNumber = clsInputValidate::ReadString("Please enter your account number: ");
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\nPlease enter the amount you want to withdraw: ";
        double WithdrownAmount = clsInputValidate::ReadDblNumber();

        if(Client.CheckTransferPossibility(WithdrownAmount))
        {
            char UserAnswer = 'n';
            cout << "\n\nAre you sure you want to perform this operation? (y/n)\n";
            cin >> UserAnswer;

                if (toupper(UserAnswer) == 'Y')
                {            
                    Client.Withdraw(WithdrownAmount);
                    cout << "\nOperation has been compeleted successfully!" << endl;
                    cout << "New balance is: " << Client.getAccountBalance() << endl;  
                }
                else
                {
                    cout <<"\nDon't worry! The operation has been cancelled successfully.";
                }
                
        }
        else
        {
            cout << "\nFaild!\nYou don't have sufficient balance to do this operation." << endl;
            cout << "\n\nAmount to withdraw is: " << WithdrownAmount;
            cout << "\nYour balance is: " << Client.getAccountBalance();
        }
    }
};