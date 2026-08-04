#pragma once
#ifndef TOTALBALANCE_H
#define TOTALBALANCE_H
#include <iostream>
#include"clsscreen.h"
#include"clsinputvalidate.h"
#include"clsfindclients.h"
#include"showclientscreen.h"
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;

class totalbalance:protected clsscreen{


    public:


static void totalbalancenumber(){
    clsscreen::_drawscreenheader("\n\t\t\t\ttotalbalance in account/t");
    cout<<endl;
    showclientlist::showclient();
    cout<<endl;
    double totalbalance;
    totalbalance=clsbank::gettotalbalanc();
    cout<<"total balance is:"<<totalbalance;


}
};
#endif