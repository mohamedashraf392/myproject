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

int numberofdayfrombeginnerintheyear(int day,int month,int year){
    int total=0;
    for(int i=1;i<=month-1;i++){
        total+=numberofday(i,year);
    }
    total+=day;
    return total;
}
int main(){
int x=readyear();
int y=readmonth();
int z=readday();
cout<<"the day is;"<<z<<endl;
cout<<"the month is ;"<<y<<endl;
cout<<"the year is ;"<<x<<endl;
cout<<"the number of day"<<numberofdayfrombeginnerintheyear(z,y,x);
return 0;
}