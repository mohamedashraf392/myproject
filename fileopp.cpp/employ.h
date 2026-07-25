
#pragma once
#ifndef EMPLOY_H
#define EMPLOY_H
#include <iostream>
#include"person.h"
using namespace std;

class employ:public person{

private:
string _tital;
string _department;
int _salary;


public:

employ(int id,string first,string list,string email,string phone,string tital,string depart,int salary)
:person(id,first ,list,email,phone){
_tital=tital;
_department=depart;
_salary=salary;


}
    void settital(string tital){
        _tital=tital;
    }

    string gettital(){
        return _tital;
    }


    void setdepart(string depart){
        _department=depart;
    }

    string getdepart(){
        return _department;
    }


    void setsalary(int salar){
        _salary=salar;
    }

    int getsalar(){
        return _salary;
    }

    

    void print(){
        person::print();
        cout<<"tital is:"<<_tital<<endl;
        cout<<"department is:"<<_department<<endl;
        cout<<"salary is :"<<_salary<<endl;
      
    }
};



#endif