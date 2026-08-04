#pragma once
#ifndef LOGINBANK_H
#define LOGINBANK_H
#include <iostream>
#include"clsuser.h"
#include"clsmanmenu.h"
#include"clsscreen.h"
#include"globel.h"

using namespace std;



class clslog:protected clsscreen{

private:

 static bool login(){
    string password;
    string name;
    bool loginfail=false;
    int count=0;

    do{

        if(loginfail){
            count++;
            cout<<"invalid user name/password"<<endl;
            cout<<"you have"<<(3-count)<<"trais in user"<<endl;
        }
        if(count==3){
            cout<<"you arelocked after 3 trais"<<endl;
            return false;
        }

        cout<<"plea enter user name"<<endl;
        cin>>name;

        cout<<"please enter password"<<endl;
        cin>>password;

        currint=clsuser::find(name,password);

        loginfail=currint.isempty();

    }
    while(loginfail);
     currint.addusernew();
    clsmanmenu::ShowMainMenue();
   
    return true;
}

public:
static bool _log(){
clsscreen::_drawscreenheader("\t login in bank");
return login();
}

};


#endif