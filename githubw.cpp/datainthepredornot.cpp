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


bool  datainthepred(stpred p1,stpred p2){

    return(comperdatas(p2.startday,p1.startday)==endata::after&&comperdatas(p2.startday,p1.endday)==endata::befor);
    
}
 int countdatin(stpred p1,stpred p2){
    int count=0;
    while(datainthepred(p1,p2)){
        count++;
        p2.startday=increase(p2.startday);
    }
    return count;
 }

 int main(){
    
    stpred p1,p2;
    cout<<"pred 1";
    p1=readpread();
    cout<<"pred 2";
    p2=readpread();
  cout<<"overlop day count is:"<<countdatin(p1,p2);
  return 0;
 }