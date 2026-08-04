#pragma once
#ifndef WITHDROW_H
#define WITHDROW_H
#include <iostream>
#include"clsscreen.h"
#include"clsinputvalidate.h"
#include"clsfindclients.h"
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;

class withdrow:protected clsscreen{

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


static void withdrownumber(){
    clsscreen::_drawscreenheader("\n\t\t\t\twithdrownumber in account/t");
    string account;
    cout<<"please enter the account number"<<endl;
    account=clsvalidate::readstring();
    while(!clsbank::isclientexit(account)){
        cout<<"please enter account agin "<<endl;
        account=clsvalidate::readstring();
    }
    clsbank client=clsbank::Find(account);
    print(client);
    
    int number=clsvalidate::readintnumber();

   if(client.getwithdow(number)){
    cout<<"sucssufly with drow"<<endl;
   cout<<"with drow new is:"<<client.getaccountbalance();
   }
   else{
    cout<<"the ammount great then accountbalance";
   }

   
}
};
#endif