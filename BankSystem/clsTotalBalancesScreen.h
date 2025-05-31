#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClientOnMyOwn.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsTotalBalancesScreen:protected clsScreen
{

private:

    static void _PrintClientRecordLine(clsBankClientOnMyOwn Client)
    {

        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }
public:
	static void ShowTotalBalancesScreen()
	{

    clsScreen::_DrawScreenHeader("\tBalances of Clients in System");
    vector <clsBankClientOnMyOwn> vClients = clsBankClientOnMyOwn::GetClientsList();

    cout << "\n\t\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    //double TotalBalnces = 0;
    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClientOnMyOwn Client : vClients)
        {
         //   TotalBalnces += Client.GetAccountBalance();
            _PrintClientRecordLine(Client);
            
            cout << endl;
        }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    //cout << "\t\t\t\tTotal Balnces = "<< TotalBalnces<<"\n";
    cout << "\t\t\tTotal Balances = " << clsBankClientOnMyOwn::GetTotalBalances(vClients) << "\n";
	
    }

};
