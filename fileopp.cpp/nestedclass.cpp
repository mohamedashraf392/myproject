#include<iostream>
# include<cmath>
# include<string>
using namespace std; 

class person{

  class staddreasss{
    private:
    string _city;
    string _country;
    public:
    staddreasss(){}
    staddreasss(string city,string coutry){
    _city=city;
    _country=coutry;
    }
    void setcity(string city){
        _city=city;
    }

    string getcity(){
        return _city;
    }
    

    void setcountry(string country){
        _country=country;
    }

    string getcoutry(){
        return _country;
    }

    void print(){
         cout<<_city<<" "<<_country<<endl;
    }
  };

   public:
   string _firstname;
   staddreasss s;

   person(string city,string counter,string f):s(city,counter){
    _firstname=f;
  
   }

};

int main(){
person p("aman","talha","mohamed");
p.s.print();

    return 0;
}