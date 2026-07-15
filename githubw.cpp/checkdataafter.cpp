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

 
bool checkdataafter(data d1, data d2){
    return (!comper(d1,d2)&&!IsDate1EqualDate2(d1,d2));
}

int main(){

    data d1=read();
    data d2=read();
    if(checkdataafter(d1,d2)){
        cout<<"yes,data1 is after data2";
    }
    else{
        cout<<"no ,data1 is not after data2 ";
    }
    return 0;
}