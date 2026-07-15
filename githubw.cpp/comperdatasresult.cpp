#include<iostream>
using namespace std;
enum endata{after=1,befor=-1,equal=0};
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

bool IsDate1EqualDate2(data Date1, data Date2)
{
return (Date1.year == Date2.year) ? ((Date1.month ==
Date2.month) ? ((Date1.day == Date2.day) ? true : false) : false)
: false;
}

endata comperdatas(data d1,data d2){

     if(IsDate1EqualDate2(d1,d2)){
        return endata::equal;
    }
     if(comper(d1,d2)){
        return endata::befor;
    }

     return endata::after;
}

 
int main(){

    data d1=read();
    data d2=read();
    cout<<endl;
    cout<<"comper result:"<<comperdatas(d1,d2);
   
    return 0;
}