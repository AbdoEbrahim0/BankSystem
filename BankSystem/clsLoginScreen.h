#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "Global.h"
	  
class clsLoginScreen: protected clsScreen
{

private:
	static void _Login()
	{
		string UserName ,passWord ;
		
		bool LoginFailed = false;
		do {
		
			
			if (LoginFailed)
			{
				cout << "\n Invalid userName/PassWord\n";
			}
			cout << "Enter User Name : \n";
			cin >> UserName;
			cout << "Enter password: \n";
			cin >> passWord;
			currentUser = clsUser::Find(UserName, passWord);
			LoginFailed = currentUser.IsEmpty();
		} while (LoginFailed);
		clsMainScreen::ShowMainMenu();
	}

public:
	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t   Login Screen");
		_Login();
		
	}

};
