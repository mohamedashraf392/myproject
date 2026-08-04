#pragma once
#ifndef CLSMANMENU_H
#define CLSMANMENU_H
#include <iostream>
#include"clsscreen.h"
#include"clsinputvalidate.h"
#include"showclientscreen.h"
#include"addnewclient.h"
#include"updataclient.h"
#include"deleteclient.h"
#include"clsfindaccountnowfile.h"
#include"clsmainmenutranscatio.h"
#include"mangeuserscreen.h"
#include"globel.h"
#include"loginbank.h"
#include"listregist.h"
#include<iomanip>
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;
 //static void ShowMainMenue();

class clsmanmenu:protected clsscreen
{   


  private:
        enum enMainMenueOptions {
            eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
            eManageUsers = 7, eExit = 8,logrigst=9
        };

     static   int _ReadMainMenueOption(){
            cout<<setw(37)<<left<<"choce whate do you went do?[1]to[9]"<<endl;
           int choice= clsvalidate::readintnumberbetween(1,9);
           return choice;
        }

         static  void _GoBackToMainMenue()
        {
            cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
           
            system("pause>0");
            ShowMainMenue();
        }


         
       static void _ShowAllClientsScreen()
       {
        showclientlist::showclient();
       }

       static void _ShowAddNewClientsScreen()
       {
          addnewclient::addnewclientinfile();
       }

       static void _ShowDeleteClientScreen()
       {
           deletclient::deletclientinfile();
       }

       static void _ShowUpdateClientScreen()
       {
         
         updatclient::updatclientinfile();

       }

       static void _ShowFindClientScreen()
       {
     findaccount::findaccountnew();

       }

       static void _ShowTransactionsMenue()
       {
         clsmanmenurransaction::ShowMainMenuemangeuser();

       }

       static void _ShowManageUsersMenue()
       {
          clsmangeuser::ShowMainMenuemangeuser();

       }

       static void logout()
           {
               currint=clsuser::find("","");
               

           }
            static void loginregist()
           {
              cout<<"login regist"<<endl;
               listregist::showregist();

           }


           static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
        {
            switch (MainMenueOption)
            {
            case enMainMenueOptions::eListClients:
            {
                system("cls");
                _ShowAllClientsScreen();
                _GoBackToMainMenue();
                break;
            }
            case enMainMenueOptions::eAddNewClient:
                system("cls");
               _ShowAddNewClientsScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eDeleteClient:
                system("cls");
                _ShowDeleteClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eUpdateClient:
                system("cls");
                _ShowUpdateClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eFindClient:
                system("cls");
                _ShowFindClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eShowTransactionsMenue:
                system("cls");
                _ShowTransactionsMenue();
                 _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eManageUsers:
                system("cls");
                _ShowManageUsersMenue();
                 _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eExit:
                system("cls");
                logout();
                //Login();

                break;

                 case enMainMenueOptions::logrigst:
                system("cls");
                loginregist();
                 _GoBackToMainMenue();
                break;
            }

        }

	public:
       static void ShowMainMenue()
        {
           
            system("cls");
            _drawscreenheader("\t\tMain Screen");

            cout << setw(37) << left <<""<< "===========================================\n";
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
               cout << setw(37) << left << "" << "\t[9] Logregist.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
        }


};







#endif