#include<iostream>
using namespace std;
int readyear(){
    int x;
    cout<<"please enter the year"<<endl;
    cin>>x;
    return x;
}

bool leapyear(int year){
    /*if(year%400==0){
        return true;
    }
    else if(year%4==0){
        return true;
    }

  else if(year%100==0){
        return false;
    }

    else{
        return false;
    }*/

    //new solution
return((year%400==0||(year%4==0&&year%100!=0))?true:false);
}
int main(){
if(leapyear(readyear())){
    cout<<"the year is a leapyear";
}
else
cout<<"the year is not leapyear";


    return 0;
}