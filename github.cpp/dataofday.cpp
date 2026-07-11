#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
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

int showday(int day,int month,int year){
    int a,b,c,d;
    a=((14-month)/12);
    b=year-a;
    c=month+(12*a)-2;
    d=(day+b+(b/4)-(b/100)+(b/400)+((31*c)/12))%7;
    return d;
}

string dayname(int x){
    string arrDayNames[] = {
"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
return arrDayNames[x];
}

int main(){
int x=readyear();
int y=readmonth();
int z=readday();
cout<<"Date    :"<<z<<"/"<<y<<"/"<<x<<endl;
cout<<"dayof order  :"<<showday(z,y,x)<<endl;
cout<<"day name   :"<<dayname(showday(z,y,x));


    return  0;
}