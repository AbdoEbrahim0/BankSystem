#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClientOnMyOwn.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen :protected clsScreen
{
private:
	enum enManageUsersMenuOPtions
	{
		eListUsers=1,
		eAddNewUser=2,
		eDeleteUser= 3,
		eUpdateUser= 4,
		eFindUser= 5,
		eMainMenue= 6,
		
	};
	static short _ReadManageUsersMenueOption()
	{
		short From = 1, To = 6;
		cout << "\nEnter what Choice You Want to do ? From " << From << " To " << To << "\n";
		short choice = (short)clsInputValidate::ReadIntNumberBetween(From, To, "Invalid Number, Enter number between 1 : 6\n");
		return choice;
	}
	static void _GoBackToManageUsersMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Tansaction Menue...\n";
		system("pause>0");
		ShowManageUsersMenu();
	}
	 static void _ShowListUsersScreen()
	 {
		 clsListUsersScreen::ShowListUsersScreen();
		 //cout << "Show List Screen\n";
	 }
	 static void _ShowAddNewUserScreen()
	 {
		 clsAddNewUserScreen::ShowAddNewUserScreen();
		 //cout << "Show Add New user Screen Screen\n";
	 }
	 static void _ShowDeleteUserScreen()
	 {
		 clsDeleteUserScreen::ShowDeleteUserScreen();
		 //cout << "Show Delete User  Screen\n";
	 }
	 static void _ShowUpdateUserScreen()
	 {
		 clsUpdateUserScreen::ShowUpdateUserScreen();
		 //cout << "Show Update User Screen\n";
	 }
	 static void _ShowFindUserScreen()
	 {
		 clsFindUserScreen::ShowFindUserScreen();
		 //cout << "Show Find User Screen\n";
	 }

	 
	 static void _PerformManageUsersMenuOPtion(enManageUsersMenuOPtions choice)
	{
		switch (choice)
		{
		case enManageUsersMenuOPtions::eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenuOPtions::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenuOPtions::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenuOPtions::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenuOPtions::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenuOPtions::eMainMenue:
			system("cls");
			//_GoBackToManageUsersMenue();
			break;
		default:
			break;
		}
	
	}
public:
	static void ShowManageUsersMenu()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		system("cls");
		clsScreen::_DrawScreenHeader("\tManage Useres Menu");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tManage UseresMenue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Return To Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageUsersMenuOPtion((enManageUsersMenuOPtions)_ReadManageUsersMenueOption());
		
	}

};
