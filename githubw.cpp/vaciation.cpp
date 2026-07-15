#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
struct data{
    int day;
    int month;
    int year;
};
int readyear(){
    int x;
    cout<<"please enter the year"<<endl;
    cin>>x;
    return x;
}
int readmonth(){
    int x;
    cout<<"please enter the month"<<endl;
    cin>>x;
    return x;
}
int readday(){
    int x;
    cout<<"please enter the day"<<endl;
    cin>>x;
    return x;
}

data read(){
    data d;
    d.day=readday();
   d. month=readmonth();
    d.year=readyear();
    return d;
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


int showday(int day,int month,int year){
    int a,b,c,d;
    a=((14-month)/12);
    b=year-a;
    c=month+(12*a)-2;
    d=(day+b+(b/4)-(b/100)+(b/400)+((31*c)/12))%7;
    return d;
}

int showday(data d){
    return showday(d.day,d.month,d.year);
}


string dayname(int x){
    string arrDayNames[] = {
"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
return arrDayNames[x];
}

bool comper(data Date1,data Date2){
    return (Date1.year < Date2.year) ? true : ((Date1.year ==
Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month ==
Date2.month ? Date1.day < Date2.day : false)) : false);
}
bool leastday(data d){
    int numberday=numberofday(d.month,d.year);
    return (numberday==d.day)?true:false;
}

bool leastmonth(data d){
    return (d.month==12)?true:false;
}

data increase(data d){
    if(leastday(d)){
        if(leastmonth(d)){
            d.day=1;
            d.month=1;
            d.year+=1;
        }
        else{
            d.day=1;
            d.month+=1;
        }

    }
    else{
        d.day+=1;
    }
    return d;
}

bool weakend(data d1){
    int x=showday(d1);
    return (x==5||x==6);
}


int vacation(data d1,data d2,bool x=false){
    int number=0;
    while(comper(d1,d2)){
        
        if(!weakend(d1)){
            number++;
        }
        d1=increase(d1);
    }
    return (x)?++number:number;
}
int main(){
data d1=read();
data d2=read();
cout<<endl;
cout<<"vacation from :"<<dayname(showday(d1))<<","<<d1.day<<"/"<<d1.month<<"/"<<d1.year<<endl;

cout<<"vacation to :"<<dayname(showday(d2))<<","<<d2.day<<"/"<<d2.month<<"/"<<d2.year<<endl;

cout<<"actucal vacation days is :"<<vacation(d1,d2);
    return 0;
}