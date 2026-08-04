#pragma once
#ifndef VALIDATE_H
#define VALIDATA_H
#include <iostream>
#include"data.h"
#include<ctime>
# include<cmath>
#include<vector>
class clsvalidate{
    public:
static bool isnumberbetwen(int number,int from,int to ){
    for(int i=from;i<=to;i++){
        if(number==i){
            return true;
        }
    }
    return false;
}


static bool isnumberbetwen(double number,double from,double to ){
return (number>=from&&number<=to);
}

static bool IsDateBetween(clsdata Date, clsdata From, clsdata To)
	{
		//Date>=From && Date<=To
		if ((clsdata::checkdataafter(Date, From) ||clsdata:: IsDate1EqualDate2(Date, From)) 
			&&
			(clsdata::comper(Date, To) ||clsdata:: IsDate1EqualDate2(Date, To)))
		{
			return true;
		}
		
		//Date>=To && Date<=From
		if ((clsdata::checkdataafter(Date, To) ||clsdata:: IsDate1EqualDate2(Date, To)) 
			&&
			(clsdata::comper(Date, From) ||clsdata:: IsDate1EqualDate2(Date, From)))
		{
			return true;
		}

		return false;
	}

    static int readintnumber(){
        int num;
        cout<<"please enter the number"<<endl;
        cin>>num;
        while(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"invalid number ,please enter the number agin"<<endl;
            cin>>num;
        }
        return num;
    }

    
    static double readdoublenumber(){
        double num;
        cout<<"please enter the number"<<endl;
        cin>>num;
        while(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"invalid number ,please enter the number agin"<<endl;
            cin>>num;
        }
        return num;
    }

    static int readintnumberbetween(int to,int from){
        int num;
        cout<<"please enter the number"<<endl;
        cin>>num;
        while((num<to)||(num>from)){
            cout<<"please enter the number please"<<endl;
            cin>>num;
        }
        return num;
        }

        
    static double readdoublenumberbetween(int to,int from){
        double num;
        cout<<"please enter the number"<<endl;
        cin>>num;
        while((num<to)||(num>from)){
            cout<<"please enter the number please"<<endl;
            cin>>num;
        }
        return num;
        }

        static string readstring(){
            string s;
            
            cin>>s;
            return s;
        }

};


#endif