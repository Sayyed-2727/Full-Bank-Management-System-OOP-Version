#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

int main()
{

    clsBankClient Client1 = clsBankClient::Find("ES150");
    Client1.Print();
    
    clsBankClient Client2 = clsBankClient::Find("EG151", "2511");
    Client2.Print();

    cout << clsBankClient::IsClientExists("EG155");

    return 0;
}