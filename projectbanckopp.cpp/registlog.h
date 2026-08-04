#pragma once
#ifndef LISTREGIST_H
#define LISTREGIST_H
#include <iostream>
#include"clsscreen.h"
#include"clsfindclients.h"
#include<iomanip>
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;

class listregist:protected clsscreen{
    public:

static  void printuser(clsbank::logregist client){
     cout<<setw(15)<<client.dat;
        cout<<setw(20)<<client.account1;
        cout<<setw(12)<<client.account2;
        cout<<setw(20)<<client.accountbalance1;
           cout<<setw(20)<<client.accountbalance2;
              cout<<setw(12)<<client.balance;
                cout<<setw(10)<<client.fullname;
}

 static void showregist(){
     /*  if(!checkper(clsuser::enPermissions::pLogRegist)){
    return;
}*/
   clsscreen::_drawscreenheader("\t user list regist");


      vector <clsbank::logregist> vClients=clsbank::_LoadClientsDataFromFileinregist();
    cout<<"\n\t\t\t client list("<<vClients.size()<<")"<<endl;
    cout<<"\n--------------------------------------------------------------------------\n"<<endl;
    cout<<"|"<<left<<setw(15)<<"data/time";
     cout<<"|"<<left<<setw(20)<<"account1";
      cout<<"|"<<left<<setw(12)<<"account2";
         cout<<"|"<<left<<setw(20)<<"accountbalance1";
         cout<<"|"<<left<<setw(20)<<"accountbalance2";
         cout<<"|"<<left<<setw(12)<<"balance";
         cout<<"|"<<left<<setw(10)<<"name";
         cout<<"\n-----------------------------------------------------------------------\n"<<endl;
         if(vClients.size()==0){
            cout<<"no client in the file";
         }
         else{
            for(clsbank::logregist& i:vClients){
                printuser(i);
                cout<<endl;
            }
         }
}


};

#endif