#pragma once
#ifndef CLSPERSON_H
#define CLSPERSON_H
#include <iostream>
#include"interfacecommmincation.h"
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;

class clsperson:public interfacecommunication{
     public:
    string _firstname;
    string _listname;
    string _email;
    string _phone;

    public:

    clsperson(string f,string l,string e,string p){
        _firstname=f;
        _listname=l;
        _email=e;
        _phone=p;
    }


    

    void setfirst(string name){
        _firstname=name;
    }

    string getfirst(){
        return _firstname;
    }

    
    void setlist(string name){
        _listname=name;
    }

    string getlist(){
        return _listname;
    }

    
    void setemail(string email){
        _email=email;
    }

    string getemail(){
        return _email;
    }

    
    void setphone(string phone){
        _phone=phone;
    }

    string getphone(){
        return _phone;
    }


    
    string fullname(){
        return _firstname+" "+_listname;
    }

    void print(){
        cout<<"---------------------------"<<endl;
        cout<<"first name:"<<_firstname<<endl;
        cout<<"list name :"<<_listname<<endl;
        cout<<"full name :"<<fullname()<<endl;
        cout<<"email :"<<_email<<endl;
        cout<<"phone :"<<_phone<<endl;
      
    }

    void sendemail(string title,string body ){

    }

    void sendfax(string title,string body ){
       
    }       

    void sendsms(string title,string body ){
       
    }






};


#endif