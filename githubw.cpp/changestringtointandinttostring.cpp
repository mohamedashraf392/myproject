#include<iostream>
#include<vector>
using namespace std;
struct data{
    int day;
    int month;
    int year;
};

string read(){
    string name;
    cout<<"pleas enter the data went to check?"<<endl;
    cin>>name;
    return name;

}
vector<string> splid(string s,string dlim="/"){
int pos=0;
string w="";
vector<string>arr;

while((pos=s.find(dlim))!=std::string ::npos){
    w=s.substr(0,pos);
    if(w!=""){
        arr.push_back(w);
    }
    s.erase(0,pos+dlim.length());
}

if(s!=""){
    arr.push_back(s);
}
return arr;
}

data tointdata(string s){
    vector<string>varr=splid(s,"/");  
    data d;
    d.day=stoi(varr[0]); 
    d.month=stoi(varr[1]);
    d.year=stoi(varr[2]);
return d;

}

string tostring(data d){
    return to_string(d.day)+"/"+to_string(d.month)+"/"+to_string(d.year);
}
int main(){
data d;
string x=read();
d=tointdata(x);
cout<<"days:"<<d.day<<endl;
cout<<"month :"<<d.month<<endl;
cout<<"years :"<<d.year<<endl;
cout<<"you enter:"<<tostring(d);


    return 0;

}