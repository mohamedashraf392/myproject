#include<iostream>
using namespace std;
enum endata{after=1,befor=-1,equal=0};
struct data{
    int day;
    int month;
    int year;
};

struct stpred{
    data startday;
    data endday;
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

stpred readpread(){
    stpred p;
    cout<<"enter start day"<<endl;
    p.startday=read();
    cout<<"enter end day"<<endl;
    p.endday=read();
    return p;
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
bool  datainthepred(stpred p1,stpred p2){

    if(comperdatas(p2.startday,p1.endday)==endata::after||comperdatas(p2.endday,p1.startday)==endata::befor){
        return false;
    }
    else
    return true;
    
}

 
int main(){
stpred p1,p2;
cout<<"pred 1"<<endl;
p1=readpread();
cout<<"pread 2"<<endl;
p2=readpread();
cout<<endl;
if(datainthepred(p1,p2)){
    cout<<"yes is pred overlop"<<endl;
}
else{
    cout<<"no,not pred";
}
   
    return 0;
}