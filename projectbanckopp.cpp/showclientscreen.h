#pragma once
#ifndef SHOWCLIENTSCREEN_H
#define SHOWCLIENTSCREEN_H
#include <iostream>
#include"clsscreen.h"
#include"clsfindclients.h"
#include"clsuser.h"
#include<iomanip>
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;

class showclientlist:protected clsscreen{
    public:

static  void printclient(clsbank i){
    cout<<"|"<<setw(15)<<left<<i.getaccountnumber();
     cout<<"|"<<setw(20)<<left<<i.fullname();
      cout<<"|"<<setw(12)<<left<<i._phone;
       cout<<"|"<<setw(20)<<left<<i._email;
        cout<<"|"<<setw(10)<<left<<i.getpincode();
         cout<<"|"<<setw(12)<<left<<i.getaccountbalance();
}

 static void showclient(){

if(!checkper(clsuser::enPermissions::pListClients)){
    return;
}

    vector<clsbank>vclient=clsbank::getclientlist();

    clsscreen::_drawscreenheader("\t client list screen");

    cout<<"\n\t\t\t client list("<<vclient.size()<<")"<<endl;
    cout<<"\n---------------------------\n"<<endl;
    cout<<"|"<<left<<setw(15)<<"account number";
     cout<<"|"<<left<<setw(20)<<"full num";
      cout<<"|"<<left<<setw(12)<<"phone";
       cout<<"|"<<left<<setw(20)<<"email";
        cout<<"|"<<left<<setw(10)<<"pincode";
         cout<<"|"<<left<<setw(12)<<"account balance";
         cout<<"\n--------------------------\n"<<endl;
         if(vclient.size()==0){
            cout<<"no client in the file";
         }
         else{
            for(clsbank i:vclient){
                printclient(i);
                cout<<endl;
            }
         }
}




};

#endif