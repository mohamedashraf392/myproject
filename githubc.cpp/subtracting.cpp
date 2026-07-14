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
bool oneday(data d){

    return (d.day==1)?true:false;
}

bool onemonth(data d){
    return (d.month==1)?true:false;
}

data decrease(data d){

    if(oneday(d)){
        if(onemonth(d)){
            d.month=12;
            d.day=numberofday(d.month,d.year);
            d.year--;
        }
        else{
            d.month--;
            d.day=numberofday(d.month,d.year);
        }

    }
    else{
        d.day--;
    }
    return d;
}

data subtractx(int x,data d){
    for(int i=1;i<=x;i++){
        d=decrease(d);
    }
    return d;
}


data subtractoneweak(data d){
    for(int i=1;i<=7;i++){
        d=decrease(d);
    }
    return d;
}

data subtractweakx(int x,data d){
    for(int i=1;i<=x;i++){
        d=subtractoneweak(d);
    }
    return d;
}

data subtractonemonth(data d){
    if(d.month==1){
            d.month=12;
            d.year-=1;
        }
        else{
            d.month--;
        }
        int x=numberofday(d.month,d.year);
        if(d.day>x){
            d.day=x;
        }
    return d;
}

data subtractmonthx(int x,data d){
    for(int i=1;i<=x;i++){
        d=subtractonemonth(d);
    }
    return d;
}

data subtractoneyear(data d){
    d.year--;
    return d;
}

data subtractxyear(int x,data d){
    for(int i=1;i<=x;i++){
        d=subtractoneyear(d);
    }
    return d;
}

data subtractxyearfaster(int x,data d){
    d.year-=x*1;
    return d;
}

  data subonedecated(data d){
       d.year-=10;
       return d;
    }

    
     data subdecatedx(int x,data d){
       for(int i=0;i<x;i++){
        d=subonedecated(d);
       }
       return d;
    }


     data subdecatedxfaster(int x,data d){
       d.year-=x*10;
       return d;
    }

    data subonecentury(data d){
        d.year-=100;
        return d;
    }

    data subonemillone(data d){
        d.year-=1000;
        return d;
    }

int main(){

    data d;
    d=read();
    d=decrease(d);
    cout<<"decrease one day:";
    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;

    d=subtractx(10,d);
    cout<<"decrease x day:";
    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;

    
    d=subtractoneweak(d);
    cout<<"decrease one weak:";
    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;

     
    d=subtractweakx(10,d);
    cout<<"decrease x weak:";
    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
    
    
    d=subtractonemonth(d);
    cout<<"decrease one month:";
    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
    
    
    d=subtractmonthx(5,d);
    cout<<"decrease month x:";
    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
    
    d=subtractoneyear(d);
    cout<<"decrease one year:";
    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
    
   d=subtractxyear(10,d);
    cout<<"decrease x year:";
    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
    
    
   d=subtractxyearfaster(10,d);
    cout<<"decrease x yearfaster:";
    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
    
    d= subonedecated(d);
    cout<<"decrease one decated:";
    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;

    d=subdecatedx(10,d);
    cout<<"decrease x decated:";
    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
    
    d=subdecatedxfaster(10,d);
    cout<<"decrease x decated fast:";
    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
    
    
    d=subonecentury(d);
    cout<<"decrease one century:";
    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
    
    
    d=subonemillone(d);
    cout<<"decrease one millon:";
    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
    
    
    return 0;
}