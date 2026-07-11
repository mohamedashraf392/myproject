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

int showday(int day,int month,int year){
    int a,b,c,d;
    a=((14-month)/12);
    b=year-a;
    c=month+(12*a)-2;
    d=(day+b+(b/4)-(b/100)+(b/400)+((31*c)/12))%7;
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
string showmonth(int x){
    string month[12] = { "Jan", "Feb", "Mar",
"Apr", "May", "Jun",
"Jul", "Aug", "Sep",
"Oct", "Nov", "Dec"};
return month[x-1];
}

void print(int month ,int year){
int currint=showday(1,month,year);
int x=numberofday(month,year);
    printf("\n _______________%s_______________\n\n",showmonth(month).c_str());

printf(" Sun Mon Tue Wed Thu Fri Sat\n");
int i=0;
    for(i=0;i<currint;i++){
      printf("    ");
    }
    for(int j=1;j<=x;j++){
     printf("%4d", j);
     i++;
     if(i==7){
    i=0;
    cout<<endl;
}
    }
printf("\n _________________________________\n");
}
int main(){
int x=readyear();
int y=readmonth();
print(y,x);

    return 0;
}