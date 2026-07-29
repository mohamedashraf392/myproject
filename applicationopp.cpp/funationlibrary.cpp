#include<iostream>
#include"util.h"
#include"data.h"
#include<ctime>
# include<cmath>
# include<string>
using namespace std; 

int main(){
  srand((unsigned)time(NULL));
cout<<util::randnumber(1,10)<<endl;

cout<<util::randlitter(util::max)<<endl;

cout<<util::genertword(util::max,8)<<endl;

cout<<util::genertkey(util::max)<<endl;

util::genertkeys(util::max,10);
cout<<endl;

int x=10;
int y=20;
cout<<x<<"   "<<y<<endl;
util::swap(x,y);
cout<<x<<"   "<<y<<endl;



double a=10.5;
double b=20.5;
cout<<a<<"   "<<b<<endl;
util::swapdouble(a,b);
cout<<a<<"   "<<b<<endl;


string c="mohamed";
string d="ahmed";
cout<<c<<"   "<<d<<endl;
util::swapstring(c,d);
cout<<c<<"   "<<d<<endl;

clsdata d1("23/02/2006");
clsdata d2("5/05/2022");
d1.print();
cout<<"  ";
d2.print();
util::swapdata(d1,d2);
d1.print();
cout<<"  ";
d2.print();


int arr[5]={1,2,3,4,5};
util::shufly(arr,5);
cout<<"after shifly"<<endl;
for(int i=0;i<5;i++){
    cout<<arr[i]<<endl;
}

string arrstring[5]={"mohamed","ahmed","mahmoud","omer","hana"};
util::shuflystring(arrstring,5);
cout<<"after shifly arry of string"<<endl;
for(int i=0;i<5;i++){
    cout<<arrstring[i]<<endl;
}


int arr3[5];
util::fularrofrandnumber(arr3,5,1,10);
for(int i=0;i<5;i++){
    cout<<arr3[i]<<endl;
}


string arr4[5];
util::fularrofrandword(arr4,5,util::max);
for(int i=0;i<5;i++){
    cout<<arr4[i]<<endl;
}


string arr5[5];
util::fularrofrandkeys(arr5,5,util::max);
for(int i=0;i<5;i++){
    cout<<arr5[i]<<endl;
}

cout<<"text1"<<util::tabs(10)<<"text2"<<endl;

string text="mohamed ashraf mohamed";
string encrypted=util::EncryptText(text,2);
cout<<encrypted<<endl;
cout<<util::DecryptText(encrypted,2);

    return 0;
}