#include<iostream>
# include<cmath>
# include<string>
using namespace std; 
class calculator{
    private:
    int _number;
    string _lastoper="clear";
    public:

    void clearnum(){
        _number=0;
    }

    void add(int num){
       _number= _number+num;
       _lastoper="add";
    }


    void subtrack(int num){
        _number=_number-num;
        _lastoper="subtrack";
    }

    void divid(int num){
        if(num==0){
            _number=_number;
        }
        else{
        _number=_number/num;
        }
        _lastoper="divid";
    }

    void mult(int num){
        _number*=num;
        _lastoper="mult";
    }

    void print(){
        cout<<"the number after " << _lastoper << " is: " << _number << endl;
    }
    


};

int main(){

    calculator c1;
    c1.clearnum();
    c1.add(20);
    c1.print();

   cout<<endl;
   
    c1.add(20);
    c1.print();

    cout<<endl;

    c1.subtrack(10);
    c1.print();

    
    cout<<endl;

    c1.divid(3);
    c1.print();

    
    cout<<endl;

    c1.mult(3);
    c1.print();
cout<<endl;
    c1.clearnum();
    c1.print();
    return 0;
}