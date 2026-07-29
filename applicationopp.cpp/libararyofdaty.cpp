#include<iostream>
#include"data.h"
#include<ctime>
# include<cmath>
# include<string>
using namespace std; 

int main(){

clsdata c;
c.print();
clsdata c5(23,2.2011);
clsdata c1(23,2,2002);
c1.print();

clsdata c2("25/02/2008");
c2.print();

clsdata c3(315,2002);
c3.print();


cout<<endl;
clsdata d(23,2,2006);
cout<<clsdata::IsDateBetween(d,c1,c5);

    return 0;
}
