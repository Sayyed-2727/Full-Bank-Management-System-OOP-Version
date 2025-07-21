#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"
#include "ClsDate.h"
#include "ClsUtil.h"
using namespace std;


class clsUser : public clsPerson
{

private:

    enum enMode {EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;
    bool _MarkedForDelete = false;

    static clsUser ConvertLineToUserObject(string Line, string Separator = "#//#")
    {
        vector <string> vWords = clsString::Split(Line, Separator);
        return clsUser(enMode::UpdateMode, vWords[0], vWords[1], vWords[2], vWords[3], vWords[4], ClsUtil::_DecryptText(vWords[5]), stoi(vWords[6]));
    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "","","","","","",0);
    }

    static string  _ConvertClientObjectToLine(clsUser User, string Separator = "#//#")
    {
        string DataLine;
        DataLine += User.getFirstName() + Separator;
        DataLine += User.getLastName() + Separator;
        DataLine += User.getEmail() + Separator;
        DataLine += User.getPhone() + Separator;
        DataLine += User.getUserName() + Separator;
        DataLine += ClsUtil::_EncryptText(User.GetPassword()) + Separator;
        DataLine += to_string(User.GetPermissions());


        return DataLine;
    }

    void _AddDataLineToFile(string DataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);  // to append

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
 
    static void _SaveUsersDataToFile(vector <clsUser> _vUsers)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out); // OverWrite
        string DataLine;

        if (MyFile.is_open())
        {
            for (clsUser c: _vUsers)
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

    static vector <clsUser> _LoadUsersDataFromFile()
    {
        vector <clsUser> vClients;
        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // Read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser Client = clsUser::ConvertLineToUserObject(Line);
                vClients.push_back(Client);
            }
            
            MyFile.close();
        }

        return vClients;
    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& c : _vUsers)
        {
            if (c.getUserName() == _UserName)
            {
                c = *this;
                break;
            }
        }
        
        _SaveUsersDataToFile(_vUsers);
    }

    string _ConvertUserLoginDataToString(string Separator = "#//#")
    {
        string LoginRegister = "";
        LoginRegister += clsDate::DateToString(clsDate()) + " - " + clsDate::TimeToString(clsDate()) + Separator;
        LoginRegister += _UserName + Separator;
        LoginRegister += ClsUtil::_EncryptText(_Password) + Separator;
        LoginRegister += to_string(_Permissions);

        return LoginRegister;
    }
    

public:

    struct stLoginRegisterRecord
    {
        string DateTime;
        string Username;
        string Password;
        int Permissions;
    };
    
    enum enPermissions {enAll = -1, enListClients = 1, enAddNewClient = 2, enDeleteClient = 4, enUpdateClient = 8, enFindClient = 16,
                        enTransactions = 32, enManageUsers = 64, enLoginRegister = 128
                        };

    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone,  string UserName, string Password, int Permissions)
    : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool IsMarkedForDelete()
    {
        return _MarkedForDelete;
    }

    // Set and Get

    string getUserName()
    {
        return _UserName;
    }
    
    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    string GetPassword()
    {
        return _Password;
    }
    
    void SetPassword(string Password)
    {
        _Password= Password;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
 
    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // read Mode
        
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = ConvertLineToUserObject(Line);
                if (User.getUserName() == UserName)
                {
                    MyFile.close();
                    return User;
                }
                
            }

            MyFile.close();
        }
        
        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // read Mode
        
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = ConvertLineToUserObject(Line);
                if (User.getUserName() == UserName && User.GetPassword() == Password)
                {
                    MyFile.close();
                    return User;
                }
                
            }

            MyFile.close();
        }

        return _GetEmptyUserObject();
    }

    static bool IsUserExists(string UserName)
    {
        clsUser User = Find(UserName);
        return !(User.IsEmpty());
    }

    enum enSaveResults {enSaveFailedEmptyObject = 0, enSaveSucceeded = 1, enSaveFailedUserExists = 2};

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::enSaveFailedEmptyObject;
            }
        }

        case enMode::UpdateMode :
        {
            _Update();
            return enSaveResults::enSaveSucceeded;
            break;
        }
        
        case enMode::AddNewMode:
        {
            // This will add new record to file or database
            if (IsUserExists(_UserName))
            {
                return enSaveResults::enSaveFailedUserExists;
            }
            else
            {
                _AddNew();
                // We need to reset Mode to Update after add the new user
                _Mode = enMode::UpdateMode;
                return enSaveResults::enSaveSucceeded;
            }

            break;
        }
        
        }
    }

    bool Delete()
    {
        vector <clsUser> vUsers = _LoadUsersDataFromFile();
        
        for (clsUser& User : vUsers)
        {
            if (User.getUserName() == _UserName)
            {
                User._MarkedForDelete = true;
                break;
            }
        }

        _SaveUsersDataToFile(vUsers);
        *this = _GetEmptyUserObject();
        return true;
    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode,"","","","",UserName,"",0);
    }

    static vector <clsUser> GetUsersList()
    {
        return clsUser::_LoadUsersDataFromFile();
    }

    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->_Permissions == enPermissions::enAll)
        {
            return true;
        }

        // if (permission & group of permissions = the same permission) => means that permission is included of this group of permissions. 
        if ((Permission & this->_Permissions) == Permission)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
        
    }

    void LoginRegister()
    {
        string LoginRecord = _ConvertUserLoginDataToString();
        
        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);  // to append

        if (MyFile.is_open())
        {
            MyFile << LoginRecord << endl;
            MyFile.close();
        }
        
    }

    static stLoginRegisterRecord ConvertLoginRegisterToRecord(string RecordLine, string Separator = "#//#")
    {
        vector <string> vString = clsString::Split(RecordLine, Separator);
        stLoginRegisterRecord Record;

        Record.DateTime = vString[0];
        Record.Username = vString[1];
        ClsUtil::_DecryptText(Record.Password) = vString[2];
        Record.Permissions = stoi(vString[3]);
        
        return Record;
    }   

    static vector <stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector <stLoginRegisterRecord> vRecords;
        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in); // Read Mode

        if (MyFile.is_open())
        {
            string Line;
            stLoginRegisterRecord LoginRegister;
            while (getline(MyFile, Line))
            {
                LoginRegister = ConvertLoginRegisterToRecord(Line);
                vRecords.push_back(LoginRegister);
            }
            
            MyFile.close();
        }

        return vRecords;
    }

};