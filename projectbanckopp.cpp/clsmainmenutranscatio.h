#pragma once
#ifndef CLSMANMENUTRANSCATION_H
#define CLSMANMENUTRANSCATION_H
#include <iostream>
#include"clsinputvalidate.h"
#include"depost.h"
#include"withdrow.h"
#include"totalbalance.h"
#include"transferscreen.h"
#include"registlog.h"
#include<iomanip>
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;
class clsmanmenurransaction:protected clsscreen
{   


  private:
        enum enMainMenueOptions {
            depost = 1, withdrow = 2, totalbalance = 3,exit=4,transfer=5,transferlog=6};

     static   int _ReadMainMenueOptionmanageuser(){
            cout<<setw(37)<<left<<"choce whate do you went do?[1]to[6]"<<endl;
           int choice= clsvalidate::readintnumberbetween(1,6);
           return choice;
        }

         static  void _GoBackToMainMenuetransaction()
        {
            cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
            system("pause>0");
            ShowMainMenuemangeuser();
        }

         
       static void _list()
       {
      depost::depostnumber();
       }


       static void _add()
       {
         withdrow::withdrownumber();
       }


       static void _delete()
       {
        totalbalance::totalbalancenumber();
       }

          static void _transferscreen()
       {
        cout<<"transfer"<<endl;
        transfer::transferscreen();
       }

          static void _transferscreenlog()
       {
        cout<<"transfer"<<endl;
       listregist::showregist();
       }



           static void _PerfromMainMenueOptiontran(enMainMenueOptions MainMenueOption)
        {
            switch (MainMenueOption)
            {
            case enMainMenueOptions::depost:
            {
                system("cls");
             _list();
                _GoBackToMainMenuetransaction();
                break;
            }
            case enMainMenueOptions::withdrow:{
                system("cls");
             _add();
                _GoBackToMainMenuetransaction();
                break;}

            case enMainMenueOptions::totalbalance:{
                system("cls");
                _delete;
                _GoBackToMainMenuetransaction();
                break;
            }

             case enMainMenueOptions::exit:{  
                break;
            }

             case enMainMenueOptions::transfer:{
                system("cls");
                _transferscreen();
                _GoBackToMainMenuetransaction();
                break;
            }

            case enMainMenueOptions::transferlog:{
                system("cls");
                _transferscreenlog();
                _GoBackToMainMenuetransaction();
                break;
            }

          
        }
    }

	public:
       static void ShowMainMenuemangeuser()
        {
           if(!checkper(clsuser::enPermissions::pTranactions)){
    return;
}
            system("cls");
            _drawscreenheader("\t\tMain transaction");

            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] depost Client List.\n";
            cout << setw(37) << left << "" << "\t[2] withdrow New Client.\n";
            cout << setw(37) << left << "" << "\t[3] totalbalance Client.\n";
             cout << setw(37) << left << "" << "\t[4] go to main menue Client.\n";
             cout << setw(37) << left << "" << "\t[5] trancfer screen.\n";
              cout << setw(37) << left << "" << "\t[6] trancfer screen log show.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromMainMenueOptiontran((enMainMenueOptions)_ReadMainMenueOptionmanageuser());
        }


};







#endif