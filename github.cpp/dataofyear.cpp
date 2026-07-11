#include<iostream>
using namespace std;
int readyear(){
    int x;
    cout<<"please enter the year"<<endl;
    cin>>x;
    return x;
}

bool leapyear(int year){
return((year%400==0||(year%4==0&&year%100!=0))?true:false);

}
short numberofday(int year){
    return leapyear(year)?366:365;
}

int numberofhour(int year){
    return numberofday(year)*24;
}

int numberofminute(int year){
    return (numberofhour(year)*60);
}

int numberofsecond(int year){
    return (numberofminute(year)*60);
}

int main(){
int x=readyear();
cout<<"the day of["<<x<<"]"<<numberofday(x)<<endl;
cout<<"the hour of["<<x<<"]"<<numberofhour(x)<<endl;
cout<<"the minute of["<<x<<"]"<<numberofminute(x)<<endl;
cout<<"the second of["<<x<<"]"<<numberofsecond(x)<<endl;
    return 0;
}