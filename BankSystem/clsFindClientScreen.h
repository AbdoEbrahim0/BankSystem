#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClientOnMyOwn.h"
#include "clsUtil.h"
#include "clsScreen.h"
class clsFindClientScreen :protected clsScreen
{

private:
    static void _PrintClient(clsBankClientOnMyOwn Client)
    {
        /*cout << "FNAME: " << GetFirstName()<<"\n";
        cout << "LNAME: " << GetLastName() << "\n";
        cout << "EAMAIL: " << Email << "\n";
        cout << "PINCODE: " << PinCode << "\n";
        cout << "PINCODE: " << GetPinCode() << "\n";
        cout << "PINCODE: " << _PinCode << "\n";*/
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
	static void _FindClient()
	{
        cout << "Please Enter Account Number To Find A Client\n";
        string AccNUmber = clsInputValidate::ReadString();
		
        while (! (clsBankClientOnMyOwn::IsClientExist(AccNUmber)))
        {
            //cout << "You Entered Not Valid Account Number Try Somthing Like A101\n";
            cout << "No Client With This Account Number " << AccNUmber << " Is Exist in The System !\n";
            cout << "Try Again: \n";
            AccNUmber = clsInputValidate::ReadString();
        }
        clsBankClientOnMyOwn ClientToShow = clsBankClientOnMyOwn::Find(AccNUmber);
        
        _PrintClient(ClientToShow);
            
	}
public:
	static void FindClientScreen()
	{
		clsScreen::_DrawScreenHeader("   Seacrh On Client In System");
        _FindClient();
	}
};
