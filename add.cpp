#pragma warning(disable:4996)
#include<ctime>
#include<iostream>
using namespace std;
int main(){
cout<<"---------------------------"<<endl;
time_t t=time(0);
tm*now=localtime(&t);
cout<<now->tm_year+1900<<endl;
cout<<now->tm_hour<<endl;
cout<<now->tm_min;
}