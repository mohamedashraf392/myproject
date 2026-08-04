/*#pragma once
#ifndef FILEUSERSRESPONSIVE_H
#define FILEUSERSRESPONSIVE_H
#include <iostream>
#include"clsscreen.h"
#include"clsinputvalidate.h"
#include"clsuser.h"
#include"data.h"
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;

class user{

public:

string changedatatostring(clsuser i,string dlim="#//#"){

   string x;
   clsdata dat=clsdata::getsystemday();

   x=to_string(dat.getday())+"/";
   x+=to_string(dat.getmonth())+"/";
   x+=to_string(dat.getyear())+dlim;
   x+=i.getname()+dlim;
   x+=i.getpassword()+dlim;
   x+=to_string(i.getpermission())+dlim;
   return x;
}

 void _adddateinfile(string data){
        fstream myfile;
        myfile.open("userresponsive.txt",ios::out | ios::app);
        if(myfile.is_open()){
            myfile<<data;
        }
        myfile.close();

    }

    void adduser(){
        _adddateinfile(changedatatostring(*this));
    }








};







#endif*/