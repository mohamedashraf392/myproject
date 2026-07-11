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
bool leapyear(int year){
return((year%400==0||(year%4==0&&year%100!=0))?true:false);

}
int numberofday(int month,int year){
    /*if(month<1||month>12){
        return 0;
    }
    if(month==2){
        return leapyear(year)?29:28;
    }
    int arr[7]={1,3,5,7,8,10,12};
    for(int i=1;i<=7;i++){
        if(arr[i-1]==month){
            return 31;
        }
    }
    return 30;*/


//new solution
    if(month<1||month>12){
        return 0;
    }
    int arr[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    return(month==2?(leapyear(year)?29:28):arr[month]);



}
int numberofhour(int month,int year){
    return numberofday(month,year)*24;
}
int numberofminute(int month,int year){
    return (numberofhour(month,year)*60);
}
int numberofsecond(int month,int year){
    return (numberofminute(month,year)*60);
}
int main(){
int x=readyear();
int y=readmonth();
cout<<"the day of["<<x<<"]"<<numberofday(y,x)<<endl;
cout<<"the hour of["<<x<<"]"<<numberofhour(y,x)<<endl;
cout<<"the minute of["<<x<<"]"<<numberofminute(y,x)<<endl;
cout<<"the second of["<<x<<"]"<<numberofsecond(y,x)<<endl;

    return 0;
}