#include<iostream>
#include"data.h"
#include<ctime>
# include<cmath>
# include<string>
using namespace std; 

int main(){

clsdata c;
c.print();

clsdata c1(23,2,2006);
c1.print();

clsdata c2("25/02/2006");
c2.print();

clsdata c3(315,2022);
c3.print();

cout<<c1.IsDate1EqualDate2(c2);

    return 0;
}
