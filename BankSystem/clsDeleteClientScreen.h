#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClientOnMyOwn.h"
#include "clsUtil.h"
#include "clsScreen.h"


class clsDeleteClientScreen: clsScreen
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

public:
    static void DeleteClient()
    {
        clsScreen::_DrawScreenHeader("\tDeleting Client From The System");
        cout << "what Client Account Number Do You want To delete ? Enter acc number\n";
        string Acc = clsInputValidate::ReadString();

        while (!clsBankClientOnMyOwn::IsClientExist(Acc))
        {
            cout << "You entered Wrong Acc Number try Again:";
            Acc = clsInputValidate::ReadString();
        }
        clsBankClientOnMyOwn clientToBeDeleted = clsBankClientOnMyOwn::Find(Acc);
        //clientToBeDeleted.Print(); seperate UI from any object businuess
        _PrintClient(clientToBeDeleted);
        cout << "Are you sure you want to delete client with Acc. number" << Acc << " Y/N ?\n";
        char ans;
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {

            if (clientToBeDeleted.Delete())
            {
                cout << "Client Removed Successfully\n";
                _PrintClient(clientToBeDeleted);
                //clientToBeDeleted.Print();
            }
            else
            {
                cout << " error Client was not Removed from the System\n";
            }
        }
        else
        {
            cout << "client still exist in the system\n";
        }
    }

};
