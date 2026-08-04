#pragma once
#ifndef ADDUSER_H
#define ADDUSER_H
#include <iostream>
#include"clsinputvalidate.h"
#include"clsscreen.h"
#include"clsuser.h"
#include<iomanip>
#include<ctime>
#include<fstream>
# include<cmath>
#include<vector>
using namespace std;

class adduser:protected clsscreen{
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

static void addusernew(){
cout<<"please enter the user name"<<endl;
string account=clsvalidate::readstring();

while(clsuser::userfind(account)){
    cout<<"please enter the user name agin"<<endl;
    string account=clsvalidate::readstring();
}

clsuser user=clsuser::getaddnew(account);

clsuser::readclient(user,account);

clsuser::enSaveResults savecls;
savecls=user.Save();
switch(savecls){
    case clsuser::enSaveResults::svSucceeded:{
        cout<<"succssud"<<endl;
        printuser(user);
        break;
    }

     case clsuser::enSaveResults::svFaildEmptyObject:{
        cout<<"error in file"<<endl;
    }

     case clsuser::enSaveResults::failaccountnumberexit:{
        cout<<"error in file"<<endl;
    }
    
    
} 




}


};






#endif