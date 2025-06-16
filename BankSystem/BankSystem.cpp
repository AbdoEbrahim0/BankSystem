//https://youtu.be/oCvb-Q5lXb8
// https://youtu.be/oCvb-Q5lXb8
//just try to check pull from visual studio 
// after pulling
//edit on my pull request locally then add to repo 
//edit from my repo then add to local machine only ttrough [fetch] 

//ProgrammingAdvices.com
//Mohmammed Abu-Hadhoud
#include <iostream>
#include <iomanip>
#include "clsBankClientOnMyOwn.h"
#include "clsUtil.h"
//#include "clsMainScreen.h" //hide
#include "clsUser.h"
#include "clsLoginScreen.h"
#include "Global.h"
//2nd video

void ReadClientInfo(clsBankClientOnMyOwn& myclinet)
{
    cout << "\nBEFORE EDIT ::\n" << endl;
    myclinet.Print();
    string temp = "";
    cout << "\nF.Name: ";
    cin >> temp;   myclinet.FirstName = temp;
    cout << "\nL.Name: ";
    cin >> temp; myclinet.LastName = temp;
    cout << "\nEmail: ";
    cin >> temp; myclinet.Email = temp;
    cout << "\nPhone: ";
    cin >> temp; myclinet.Phone = temp;
    cout << "\nPinCode: ";
    cin >> temp; myclinet.PinCode = temp;
    cout << "\nAccountBalance  ";  myclinet.AccountBalance = clsInputValidate::ReadDblNumber();
    cout << "\n Results After EDIT ::\n" << endl;
    myclinet.Print();

}
    //my wrong naive approch 
//void _Update()
//{
//    cout << "Enter Account number to update Info: ";
//    string s = clsInputValidate::ReadString();
//
//    while (!clsBankClientOnMyOwn:: IsClientExist(s))
//    {
//        s = clsInputValidate::ReadString("invalid account number please try another account exist: ");
//
//    }
//    clsBankClientOnMyOwn clientToEdit = clsBankClientOnMyOwn:: Find(s);
//    ReadClientInfo(clientToEdit);
//    clsBankClientOnMyOwn AfterEdit= clientToEdit.Save();
//}
//2nd Video
void UpdateClient()
{
    cout << "Enter Account number to update Info: ";
    string s = clsInputValidate::ReadString();

    while (!clsBankClientOnMyOwn::IsClientExist(s))
    {
        cout << "invalid account number please try another account exist: \n";
        s = clsInputValidate::ReadString();

    }
    clsBankClientOnMyOwn clientToEdit = clsBankClientOnMyOwn::Find(s);
    ReadClientInfo(clientToEdit);
    clientToEdit.Save();
}
//3rd Video
void AddNewClient()
{
    cout << "Enter Acount number of a new Client you want to add to databse\n";
    string accNum = clsInputValidate::ReadString();
    while (clsBankClientOnMyOwn::IsClientExist(accNum))
    {
        cout << "Account Number You enter Exist in database  try another one: \n";
        accNum = clsInputValidate::ReadString();
    }
    clsBankClientOnMyOwn NewClient=clsBankClientOnMyOwn::GetAddNewClientObject(accNum);
    
    ReadClientInfo(NewClient);

    clsBankClientOnMyOwn::enSaveResults SaveResults;
    SaveResults = NewClient.Save();
    if (SaveResults == clsBankClientOnMyOwn::enSaveResults::svSucceeded)
    {
        cout << "new account Added succesfully To databse" << endl;
        NewClient.Print();
    }
    else if (SaveResults == clsBankClientOnMyOwn::enSaveResults::svFailEmptyObject)
    {
    
        cout << "\nError account was not saved because it's Empty";
    }
    else if (SaveResults == clsBankClientOnMyOwn::enSaveResults::svFaildAccountNumberExist)
    {
        cout << "faid to add to database The Account Number is exist already\n";
    }
        
}
//4th Video
void DeleteClient()
{
    cout << "what Client Account Number Do You want To delete ? Enter acc number\n";
    string Acc= clsInputValidate::ReadString();
    
    while( !clsBankClientOnMyOwn::IsClientExist(Acc))
    {
        cout << "You entered Wrong Acc Number try Again:";
        Acc = clsInputValidate::ReadString();
    }
    clsBankClientOnMyOwn clientToBeDeleted = clsBankClientOnMyOwn::Find(Acc);
    clientToBeDeleted.Print();
    cout << "Are you sure you want to delete client with Acc. number" << Acc << " Y/N ?\n";
    char ans;
    cin >> ans;
    if (ans == 'y' || ans == 'Y')
    {
        
        if (clientToBeDeleted.Delete())
        {
            cout << "Client Removed Successfully\n";
            
            clientToBeDeleted.Print();
        }   
        else
        {
            cout << " error Client was not Removed from the System\n";
        }
    }
    else
    {
        cout << "clients still exist in the system\n";
    }
}
//5th video 
void PrintClientRecordLine(clsBankClientOnMyOwn Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(20) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(20) << left << Client.Email;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(12) << left << Client.AccountBalance;

}

void ShowClientsList()
{

    vector <clsBankClientOnMyOwn> vClients = clsBankClientOnMyOwn::GetClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClientOnMyOwn Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

void PrintClientRecordBalanceLine(clsBankClientOnMyOwn Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(40) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.AccountBalance;

}
void ShowTotalBalances()
{
    vector<clsBankClientOnMyOwn> VClients = clsBankClientOnMyOwn::_LoadClientsDataFromFile();
    
        cout << "\n\t\t\t\t\tBalances List (" << VClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double  TotalBalances=clsBankClientOnMyOwn::GetTotalBalances(VClients);

    for (clsBankClientOnMyOwn &Client : VClients)
    {
        PrintClientRecordBalanceLine(Client);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
    cout << "\t\t\t\t\t   ( " << clsUtil ::NumberToText(TotalBalances) << ")";
}
int main()

{
//1st video

    //clsBankClientOnMyOwn Client1 = clsBankClientOnMyOwn::Find("A101");
    //if (!Client1.IsEmpty())
    //{
    //    cout << "\nClient Found :-)\n";
    //}
    //else
    //{
    //    cout << "\nClient Was not Found :-(\n";
    //}
    //Client1.Print();
    //clsBankClientOnMyOwn Client2 = clsBankClientOnMyOwn::Find("A101", "1234");
    //if (!Client2.IsEmpty())
    //{
    //    cout << "\nClient Found :-)\n";
    //}
    //else
    //{
    //    cout << "\nClient Was not Found :-(\n";
    //}
    //Client2.Print();
    //cout << "\nIs Client Exist? " << clsBankClientOnMyOwn::IsClientExist("A101");
    //cout << "\nIs Client Exist? " << clsBankClientOnMyOwn::IsClientExist("A105115");

//2nd video
    // this my naive way it forced my to declare object without need all what was asked was update fn in main
    // if you go in implemenation of naive you will see that you type find fun twice
    //my wrong naive approch 
        //clsBankClientOnMyOwn clientToUpdate= clsBankClientOnMyOwn::_GetEmptyClientObject2();// static fn only can call static fn 
        //clientToUpdate._Update2();
    // the correct way 
        //UpdateClient();
//3rd video
        //AddNewClient();
//4th video
    //DeleteClient();

//5th video
    //ShowClientsList();
//6th video
    //ShowTotalBalances();


//lesson 7
    //clsMainScreen::ShowMainMenu();

//lessong 24
    while (true)
    {
        clsLoginScreen::ShowLoginScreen();
    }
    

    
    
    
    
system("pause>0");
    return 0;
}
