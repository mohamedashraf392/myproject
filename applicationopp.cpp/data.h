#pragma once
#ifndef DATA_H
#define DATA_H
#include <iostream>
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;
class clsdata{
    private:
    int _day;
    int _month;
    int _year;
    public:

    clsdata(){
    
        time_t t=time(0);
        tm*now=localtime(&t);
        _day=now->tm_mday;
        _month=now->tm_mon+1;
        _year=now->tm_year+1900;
    }

    clsdata(int d,int m,int y){
        _day=d;
        _month=m;
        _year=y;

    }

    clsdata(string s){
        _day=stoi(s.substr(0,2));
        _month=stoi(s.substr(3,2));
        _year=stoi(s.substr(6,4));

    }


bool leapyear(int year){
return((year%400==0||(year%4==0&&year%100!=0))?true:false);
}

int numberofday(int month,int year){
    if(month<1||month>12){
        return 0;
    }
    int arr[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    return(month==2?(leapyear(year)?29:28):arr[month]);
}

clsdata(int day,int year){
    int month=1;
    int numberday=day;
    int numbermonth=numberofday(month,year);
  
    while(numberday>numbermonth){
        month++;
        numberday-=numbermonth;
         numbermonth=numberofday(month,year);
    }
    _year=year;
    _month=month;
    _day=numberday;
}
void setday(int x){
    _day=x;
}

int getday(){
    return _day;
}


void setmonth(int x){
    _month=x;
}

int getname(){
    return _month;
}


void setyear(int x){
    _year=x;
}

int getyear(){
    return _year;
}

void print(){
    cout<<_day<<"/"<<_month<<"/"<<_year<<endl;
}

//calender of month

int showday(int day,int month,int year){
    int a,b,c,d;
    a=((14-month)/12);
    b=year-a;
    c=month+(12*a)-2;
    d=(day+b+(b/4)-(b/100)+(b/400)+((31*c)/12))%7;
    return d;
}

string showmonth(int x){
    string month[12] = { "Jan", "Feb", "Mar",
"Apr", "May", "Jun",
"Jul", "Aug", "Sep",
"Oct", "Nov", "Dec"};
return month[x-1];
}

void printcalender(int month ,int year){
int currint=showday(1,month,year);
int x=numberofday(month,year);
    printf("\n _______________%s_______________\n\n",showmonth(month).c_str());

printf(" Sun Mon Tue Wed Thu Fri Sat\n");
int i=0;
    for(i=0;i<currint;i++){
      printf("    ");
    }
    for(int j=1;j<=x;j++){
     printf("%4d", j);
     i++;
     if(i==7){
    i=0;
    cout<<endl;
}
    }
printf("\n _________________________________\n");
}

void printcalender(){
    printcalender(_month,_year);
}

//all calender

void printallcalender()
{
    for(int i=1;i<=12;i++){
        printcalender(i,_year);
        cout<<endl;
    }
}

//vaild or not
int validday(int d,int m,int y){
    int numberday=numberofday(m,y);
    if(d>numberday){
        return 0;
    }
    else{
        return 1;
    }
}

int validday(){
    return validday(_day,_month,_year);
}
// equal day

static bool IsDate1EqualDate2(clsdata Date1, clsdata Date2)
{
return (Date1._year == Date2._year) ? ((Date1._month ==
Date2._month) ? ((Date1._day == Date2._day) ? true : false) : false)
: false;
}




//comper data 

 static bool comper(clsdata Date1,clsdata Date2){
    return (Date1._year < Date2._year) ? true : ((Date1._year ==
Date2._year) ? (Date1._month < Date2._month ? true : (Date1._month ==
Date2._month ? Date1._day < Date2._day : false)) : false);
}

bool comper(clsdata Date2){
    return comper(*this ,Date2);
}

//after data

static bool checkdataafter(clsdata d1, clsdata d2){

   return comper(d2,d1);
}




//number of day in year

bool leastday(clsdata d){
    int numberday=numberofday(d._month,d._year);
    return (numberday==d._day)?true:false;
}

bool leastmonth(clsdata d){
    return (d._month==12)?true:false;
}

clsdata increase(clsdata d){
    if(leastday(d)){
        if(leastmonth(d)){
            d._day=1;
            d._month=1;
            d._year+=1;
        }
        else{
            d._day=1;
            d._month+=1;
        }

    }
    else{
        d._day+=1;
    }
    return d;
}
clsdata getsystemday(){
    clsdata d;
    time_t t = time(0);
     tm* now = localtime(&t);
     d._year = now->tm_year + 1900;
     d._month = now->tm_mon + 1;
     d._day = now->tm_mday;
     return d;
}

int calcdifference(clsdata d1,clsdata d2,bool x=false){
    int number=0;
    while(comper(d1,d2)){
        number++;
        d1=increase(d1);
    }
    return (x)?++number:number;
}

int calcdifference(bool x=false){
    return calcdifference(*this,getsystemday(),x);
}



bool  IsDate1EqualDate2(clsdata Date2){
   return IsDate1EqualDate2(*this, Date2);

}

static void swapdata(clsdata& d,clsdata& d2){
    clsdata  temp;
    temp=d;
    d=d2;
    d2=temp;
}



	


};


#endif