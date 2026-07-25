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
    int num=5;
clasa*arr=new clasa(num);
for(int i=0;i<num;i++){
    clasa s(i);
    arr[i]=s;
}

for(int i=0;i<num;i++){
    arr[i].print();
}
return 0;
}
