#pragma once
#ifndef DELETUSER_H
#define DELETUSER_H
#include <iostream>
#include"clsscreen.h"
#include"clsinputvalidate.h"
#include"clsuser.h"
#include<iomanip>
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;


class deletuser:protected clsscreen  
{

   private:
   
static  void printuser(clsuser client){
     cout<<setw(15)<<client.getfirst();
        cout<<setw(15)<<client.getlist();
        cout<<setw(35)<<client.getemail();
        cout<<setw(22)<<client.getphone();
        cout<<setw(20)<<client.getname();
        cout<<setw(20)<<client.getpassword();
        cout<<setw(12)<<client.getpermission();
}


    public:
 static void deletuserinfile(){
    clsscreen::_drawscreenheader("\n\t\t\t\t\t\t delete account");

    string account;
    cout<<"please enter the account "<<endl;
    account=clsvalidate::readstring();
    while(!clsuser::userfind(account)){
        cout<<"please enter account agin "<<endl;
        account=clsvalidate::readstring();
    }
    clsuser user=clsuser::find(account);
    printuser(user);
    cout<<endl;
    cout<<"are you sure you want to delete this client [y/n]"<<endl;
    char x='n';
    cin>>x;
    if(x=='y'||x=='Y'){
      if(user.deleteclient()){
        cout<<"client delete"<<endl;
        printuser(user);
      }
      else{
        cout<<"erro client not find";
      }
    }
}

};




#endif