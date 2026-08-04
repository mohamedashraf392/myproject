#pragma once
#ifndef MANGEUSERSCREEN_H
#define MANGEUSERSCREEN_H
#include <iostream>
#include"clsinputvalidate.h"
#include"clsscreen.h"
#include"clsfinduser.h"
#include"listuser.h"
#include"updateuser.h"
#include"adduser.h"
#include"deletuser.h"
#include<iomanip>
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;
class clsmangeuser:protected clsscreen
{   


  private:
        enum enMainMenueOptions {
            listuser=1,adduser=2,deleteuser=3,updatuser=4,finduser=5,mainmenue=6};

     static   int _ReadMainMenueOptionmanageuser(){
            cout<<setw(37)<<left<<"choce whate do you went do?[1]to[6]"<<endl;
           int choice= clsvalidate::readintnumberbetween(1,6);
           return choice;
        }

         static  void _GoBackTomangemenue()
        {
            cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
            system("pause>0");
            ShowMainMenuemangeuser();
        }

         
       static void _list()
       {
        listuser::showclient();

       }


       static void _add()
       {
    adduser::addusernew();
       }


       static void _delete()
       {
    deletuser::deletuserinfile();
       }

        static void _update()
       {
     updatuser::updatuserinfile();
       }


       static void _find()
       {
      finduser::finduserinfile();
       }



           static void _PerfromMainMenueOptiontran(enMainMenueOptions MainMenueOption)
        {
            switch (MainMenueOption)
            {
            case enMainMenueOptions::listuser:
            {
                system("cls");
             _list();
                _GoBackTomangemenue();
                break;
            }
            case enMainMenueOptions::adduser:{
                system("cls");
             _add();
                _GoBackTomangemenue();
                break;}

            case enMainMenueOptions::deleteuser:{
                system("cls");
                _delete;
                _GoBackTomangemenue();
                break;
            }

              case enMainMenueOptions::updatuser:
            {
                system("cls");
             _update();
                _GoBackTomangemenue();
                break;
            }
            case enMainMenueOptions::finduser:{
                system("cls");
             _find();
                _GoBackTomangemenue();
                break;}

             case enMainMenueOptions::mainmenue:{  
                
            }

          
        }
    }

	public:
       static void ShowMainMenuemangeuser()
        {
           if(!checkper(clsuser::enPermissions::pManageUsers)){
    return;
}
            system("cls");
            _drawscreenheader("\t\tmanage user");

            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] list user.\n";
            cout << setw(37) << left << "" << "\t[2] add user.\n";
            cout << setw(37) << left << "" << "\t[3] delete user.\n";
             cout << setw(37) << left << "" << "\t[4] update user.\n";
              cout << setw(37) << left << "" << "\t[5] find user.\n";
             cout << setw(37) << left << "" << "\t[6] go to main menue Client.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromMainMenueOptiontran((enMainMenueOptions)_ReadMainMenueOptionmanageuser());
        }


};







#endif