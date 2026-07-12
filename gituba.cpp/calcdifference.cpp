#pragma warning(disable : 4996)
#include<iostream>
#include<ctime>
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

bool comper(data Date1,data Date2){
    return (Date1.year < Date2.year) ? true : ((Date1.year ==
Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month ==
Date2.month ? Date1.day < Date2.day : false)) : false);
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
void swapdata(data& d1,data&d2){
    data temp;
    temp.day=d1.day;
    temp.month=d1.month;
    temp.year=d1.year;

    d1.day=d2.day;
    d1.month=d2.month;
    d1.year=d2.year;

    d2.day=temp.day;
    d2.month=temp.month;
    d2.year=temp.year;

}

int calcdifference(data d1,data d2,bool x=false){
    int number=0;
    short swapflagvalue=1;
   if(!comper(d1,d2)){
    swapdata(d1,d2);
    swapflagvalue=-1;
   }

    while(comper(d1,d2)){
        number++;
        d1=increase(d1);
    }
    return (x)?(++number*swapflagvalue):(number*swapflagvalue);
}

int main(){
data d1,d2;
d1=read();
d2=read();
 cout<<"the day is: "<<calcdifference(d1,d2,true)<<endl;

    return 0;
}