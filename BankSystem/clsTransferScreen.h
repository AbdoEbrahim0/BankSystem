#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClientOnMyOwn.h"
#include "clsInputValidate.h"

class clsTransferScreen: protected clsScreen
{
private:
    static void _PrintClient(clsBankClientOnMyOwn Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber;
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClientOnMyOwn::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float ReadAmount(clsBankClientOnMyOwn SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadDblNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }
public:
	static void ShowTransferScreen()
	{
        _DrawScreenHeader("\tTransfer Screen");
        cout << "\nPlease Enter Account Number to Transfer From: ";
        clsBankClientOnMyOwn SourceClient = clsBankClientOnMyOwn::Find(_ReadAccountNumber());

        _PrintClient(SourceClient);
        cout << "\nPlease Enter Account Number to Transfer To: ";
        clsBankClientOnMyOwn DestinationClient = clsBankClientOnMyOwn::Find(_ReadAccountNumber());

        _PrintClient(DestinationClient);

        float Amount = ReadAmount(SourceClient);
        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient,currentUser.UserName))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }

        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);
	}



};
