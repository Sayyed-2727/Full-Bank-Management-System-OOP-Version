#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "ClsUtil.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h"
using namespace std;



int main()
{
    
    // In order to make the program open the login screen again and again, we put it within a loop
        
    while(true)
    {
        // clsMainScreen::ShowMainMenu();
        if(!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }

    return 0;                                                   
}