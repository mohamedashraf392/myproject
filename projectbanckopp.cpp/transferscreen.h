#pragma once
#ifndef TRANSFERSCREEN_H
#define TRANSFERSCREEN_H
#include <iostream>
#include"clsscreen.h"
#include"clsfindclients.h"
#include"clsinputvalidate.h"
#include<iomanip>
#include<ctime>
# include<cmath>
#include<vector>

class transfer:protected clsscreen{

private:

static void print(clsbank i){

    cout<<"accountnumber is:"<<i.getaccountnumber()<<endl;
    cout<<"accountbalance is:"<<i.getaccountbalance()<<endl;
     cout<<"name is:"<<i.fullname()<<endl;
}
public:
 
static void transferscreen(){
string account1;
string account2;
cout<<"please enter account1 "<<endl;
account1=clsvalidate::readstring();
while(!clsbank::isclientexit(account1)){
cout<<"please enter account1 agin "<<endl;
account1=clsvalidate::readstring();
}
clsbank client1=clsbank::Find(account1);
print(client1);

cout<<"\nplease enter account2 "<<endl;
account2=clsvalidate::readstring();
while(!clsbank::isclientexit(account2)){
cout<<"please enter account2 agin "<<endl;
account2=clsvalidate::readstring();
}

clsbank client2=clsbank::Find(account2);
print(client2);

cout<<"\nplease enter balance"<<endl;
double balance;
balance=clsvalidate::readdoublenumber();

cout<<endl;

if(client1.transferscreen(client2,balance)){
    cout<<"transfer is done"<<endl;
    print(client1);
    print(client2);
}
else{
    cout<<"transfer is not done"<<endl;


}
client1.addusernew(balance,client1.fullname(),client2);


}






};

#endif