#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
using namespace std;


class clsTransferScreen : protected clsScreen
{

private:

    static string _ReadAccountNumber(string Message)
    {
        string AccTransfrom = clsInputValidate::ReadString(Message);

        while (!clsBankClient::IsClientExists(AccTransfrom))
        {
            system("cls");
            cout << "\nThere's no clients with this account number (" << AccTransfrom << ") in the system!\nPlease try again...\n" << endl;
            AccTransfrom = clsInputValidate::ReadString(Message);
        }

        return AccTransfrom;
    }

    static double _ReadAmount(clsBankClient ClientOrig)
    {
        cout << "\nPlease enter the amount you want to transfer: ";
        double TransferAmount = clsInputValidate::ReadDblNumber();
        
        
        while (!ClientOrig.CheckTransferPossibility(TransferAmount))
        {
            cout << "\nFaild!\nAmount exceeds the available balance. Please enter another amount: " << endl;
            TransferAmount = clsInputValidate::ReadDblNumber();
        }

        return TransferAmount;
    }

public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t     Transfer Screen");

        // Read and Find source account
        string AccTransfrom = _ReadAccountNumber("\n\nPlease enter an account number to transfer from: ");
        clsBankClient ClientOrig = clsBankClient::Find(AccTransfrom);
        _PrintClientShort(ClientOrig);

        // Read and Find Destination account
        string AccTransTo = _ReadAccountNumber("\n\nPlease enter an account number to transfer to: ");
        clsBankClient ClientDest = clsBankClient::Find(AccTransTo);
        _PrintClientShort(ClientDest);

        // Read and validate amount to transfer
        double TransferAmount = _ReadAmount(ClientOrig);

        char UserAnswer = 'n';
        cout << "\n\nAre you sure you want to perform this operation? (y/n)\n";
        cin >> UserAnswer;

        if (toupper(UserAnswer) == 'Y')
        {            
            if(ClientOrig.Transfer(TransferAmount,ClientDest))
            {
                cout << "\nOperation has been compeleted successfully!" << endl;
                _PrintClientShort(ClientOrig);
                _PrintClientShort(ClientDest);
        
            }
            else
            {
                cout << "\nAn error has occured, please try again.";
            }
            
        }
        else
        {
            cout <<"\nDon't worry! The operation has been cancelled successfully.";
        }
    
    }


};