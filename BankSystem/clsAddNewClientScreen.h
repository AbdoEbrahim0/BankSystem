#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClientOnMyOwn.h"
#include "clsUtil.h"
#include "clsScreen.h"

class clsAddNewClientScreen : clsScreen
{

private:
    static void ReadClientInfo(clsBankClientOnMyOwn& myclinet)
    {
        cout << "\nBEFORE EDIT ::\n" << endl;
        myclinet.Print();
        string temp = "";
        cout << "\nF.Name: ";
        cin >> temp;   myclinet.FirstName = temp;
        cout << "\nL.Name: ";
        cin >> temp; myclinet.LastName = temp;
        cout << "\nEmail: ";
        cin >> temp; myclinet.Email = temp;
        cout << "\nPhone: ";
        cin >> temp; myclinet.Phone = temp;
        cout << "\nPinCode: ";
        cin >> temp; myclinet.PinCode = temp;
        cout << "\nAccountBalance  ";  myclinet.AccountBalance = clsInputValidate::ReadDblNumber();
        cout << "\n Results After EDIT ::\n" << endl;
        myclinet.Print();

    }

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
    static void ShowAddNewClient()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
        _DrawScreenHeader("\tAdd New Client To System");
        cout << "Enter Acount number of a new Client you want to add to databse\n";
        string accNum = clsInputValidate::ReadString();
        while (clsBankClientOnMyOwn::IsClientExist(accNum))
        {
            cout << "Account Number You enter Exist in database  try another one: \n";
            accNum = clsInputValidate::ReadString();
        }
        clsBankClientOnMyOwn NewClient = clsBankClientOnMyOwn::GetAddNewClientObject(accNum);

        ReadClientInfo(NewClient);

        clsBankClientOnMyOwn::enSaveResults SaveResults;
        SaveResults = NewClient.Save();
        if (SaveResults == clsBankClientOnMyOwn::enSaveResults::svSucceeded)
        {
            cout << "new account Added succesfully To databse" << endl;
            _PrintClient(NewClient);

        }
        else if (SaveResults == clsBankClientOnMyOwn::enSaveResults::svFailEmptyObject)
        {

            cout << "\nError account was not saved because it's Empty";
        }
        else if (SaveResults == clsBankClientOnMyOwn::enSaveResults::svFaildAccountNumberExist)
        {
            cout << "faid to add to database The Account Number is exist already\n";
        }

    }

};
