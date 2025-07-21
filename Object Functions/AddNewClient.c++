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

void AddNewClient()
{
    string AccountNumber = "";

    cout << "\nPlease enter your account number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExists(AccountNumber))
    {
        cout << "\nAccount number is already used.\nPlease choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(Client);
    
    clsBankClient::enSaveResults SaveResult;
    SaveResult = Client.Save();
}

int main()
{



    return 0;
}