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
    d.month=readmonth();
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

int numberofdayfrombeginnerintheyear(int day,int month,int year){
    int total=0;
    for(int i=1;i<=month-1;i++){
        total+=numberofday(i,year);
    }
    total+=day;
    return total;
}

data renam(int dataorderinyear,data d){
    int remainday=dataorderinyear+numberofdayfrombeginnerintheyear(d.day,d.month,d.year);
    d.month=1;
    while(true){
        int z=numberofday(d.month,d.year);
        if(remainday>z){
            remainday-=z;
            d.month++;
            if(d.month>12){
                d.month=1;
                d.year++;
            }

        }
        else {
            d.day=remainday;
            break;
        }
    }
return d;
}
int main(){
  data d;
  d=read();

int addday;
cout<<"how many day went to add:";
cin>>addday;
cout<<"the number of day went to add"<<addday<<endl;


d=renam(addday,d);
cout<<d.day<<"/"<<d.month<<"/"<<d.year;


return 0;
}