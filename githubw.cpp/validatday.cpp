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

bool validatday(data d){
    int numberday=numberofday(d.month,d.year);
    if(d.month>12||d.month<1){
        return false;
    }

    if(d.day!=numberday){
        return false;
    }

    return true;


}
int main(){
    data d;
    d=read();
    if(validatday(d)){
        cout<<"yes,data is validata day";
    }
    else
    cout<<"no,data is not validata day";

return 0;
}