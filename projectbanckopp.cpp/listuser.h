#pragma once
#ifndef LISTUSER_H
#define LISTUSER_H
#include <iostream>
#include"clsscreen.h"
#include"clsuser.h"
#include<iomanip>
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;

class listuser:protected clsscreen{
    public:

static  void printuser(clsuser client){
     cout<<setw(15)<<client.getfirst();
        cout<<setw(15)<<client.getlist();
        cout<<setw(35)<<client.getemail();
        cout<<setw(22)<<client.getphone();
        cout<<setw(20)<<client.getname();
        cout<<setw(20)<<client.getpassword();
        cout<<setw(12)<<client.getpermission();
}

 static void showclient(){
    vector<clsuser>vclient=clsuser::getclientlist();

    clsscreen::_drawscreenheader("\t client list screen");
cout<<"ppppp"<<endl;
    cout<<"\n\t\t\t client list("<<vclient.size()<<")"<<endl;
    cout<<"\n--------------------------------------------------------------------------\n"<<endl;
    cout<<"|"<<left<<setw(15)<<"first name";
     cout<<"|"<<left<<setw(15)<<"list name";
      cout<<"|"<<left<<setw(35)<<"email";
       cout<<"|"<<left<<setw(18)<<"phone";
        cout<<"|"<<left<<setw(12)<<"name";
         cout<<"|"<<left<<setw(12)<<"password";
         cout<<"|"<<left<<setw(12)<<"permission";
         cout<<"\n-----------------------------------------------------------------------\n"<<endl;
         if(vclient.size()==0){
            cout<<"no client in the file";
         }
         else{
            for(clsuser& i:vclient){
                printuser(i);
                cout<<endl;
            }
         }
}




};

#endif