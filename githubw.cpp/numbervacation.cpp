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


data datavacation(data d ,int x){
    int numberweak=0;
    while(weakend(d)){
         d=increase(d);
    }
    for(int i=1;i<=x+numberweak;i++){
      if(weakend(d)){
        numberweak++;}
        d=increase(d);
      
    }
     while(weakend(d)){
         d=increase(d);
    }
   return d;
}
int main(){
data d=read();
int numberday;
cout<<"please enter the day do you went vacation"<<endl;
cin>>numberday;
cout<<endl;
d=datavacation(d,numberday);
cout<<"return data is :"<<dayname(showday(d))<<","<<d.day<<"/"<<d.month<<"/"<<d.year;



    return 0;
}