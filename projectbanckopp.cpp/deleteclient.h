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


class deletclient:protected clsscreen  
{

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
 static void deletclientinfile(){
  if(!checkper(clsuser::enPermissions::pDeleteClient)){
    return;
}
    clsscreen::_drawscreenheader("\n\t\t\t\t\t\t delete account");

    string account;
    cout<<"please enter the account number"<<endl;
    account=clsvalidate::readstring();
    while(!clsbank::isclientexit(account)){
        cout<<"please enter account agin "<<endl;
        account=clsvalidate::readstring();
    }
    clsbank client=clsbank::Find(account);
    print(client);
    cout<<endl;
    cout<<"are you sure you want to delete this client [y/n]"<<endl;
    char x='n';
    cin>>x;
    if(x=='y'||x=='Y'){
      if(client.deleteclient()){
        cout<<"client delete"<<endl;
        print(client);
      }
      else{
        cout<<"erro client not find";
      }
    }
}

};




#endif