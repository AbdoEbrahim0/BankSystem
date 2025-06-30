#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClientOnMyOwn.h"
#include "clsInputValidate.h"

class clsTransferLogScreen:protected clsScreen
{
private:
    static vector<vector<string>>_LoadLogsDataFromFile()
    {
        vector<vector<string>>vLogs;
        fstream myFile;
        myFile.open("C:\\Users\\Mr_Abdo\\source\\repos\\BankSystem\\BankSystem\\TransferLog.txt", ios::in);//readMode
        if (myFile.is_open())
        {
            string Line;
            while (getline(myFile, Line))
            {
                vLogs.push_back(clsString::Split(Line, "#//#")) ;
            }
            myFile.close();
        }
        return vLogs;
    }

    static void _PrintlogRecordLine(vector<string> LogDataLine )
    {
        
            cout << "| " << setw(20) << left << LogDataLine[0];
            cout << "| " << setw(17) << left << LogDataLine[1];
            cout << "| " << setw(17) << left << LogDataLine[2];
            cout << "| " << setw(17) << left << LogDataLine[3];
            cout << "| " << setw(13) << left << LogDataLine[4];
            cout << "| " << setw(13) << left << LogDataLine[5];
            cout << "| " << setw(13) << left << LogDataLine[6];
        
    }
public:
    
	static void ShowTransferLogsScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pShowLogsScreen))
        {
            return;
        }
		clsScreen::_DrawScreenHeader("\tTransfer Log Screen");
        vector <vector<string>> vTransferLogs = _LoadLogsDataFromFile();

        cout << "\n\t\t\t\t\t\tLog List (" << vTransferLogs.size() << ") Log(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(20) << "Date-Time";
        cout << "| " << left << setw(17) << "S. Account Number";
        cout << "| " << left << setw(17) << "D. Account Number";
        cout << "| " << left << setw(17) << "Amount Transfered";
        cout << "| " << left << setw(13) << "S.New Balance";
        cout << "| " << left << setw(13) << "D.New Balance";
        cout << "| " << left << setw(13) << "User(Admin)";

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    
        if (vTransferLogs.size() == 0)
            cout << "\t\t\t\tNo Logs Available In the System!";
        else

            for (vector<string> &val: vTransferLogs)
            {
                _PrintlogRecordLine(val);
                cout << endl;
            }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

	}

};
