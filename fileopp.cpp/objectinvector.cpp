#include<iostream>
# include<cmath>
#include<vector>
# include<string>
using namespace std; 
class clasa{
    public:
    int x;
    clasa(int num){
        x=num;
    }
    void print(){
        cout<<"the value is:"<<x<<endl;
    }
};

int main(){

vector<clasa>v;
int numberofobj=5;
for(int i=0;i<numberofobj;i++){
    clasa s(i);
    v.push_back(s);
}
  
for(int i=0;i<numberofobj;i++){
    v[i].print();
}
}