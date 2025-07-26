#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <string>
#include <vector>
#include <fstream>
#include "ClsDate.h"
#include "Global.h"
using namespace std;

class clsBankClient : public clsPerson
{

private:
    enum enMode {EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;
 
    static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
    {
        vector <string> vClientData;
        vClientData = clsString::Split(Line, Separator);
        
        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static vector <clsBankClient> _LoadClientsDataFromFile()
    {
        vector <clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("ClientsNameFile.txt", ios::in); // Read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = clsBankClient::_ConvertLineToClientObject(Line);
                vClients.push_back(Client);
            }
            
            MyFile.close();
        }

        return vClients;
    }

    static string  _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
    {
        string DataLine;
        DataLine += Client.getFirstName() + Separator;
        DataLine += Client.getLastName() + Separator;
        DataLine += Client.getEmail() + Separator;
        DataLine += Client.getPhone() + Separator;
        DataLine += Client.AccountNumber() + Separator;
        DataLine += Client.getPinCode() + Separator;
        DataLine += to_string(Client.getAccountBalance());

        return DataLine;
    }

    static void _SaveClientDataToFile(vector <clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open("ClientsNameFile.txt", ios::out); // OverWrite
        string DataLine;

        if (MyFile.is_open())
        {
            for (clsBankClient c: vClients)
            {
                if (c._MarkedForDelete == false)
                {
                    DataLine = _ConvertClientObjectToLine(c);
                    MyFile << DataLine << endl;
                }
            }
            
            MyFile.close();
        }
        
    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& c : _vClients)
        {
            if (c.AccountNumber() == AccountNumber())
            {
                c = *this;
                break;
            }
        }
        
        _SaveClientDataToFile(_vClients);
    }

    void _AddDataLineToFile(string DataLine)
    {
        fstream MyFile;
        MyFile.open("ClientsNameFile.txt", ios::out | ios::app);  // to append

        if (MyFile.is_open())
        {
            MyFile << DataLine << endl;
            MyFile.close();
        }
        
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    
    string _ConvertTransactionDataToString(clsBankClient ClientDest, double TransferAmount, string Separator = "#//#")
    {
        string TransactionRegister = "";

        TransactionRegister += clsDate::DateToString(clsDate()) + " - " + clsDate::TimeToString(clsDate()) + Separator;
        TransactionRegister += _AccountNumber + Separator;
        TransactionRegister += ClientDest.AccountNumber() + Separator;
        TransactionRegister += to_string(TransferAmount) + Separator;
        TransactionRegister += to_string(_AccountBalance) + Separator;
        TransactionRegister += to_string(ClientDest.getAccountBalance()) + Separator;
        TransactionRegister += CurrentUser.getUserName();

        return TransactionRegister;
    }

    void _TransferRegister(clsBankClient ClientDest, double TransferAmount)
    {
        string TransactionRecord = _ConvertTransactionDataToString(ClientDest, TransferAmount);
        
        fstream MyFile;
        MyFile.open("TransactionsHistory.txt", ios::out | ios::app);  // to append

        if (MyFile.is_open())
        {
            MyFile << TransactionRecord << endl;
            MyFile.close();
        }
        
    }


public:

    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : 
    clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _AccountBalance = AccountBalance;
        _PinCode = PinCode; // <-- Add this line

    }

    // Read Only Properties
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    // Get and Set Properties
    void setPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string getPinCode()
    {
        return _PinCode;
    }

    void setAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float getAccountBalance()
    {
        return _AccountBalance; 
    }

    // void Print()
    // {
    //     cout << "\nClient Card:";
    //     cout << "\n____________________";
    //     cout << "\nFirstName       : " << getFirstName();
    //     cout << "\nLastName        : " << getLastName();
    //     cout << "\nFullName        : " << FullName();
    //     cout << "\nEmail           : " << getEmail();
    //     cout << "\nPhone           : " << getPhone();
    //     cout << "\nAccount Number  : " << AccountNumber();
    //     cout << "\nPinCode         : " << getPinCode();
    //     cout << "\nAccount Balance : " << getAccountBalance();
    //     cout << "\n____________________\n";
    // }

    struct stTransactionsHistory
    {
        string DateTime;
        string SourceAccount;
        string DestinationAccouunt;
        float TransactionAmount;
        float SourceBalance;
        float DestinationBalannce;
        string Username;
    };
    

    static clsBankClient Find(string AccountNumber)
    {
        vector <clsBankClient> vBankClient;
        fstream MyFile;
        MyFile.open("ClientsNameFile.txt", ios::in); // Read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile,Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client._AccountNumber == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
                vBankClient.push_back(Client);
            }
            
            MyFile.close();
        }
        
        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        vector <clsBankClient> vBankClient;
        fstream MyFile;
        MyFile.open("ClientsNameFile.txt", ios::in); // Read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile,Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client._AccountNumber == AccountNumber && Client._PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
                vBankClient.push_back(Client);
            }
            
            MyFile.close();
        }
        
        return _GetEmptyClientObject();
    }

    static bool IsClientExists(string AccountNumber)
    {
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        
        return (!Client.IsEmpty());
    }

    enum enSaveResults {SaveFailedEmptyRecord = 0, SaveSucceeded = 1, SaveFailedAccountNumberExists = 2};

    enSaveResults Save()
    {
        switch (_Mode)
        {
        
        case enMode::EmptyMode :
        {
            if (IsEmpty())
            {
                return enSaveResults::SaveFailedEmptyRecord;
            }
        }
        
        case enMode::UpdateMode :
        {
            _Update();
            return enSaveResults::SaveSucceeded;
            break;
        }
        
        case enMode::AddNewMode:
        {
            // This will add new record to file or database
            if (IsClientExists(_AccountNumber))
            {
                return enSaveResults::SaveFailedAccountNumberExists;
                break;
            }
            else
            {
                _AddNew();

                // We need to set up the mood to be update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::SaveSucceeded;
            }
            
        }

        default:
            break;
        }
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "","","","",AccountNumber,"",0);
    }

    bool Delete()
    {
        vector <clsBankClient> vClientes;
        vClientes = _LoadClientsDataFromFile();

        for (clsBankClient& c : vClientes)
        {
            if (c.AccountNumber() == this-> AccountNumber())
            {
                c._MarkedForDelete = true;        
                _SaveClientDataToFile(vClientes);
                *this = _GetEmptyClientObject();
                
                return true;
            }   
        }
        return false;
    }

    static vector <clsBankClient> GetClientsList()
    {
        return clsBankClient::_LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();
        
        double TotalBalances = 0;

        for (clsBankClient c : vClients)
        {
            TotalBalances += c.getAccountBalance();
        }

        return TotalBalances;
    }

    void Deposit(double AmountToDeposit)
    {
        _AccountBalance += AmountToDeposit;
        Save();
    }

    bool Withdraw(double AmountToWithdraw)
    {
        if (AmountToWithdraw > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= AmountToWithdraw;
            Save();
            return true;
        }
    }
    
    bool CheckTransferPossibility(double AmountToWithdraw)
    {
        if (AmountToWithdraw > _AccountBalance)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool Transfer(double AmountToTransfer, clsBankClient& DestClient)
    {
        if (AmountToTransfer > _AccountBalance)
        {
            return false;
        }

        Withdraw(AmountToTransfer);
        DestClient.Deposit(AmountToTransfer);
        _TransferRegister(DestClient, AmountToTransfer);
        return true;
    }

    static stTransactionsHistory ConvertTransactionToRecord(string Transaction, string Separator = "#//#")
    {
        vector <string> vString = clsString::Split(Transaction, Separator);
        stTransactionsHistory TransactionRecord;

        TransactionRecord.DateTime = vString[0];
        TransactionRecord.SourceAccount = vString[1];
        TransactionRecord.DestinationAccouunt = vString[2];
        TransactionRecord.TransactionAmount = stof(vString[3]);
        TransactionRecord.SourceBalance = stof(vString[4]);
        TransactionRecord.DestinationBalannce = stof(vString[5]);
        TransactionRecord.Username = CurrentUser.getUserName();
        
        return TransactionRecord;
    }   

    static vector <stTransactionsHistory> GetTransactionsHistoryList()
    {
        vector <stTransactionsHistory> vTransactions;
        fstream MyFile;
        MyFile.open("TransactionsHistory.txt", ios::in); // Read Mode

        if (MyFile.is_open())
        {
            string Line;
            stTransactionsHistory Transaction;
            while (getline(MyFile, Line))
            {
                Transaction = ConvertTransactionToRecord(Line);
                vTransactions.push_back(Transaction);
            }
            
            MyFile.close();
        }

        return vTransactions;
    }

};