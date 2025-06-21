#pragma once
#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"

class clsUpdateUserScreen :protected clsScreen
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
    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow User List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New User? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete User? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate User? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind User? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage User? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nLogin Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pShowLoginRegister;
        }
        return Permissions;

    }
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEdit FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEdit LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEdit Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEdit Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEdit Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEdit Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

public:
	static void ShowUpdateUserScreen()
	{
        clsScreen::_DrawScreenHeader(" Update Info Of User In The System");
        cout << "Enter User Name to update Info: ";
        string s = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(s))
        {
            cout << "invalid User Name please try another account exist: \n";
            s = clsInputValidate::ReadString();
        }
        clsUser UserToEdit = clsUser::Find(s);
        _ReadUserInfo(UserToEdit);
        UserToEdit.Save();
        _PrintUser(UserToEdit);
	}

};
