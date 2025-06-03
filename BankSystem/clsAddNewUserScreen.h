#pragma once
#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsUser.h"

class clsAddNewUserScreen :protected clsScreen
{

private:
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

        return Permissions;

    }
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

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
	static void ShowAddNewUserScreen()
	{
        clsScreen::_DrawScreenHeader("Add New User ", "Enter All Required Data");
        string UserName = "";

        cout << "\nPlease Enter User Name: ";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name Is Already Used, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;
        SaveResult = NewUser.Save();
        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;
        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User was not saved because User Name is used!\n";
            break;

        }
        }
	}
};
