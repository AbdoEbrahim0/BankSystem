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
	
	static bool _Login()
	{
		string UserName ,passWord ;
		static short NumberOfFailedloggingIn=0;
		bool LoginFailed = false;
		do {	
			
			if (LoginFailed)
			{
				cout << "\n Invalid userName/PassWord\n";
				NumberOfFailedloggingIn++;
				cout << "you have " << (3 - NumberOfFailedloggingIn) << " Atempts or system will be Locked Down\n";
				if (NumberOfFailedloggingIn == 3)
				{
					cout << "\nYou reached maximum Number Of Attemps system will be locked Due to Security\n";
					return false;
				}
			}
			cout << "Enter User Name : \n";
			cin >> UserName;
			cout << "Enter password: \n";
			cin >> passWord;
			currentUser = clsUser::Find(UserName, passWord);
			LoginFailed = currentUser.IsEmpty();
			
		} while (LoginFailed );
		
		NumberOfFailedloggingIn = 0; // to reset number of failure when any user logged in successfully
		clsMainScreen::ShowMainMenu();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t   Login Screen");
		return _Login();
		
	}

};

