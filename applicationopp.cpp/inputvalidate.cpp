#include<iostream>
#include"validate.h"
#include"data.h"
#include<ctime>
# include<cmath>
# include<string>
using namespace std; 
int main(){

    cout<<clsvalidate::isnumberbetwen(12,4,10)<<endl;

    cout<<clsvalidate::isnumberbetwen(3.5,2.5,10.5)<<endl;

    clsdata c(23,2,2006);
    clsdata c1(5,5,2015);
    clsdata c2(3,3,2008);

cout<<clsvalidate::IsDateBetween(c2,c,c1)<<endl;


cout<<clsvalidate::IsValideDate(c);


    return 0;
}