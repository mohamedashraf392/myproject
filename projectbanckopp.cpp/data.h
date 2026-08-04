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
    int _hour;
    int _mintus;
    int _second;
    public:

    clsdata(){
    
        time_t t=time(0);
        tm*now=localtime(&t);
        _day=now->tm_mday;
        _month=now->tm_mon+1;
        _year=now->tm_year+1900;
    }

    clsdata(int d,int m,int y,int i,int p,int c){
        _day=d;
        _month=m;
        _year=y;
        _hour=i;
        _mintus=p;
        _second=c;

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

int getmonth(){
    return _month;
}


void setyear(int x){
    _year=x;
}

int getyear(){
    return _year;
}

void sethour(int x){
    _hour=x;
}

int gethour(){
    return _hour;
}
void setsecond(int x){
    _second=x;
}

int getsecond(){
    return _second;
}

void setmints(int x){
    _mintus=x;
}

int getmintus(){
    return _mintus;
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
static clsdata getsystemday(){
    clsdata d;
    time_t t = time(0);
     tm* now = localtime(&t);
     d._year = now->tm_year + 1900;
     d._month = now->tm_mon + 1;
     d._day = now->tm_mday;
     d._hour=now->tm_hour;
     d._mintus=now->tm_min;
     d._second=now->tm_sec;
     return d;
   }
static void showdat(){
    clsdata d;
    clsdata::getsystemday();
    cout<<d._day<<"/"<<d._month<<"/"<<d._year;
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




 static string NumberToText(int Number){
    if (Number == 0)
{
return "";
}

if (Number >= 1 && Number <= 19)
{
string arr[] = { "",
"One","Two","Three","Four","Five","Six","Seven",
"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
return arr[Number] + " ";
}

if (Number >= 20 && Number <= 99)
{
string arr[] = {
"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty"
,"Ninety" };
return arr[Number / 10] + " " + NumberToText(Number % 10);
}

/*if (Number >= 100 && Number <= 199)
{
return "One Hundred " + NumberToText(Number % 100);
}*/

if (Number >= 100 && Number <= 999)
{
return NumberToText(Number / 100) + "Hundred " +
NumberToText(Number % 100);
}

/*if (Number >= 1000 && Number <= 1999)
{
return "One Thousand " + NumberToText(Number % 1000);
}*/

if (Number >= 1000 && Number <= 999999)
{
return NumberToText(Number / 1000) + "Thousand " +
NumberToText(Number % 1000);
}

/*if (Number >= 1000000 && Number <= 1999999)
{
return "One Million " + NumberToText(Number % 1000000);
}*/

if (Number >= 1000000 && Number <= 999999999)
{
return NumberToText(Number / 1000000) + "Millions" +
NumberToText(Number % 1000000);
}

if (Number >= 1000000000 && Number <= 1999999999)
{
return "One Billion " + NumberToText(Number %
1000000000);
}
else
{
return NumberToText(Number / 1000000000) + "Billions " +
NumberToText(Number % 1000000000);
}
}

	


};


#endif