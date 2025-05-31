#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClientOnMyOwn.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsDepositScreen: protected clsScreen
{
private:
	static void _PrintClient(clsBankClientOnMyOwn CC)
	{
		CC.Print();
	}
	 static string _ReadAccountNumber()
	{
		return clsInputValidate::ReadString();
	}

public:
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("Welcome To Deposite Screen\n");
		cout << "Please Enter Account Number : \n";
		//to seperate UI over Businuess logic(backend)
		string accNum = _ReadAccountNumber();//  instead of clsInputValidate::readString
		

		while (!clsBankClientOnMyOwn::IsClientExist(accNum))
		{
			cout << "Not valid Account Number As "<< accNum<<" Not Exist please try again :\n";
			accNum = clsInputValidate::ReadString();
		}
		clsBankClientOnMyOwn Client = clsBankClientOnMyOwn::Find(accNum);
		cout << "Clinet Info: \n";
		//to seperate UI over Businuess logic(backend)
		_PrintClient(Client); // instead of Client.Print();
		
		cout << "Please Enter Amount To Deposit: \n";
		
		double amount = clsInputValidate::ReadDblNumber();
		cout << "Are You Sure You Want to complete process ? y/n \n";
		char ans;
		cin >> ans;
		if (ans == 'y' || ans == 'Y')
		{
			Client.Deposit(amount);
			cout << "Operation Succeeded and Your new Balance is : " << Client.AccountBalance;
		}
		else if (ans == 'n' || ans == 'N')
			cout << "Operation Cancelled\n";

	}
	

};
