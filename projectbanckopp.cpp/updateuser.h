#pragma once
#ifndef VALIDATE_H
#define VALIDATA_H
#include <iostream>
#include"clsscreen.h"
#include"clsinputvalidate.h"
#include"clsuser.h"
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;

class updatuser:protected clsscreen{

     private:
   static void print(clsuser client){
        cout<<"first name is:"<<client.getfirst()<<endl;
        cout<<"list name is:"<<client.getlist()<<endl;
        cout<<"email name is:"<<client.getemail()<<endl;
        cout<<"phone name is:"<<client.getphone()<<endl;
        cout<<"name is:"<<client.getname()<<endl;
        cout<<" password is:"<<client.getpassword()<<endl;
        cout<<"permission is:"<<client.getpermission()<<endl;

    }

    public:


static void updatuserinfile(){
    string account;
    cout<<"please enter the pass word"<<endl;
    account=clsvalidate::readstring();
    while(!clsuser::userfind(account)){
        cout<<"please enter account agin "<<endl;
        account=clsvalidate::readstring();
    }
    clsuser client=clsuser::find(account);
    print(client);

    cout<<"\n\nupdate client\n";
    cout<<"\n\n-----------------\n\n";

    clsuser::readclient(client,account);

    clsuser::enSaveResults saveresult;
    saveresult=client.Save();

    switch(saveresult){
        case clsuser::enSaveResults::svSucceeded:{
        cout<<"\naccount updata successfly"<<endl;
        print(client);
        break;}

        case clsuser::enSaveResults::svFaildEmptyObject:{
            cout<<"\n error account is not save\n";
        }

    }

}




};




#endif