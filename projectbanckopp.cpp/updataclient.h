#pragma once
#ifndef VALIDATE_H
#define VALIDATA_H
#include <iostream>
#include"clsscreen.h"
#include"clsinputvalidate.h"
#include"clsfindclients.h"
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;

class updatclient:protected clsscreen{

     private:
   static  void print(clsbank i){
       cout<<"---------------------------"<<endl;
        cout<<"first name:"<<i.getfirst()<<endl;
        cout<<"list name :"<<i.getlist()<<endl;
        cout<<"full name :"<<i.fullname()<<endl;
        cout<<"email :"<<i.getemail()<<endl;
        cout<<"phone :"<<i.getphone()<<endl;
            cout<<"account number:"<<i.getaccountbalance()<<endl;
            cout<<"account balance:"<<i.getaccountnumber()<<endl;
            cout<<"pincode:"<<i.getpincode();
        }

    public:


static void updatclientinfile(){
    if(!checkper(clsuser::enPermissions::pUpdateClients)){
    return;
}
    string account;
    cout<<"please enter the account number"<<endl;
    account=clsvalidate::readstring();
    while(!clsbank::isclientexit(account)){
        cout<<"please enter account agin "<<endl;
        account=clsvalidate::readstring();
    }
    clsbank client=clsbank::Find(account);
    print(client);

    cout<<"\n\nupdate client\n";
    cout<<"\n\n-----------------\n\n";

    clsbank::readclient(client);

    clsbank::enSaveResults saveresult;
    saveresult=client.Save();

    switch(saveresult){
        case clsbank::enSaveResults::svSucceeded:{
        cout<<"\naccount updata successfly"<<endl;
        print(client);
        break;}

        case clsbank::enSaveResults::svFaildEmptyObject:{
            cout<<"\n error account is not save\n";
        }

    }

}




};




#endif