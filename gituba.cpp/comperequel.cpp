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

bool comper(data Date1,data Date2){

//return (Date1.year == Date2.year) ? ((Date1.month ==Date2.month) ? ((Date1.day == Date2.day) ? true : false): false) : false;
 //new solution
 return(Date1.year==Date2.year&&Date1.month ==Date2.month&&Date1.day == Date2.day)   ;
}
int main(){
data d1,d2;
d1=read();
d2=read();
 if(comper(d1,d2)){
    cout<<"yese data1 is equel data2";
 }
else{
    cout<<"no data1 not equel then data2";
}
    return 0;
}