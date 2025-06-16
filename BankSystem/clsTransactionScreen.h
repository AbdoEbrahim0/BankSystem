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

class clsTransactionScreen: protected clsScreen
{
private:
    enum enTransactionMenueOptions {eDeposit=1 ,eWithdraw=2,eTotalBalances=3,eMainMenue=4};


    static short _ReadTransactionMenueOption()
    {
        short From = 1, To = 4;
        cout << "\nEnter what Choice You Want to do ? From " << From << " To " << To << "\n";
        short choice = (short)clsInputValidate::ReadIntNumberBetween(From, To, "Invalid Number, Enter number between 1 : 4\n");
        return choice;
        
    }
    static void _GoBackToTansactionMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Tansaction Menue...\n";
        system("pause>0");
        ShowTransactionMenu();
    }
    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
        //cout << "Deposit screen will be here\n";
    }
    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
        //cout << "Withdraw screen will be here\n";
    }
    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
        //cout << "Total balancesscreen will be here\n";
    }
    
    static void _PerformTransactionMenuOPtion(enTransactionMenueOptions Choice)
    {
        switch (Choice)
        {
        case clsTransactionScreen::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTansactionMenue();
            break;
        }
        case clsTransactionScreen::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTansactionMenue();
            break;
        }
        case clsTransactionScreen::eTotalBalances:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTansactionMenue();
            break;
        }
        case clsTransactionScreen::eMainMenue:
        {
            system("cls");

            //clsMainScreen::ShowMainMenu();
            break;
        }
        default:
            break;
        }
    
    }
public:
	static void ShowTransactionMenu()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }
		system("cls");
		clsScreen::_DrawScreenHeader("\tTransaction Menu");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransaction Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposite.\n";
        cout << setw(37) << left << "" << "\t[2] WithDraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] return back To Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionMenuOPtion((enTransactionMenueOptions)_ReadTransactionMenueOption());
	}


};
