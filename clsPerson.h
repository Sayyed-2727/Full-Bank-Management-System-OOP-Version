#pragma once
#include <iostream>
using namespace std;

class clsPerson
{

private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    // Property Set
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    
    // Property Get
    string getFirstName()
    {
        return _FirstName;
    }

    // Property Set
    void setLastName(string LastName)
    {
        _LastName = LastName;
    }

    // Property Get
    string getLastName()
    {
        return _LastName;
    }

    // Property Set
    void setEmail(string Email)
    {
        _Email = Email;
    }

    // Property Get
    string getEmail()
    {
        return _Email;
    }

    // Property Set
    void setPhone(string Phone)
    {
        _Phone = Phone;
    }
    
    // Property Get
    string getPhone()
    {
        return _Phone;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

};