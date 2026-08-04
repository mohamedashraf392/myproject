#pragma once
#ifndef LISTREGIST_H
#define LISTREGIST_H
#include <iostream>
#include"clsscreen.h"
#include"clsuser.h"
#include<iomanip>
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;

class listregist:protected clsscreen{
    public:

static  void printuser(clsuser::logregist client){
     cout<<setw(15)<<client.dat;
        cout<<setw(22)<<client.user;
        cout<<setw(37)<<client.password;
        cout<<setw(22)<<client.permission;
}

 static void showregist(){
       if(!checkper(clsuser::enPermissions::pLogRegist)){
    return;
}
   clsscreen::_drawscreenheader("\t user list regist");


      vector <clsuser::logregist> vClients=clsuser::_LoadClientsDataFromFileinregist();
    cout<<"\n\t\t\t client list("<<vClients.size()<<")"<<endl;
    cout<<"\n--------------------------------------------------------------------------\n"<<endl;
    cout<<"|"<<left<<setw(15)<<"data/time";
     cout<<"|"<<left<<setw(22)<<"user";
      cout<<"|"<<left<<setw(37)<<"password";
         cout<<"|"<<left<<setw(22)<<"permission";
         cout<<"\n-----------------------------------------------------------------------\n"<<endl;
         if(vClients.size()==0){
            cout<<"no client in the file";
         }
         else{
            for(clsuser::logregist& i:vClients){
                printuser(i);
                cout<<endl;
            }
         }
}


};

#endif