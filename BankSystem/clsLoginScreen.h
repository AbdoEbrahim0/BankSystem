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
	static string _LogDataToLine(string Usr, string pass,short perm,  string Seperator = "#//#")
	{
		string s;
		clsDate currentDate;
		s = s + clsDate::DateToString(currentDate) + " - ";
		s = s + clsDate::TimeToString(currentDate) + Seperator;
		s = s + Usr + Seperator;
		s = s + pass + Seperator;
		s = s +  to_string(perm);
		return s;
	}
	static  vector <string> _LoadLogsDataFromFile()
	{
		vector <string> vLogs;
		fstream MyFile;
		MyFile.open("C:\\Users\\Mr_Abdo\\source\\repos\\BankSystem\\BankSystem\\LoginRegister.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				vLogs.push_back(Line);
			}
			MyFile.close();
		}
		return vLogs;
	}
	static void _SaveLogsDataToFile(vector <string> vLogs)
	{

		fstream MyFile;
		MyFile.open("C:\\Users\\Mr_Abdo\\source\\repos\\BankSystem\\BankSystem\\LoginRegister.txt", ios::out);//overwrite
		string DataLine;
		if (MyFile.is_open())
		{
			for (string log : vLogs)
			{
					//we only write records that are not marked for delete.  
					DataLine = log;
					MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}
	static void _SaveLogDataToFile(string DataLineOfLoggedUser)
	{

		fstream MyFile;
		MyFile.open("C:\\Users\\Mr_Abdo\\source\\repos\\BankSystem\\BankSystem\\LoginRegister.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{
					//we only write records that are not marked for delete.  
		DataLine = DataLineOfLoggedUser;
		MyFile << DataLine << endl;
		MyFile.close();

		}

	}
	static bool _Login()
	{
		string UserName ,passWord ;
		short PermissionsOfUser;
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
			PermissionsOfUser = currentUser.Permissions;
			LoginFailed = currentUser.IsEmpty();
			
		} while (LoginFailed );
		vector<string>myVLogs= _LoadLogsDataFromFile();
		myVLogs.push_back(_LogDataToLine(UserName, passWord, PermissionsOfUser));
		_SaveLogsDataToFile(myVLogs);
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

