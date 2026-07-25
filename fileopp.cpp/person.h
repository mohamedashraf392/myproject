
#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;
class person{
    private:
    int _id;
    string _first;
    string _list;
    string _email;
    string _phone;

    public:

    person(){

    }
    person(int id,string first,string list,string email,string phone){
        _id=id;
        _first=first;
        _list=list;
        _email=email;
        _phone=phone;
    }

    int getid(){
        return _id;
    }

    void setfirst(string name){
        _first=name;
    }

    string getfirst(){
        return _first;
    }

    
    void setlist(string name){
        _list=name;
    }

    string getlist(){
        return _list;
    }

    
    void setenail(string email){
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
        return _first+" "+_list;
    }

    void print(){
        cout<<"---------------------------"<<endl;
        cout<<"id :"<<_id<<endl;
        cout<<"first name:"<<_first<<endl;
        cout<<"list name :"<<_list<<endl;
        cout<<"full name :"<<fullname()<<endl;
        cout<<"email :"<<_email<<endl;
        cout<<"phone :"<<_phone<<endl;
        cout<<"----------------------------"<<endl;
    }

    void sendemail(string sub,string body){
        cout<<"message send successfully: "<<_email<<endl;
        cout<<"subjet:"<<sub<<endl;
        cout<<"body:"<<body<<endl;
    }

    void sendsms(string message){
        cout<<"sms send successfully: "<<_phone<<endl;
        cout<<message;
    }
};

#endif