#pragma once
#ifndef CLSSCREEN_H
#define CLSSCREEN_H
#include <iostream>
#include"clsuser.h"
#include"globel.h"
#include"data.h"
using namespace std;

class clsscreen
{

    protected:
    static void _drawscreenheader(string header){
        cout<<"\t\t\t\t\t--------------------------";
        cout<<"\n\n\t\t\t\t\t"<<header;
        cout<<"\n\n\t\t\t\t\t-----------------------\n\n";
        cout<<"user:"<<currint.getname()<<endl;
        cout<<"data:";
        clsdata::showdat();
        cout<<endl;
    }

    static bool checkper(clsuser::enPermissions permision){

        if(!currint.ischeckaccesspermision(permision)){
             cout<<"\t\t\t\t----------------------------\t"<<endl;
            cout<<"\t\t\t\taccess denid"<<endl;
            cout<<"\t\t\t\t----------------------------\t"<<endl;
            return false;
        }
        else{
           
            return true;
        }






    }

};





#endif