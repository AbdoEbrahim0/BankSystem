#pragma once
#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsUser.h"
class clsDeleteUserScreen :protected clsScreen
{

private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }
public:
	static void ShowDeleteUserScreen()
	{
        clsScreen::_DrawScreenHeader("\tDeleting User From The System");
        cout << "Which Users Do You want To delete ? Enter User Name\n";
        string UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "You entered Wrong User Name try Again:";
            UserName = clsInputValidate::ReadString();
        }
        clsUser UserToBeDeleted = clsUser::Find(UserName);
        //UserToBeDeleted.Print(); seperate UI from any object businuess
        _PrintUser(UserToBeDeleted);
        cout << "Are you sure you want to delete User with User Name : " << UserName<< " Y/N ?\n";
        char ans='n';
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {

            if (UserToBeDeleted.Delete())
            {
                cout << "User Removed Successfully\n";
                _PrintUser(UserToBeDeleted);
                //UserToBeDeleted.Print();
            }
            else
            {
                cout << " error User was not Removed from the System\n";
            }
        }
        else
        {
            cout << "User still exist in the system\n";
        }
	}

};
