#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClientOnMyOwn.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginScreen.h"
#include "Global.h"
class clsMainScreen :protected clsScreen
{
private :
    enum enMainMenueOptions { eListClients =1 , eAddNewClient =2, eDeleteClient =3
        , eUpdateClient =4, eFindClient =5, eShowTransactionsMenue =6, eManageUsers =7
        , eExit =8};
    static short _ReadMainMenueOption()
    {
        short From = 1, To = 8;
        cout << "\nEnter what Choice You Want to do ? From " << From << " To " << To<<"\n";
        short choice =(short) clsInputValidate::ReadIntNumberBetween(From, To, "Invalid Number, Enter number between 1 : 8\n");
        return choice;
    }
    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowMainMenu();
    }
    static void _ShowAllClientsScreen() {
        
        clsClientListScreen:: ShowClientsList();
        //cout << "\nClient List Screen Will be here...\n";
    }
    static void _ShowAddNewClientsScreen() {
        clsAddNewClientScreen::ShowAddNewClient();
        
        //cout << "\nAdd New Client Screen Will be here...\n";
    }
    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::DeleteClient();
        //cout << "\nDelete Client Screen Will be here...\n";
    }
    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::UpdateClient();
        //cout << "\nUpdate Client Screen Will be here...\n";
    }
    static void _ShowFindClientScreen()
    {
        
        clsFindClientScreen::FindClientScreen();
        //cout << "\nFind Client Screen Will be here...\n";
    }
    static void _ShowTransactionsMenue()
    {
        clsScreen::_DrawScreenHeader("\t   Transaction Menu");
        clsTransactionScreen::ShowTransactionMenu();
        cout << "\nTransactions Menue Will be here...\n";
    }
    static void _ShowManageUsersMenue()
    {
        clsScreen::_DrawScreenHeader("\t   Manage Useres");
        clsManageUsersScreen::ShowManageUsersMenu();
        //cout << "\nUsers Menue Will be here...\n";
    }
            //static void _ShowEndScreen()
            //{
            //    clsScreen::_DrawScreenHeader("\t     Thank You!! ");
            //    cout << "\nEnd Screen Will be here...\n";
            //}

    static void _Logout()
    {
        currentUser = clsUser::Find("", "");
    }
    static void _PerformMainMenuOPtion(enMainMenueOptions enOption)
    {
        switch (enOption)
        {
        case clsMainScreen::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eExit:
            system("cls");
            //_ShowEndScreen();
            _Logout();
            break;
        default:
            break;
        }
    }
public:
	static void ShowMainMenu()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("\t\tMain Menu");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuOPtion((enMainMenueOptions)_ReadMainMenueOption());
	}

};

