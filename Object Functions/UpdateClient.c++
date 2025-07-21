#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

void ReadClientInfo(clsBankClient& Client)
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

void UpdateClient()
{
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
    Client.Print();

    cout << "\n\nUpdating client info....\n";
    cout << "___________________________________";

    ReadClientInfo(Client);

    clsBankClient::enSaveResults SaveResult;
    SaveResult = Client.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::SaveSucceeded:
        cout << "\nAccount Updated Successfully.\n";
        Client.Print();
        break;
    
    case clsBankClient::enSaveResults::SaveFailedEmptyRecord :
        cout << "\nAn error has ocurred! The client has not been save for being empty.\n";
        break;
    
    }
    
}

int main()
{



    return 0;
}