#pragma once
#include <iostream>
#include <iomanip>

#include "clsUtil.h"
#include "clsScreen.h"
#include "clsUser.h"
class clsListUsersScreen :clsScreen {

private:
    static void _PrintUserRecordLine(clsUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;
    }
public:
	static void ShowListUsersScreen()
	{
        clsScreen::_DrawScreenHeader("\tAll Users in System", "\tAll Informations");
        vector <clsUser> vUsers= clsUser::GetUsersList();

        cout << "\n\t\t\t\t\t\tUsers List (" << vUsers.size() << ") Users(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}


};