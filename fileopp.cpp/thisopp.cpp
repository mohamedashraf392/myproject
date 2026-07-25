#include<iostream>
# include<cmath>
# include<string>
using namespace std; 
class person{
    public:
    string name ;
    string salary;
    person(string n,string s){
        name=n;
        salary=s;
    }

static void fun1(person p){
    p.print();
}

void fun2(){
    fun1(*this);
}

    void print(){
        cout<<name<<"   "<<salary<<endl;
    }

};

int main(){

    person p("mohamed","1250");
    p.print();
    p.fun2();
  
    return 0 ;
}