#include<iostream>
# include<cmath>
#include<vector>
# include<string>
using namespace std; 
class clasa{
    public:
    int x;
    clasa(){}
    clasa(int num){
        x=num;
    }
    void print(){
        cout<<"the value is:"<<x<<endl;
    }
};
int main(){
    clasa obj[]={clasa(10),clasa(20),clasa(30)};
    for(int i=0;i<3;i++){
        obj[i].print();
    }
    return 0;
}