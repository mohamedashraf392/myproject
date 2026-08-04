#pragma once
#ifndef INTERFACECOMMUNICATION_H
#define INTERFACECOMMUNICATION_H
#include <iostream>
#include<iomanip>
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;

class interfacecommunication{
    public:
virtual void sendemail(string title,string body )=0;
virtual void sendfax(string title,string body )=0;
virtual void sendsms(string title,string body )=0;

};
#endif