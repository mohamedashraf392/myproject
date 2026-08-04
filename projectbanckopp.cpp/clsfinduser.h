#pragma once
#ifndef CLSfinduser_H
#define CLSfinduser_H
#include <iostream>
#include"clsscreen.h"
#include"clsinputvalidate.h"
#include"clsuser.h"
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;


class finduser:protected clsscreen{
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

static void finduserinfile(){
 clsscreen::_drawscreenheader("/tfind user");
 cout<<"please enter account number"<<endl;
string pass;
pass=clsvalidate::readstring();
if(!clsuser::userfind(pass)){
  pass=clsvalidate::readstring();  
}

clsuser user=clsuser::find(pass);
print(user);
}
};








#endif


