#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClientOnMyOwn.h"
#include "clsUtil.h"
#include "clsScreen.h"
class clsUpdateClientScreen :protected clsScreen
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

    static void ReadClientInfo(clsBankClientOnMyOwn& myclinet)
    {
        cout << "\nBEFORE EDIT ::\n" << endl;
        _PrintClient(myclinet);
        //myclinet.Print(); seperate Ui from businuess logic object
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
        //myclinet.Print(); //seperate Ui from businuess logic object
        _PrintClient(myclinet);
    }
public:

    static void UpdateClient()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return; //will return to mai menue after showing access denied screen
        }
        clsScreen::_DrawScreenHeader(" Update Info Of Client In The System");
        cout << "Enter Account number to update Info: ";
        string s = clsInputValidate::ReadString();

        while (!clsBankClientOnMyOwn::IsClientExist(s))
        {
            cout << "invalid account number please try another account exist: \n";
            s = clsInputValidate::ReadString();

        }
        clsBankClientOnMyOwn clientToEdit = clsBankClientOnMyOwn::Find(s);
        ReadClientInfo(clientToEdit);
        clientToEdit.Save();
    }
};
