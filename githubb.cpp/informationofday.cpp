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

    data addxday(int x,data d){
        for(int i=0;i<x;i++){
            d=increase(d);
        }
        return d;
    }

    data addoneweak(data d){
        for(int i=0;i<7;i++){
            d=increase(d);
            
        }
        return d;
    }

     data addxweak(int x,data d){
        for(int i=0;i<x;i++){
            d=addoneweak(d);
            
        }
        return d;
    }

    data addonemonth(data d){
        if(d.month==12){
            d.month=1;
            d.year+=1;
        }
        else{
            d.month++;
        }
        int x=numberofday(d.month,d.year);
        if(d.day>x){
            d.day=x;
        }
        return d;
    }

    data addxmonth(int x,data d){
        for(int i=0;i<x;i++){
            d=addonemonth(d);
        }
        return d;
    }

    
    data addoneyear(data d){
       d.year++;
        return d;
    }

     data addxyear(int x,data d){
        for(int i=0;i<x;i++){
            d=addoneyear(d);
        }
        return d;
    }

    data addxyearfast(int x,data d){
        for(int i=0;i<x;i++){
            d.year++;
        }
        return d;
    }

     data onedecated(data d){
       d.year+=10;
       return d;
    }

    
     data decatedx(int x,data d){
       for(int i=0;i<x;i++){
        d=onedecated(d);
       }
       return d;
    }


     data decatedxfaster(int x,data d){
       d.year+=x*10;
       return d;
    }

    data addonecentury(data d){
        d.year+=100;
        return d;
    }

     data addonemillennum(data d){
        d.year+=1000;
        return d;
    }


int main(){
data d;
d=read();
d=increase(d);
cout<<"add one day:";
cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;

d=addxday(10,d);
cout<<"add x day:";
cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;

d=addoneweak(d);
cout<<"add one weak:";
cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;

d=addxweak(10,d);
cout<<"add x weak:";
cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;


d=addonemonth(d);
cout<<"add one month:";
cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;

d=addxmonth(5,d);
cout<<"add x month:";
cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;

d=addoneyear(d);
cout<<"add one year:";
cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;


d=addxyear(10,d);
cout<<"add x year:";
cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;

d=addxyearfast(10,d);
cout<<"add x year faster:";
cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;


d=onedecated(d);
cout<<"add one decated:";
cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;


d=decatedx(10,d);
cout<<"add x decated:";
cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;


d=decatedxfaster(10,d);
cout<<"add x decated fast:";
cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;


d=addonecentury(d);
cout<<"add one century:";
cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;


d=addonemillennum(d);
cout<<"add one millenum:";
cout<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;

    return 0;
}