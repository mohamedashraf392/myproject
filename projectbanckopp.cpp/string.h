#pragma once
#ifndef STRING_H
#define STRING_H
#include <iostream>
#include<vector>

using namespace std;
class clstring{
private:
string _name;
public:
clstring(){
_name="";
}

clstring(string x){
    _name=x;
}

void setname(string x){
    _name=x;
}

string getname(){
    return _name;
}

 //show name

 static vector<string> splidsline(string x,string dlim){
    vector<string>arr;
    //string dlim=" ";
    int page=0;
    string w;
    while ((page=x.find(dlim))!=std::string::npos){
     w=x.substr(0,page); 
    
        if(w!=""){
    arr.push_back(w);
        }
        x.erase(0,page+dlim.length()) ;
    }
    if(x!=""){
      arr.push_back(x);
    }
    return arr;
}

void splidsline(string dlim){
 splidsline(_name,dlim);
}

//number of string

 static int numbersplidsline(string x){
    string dlim=" ";
    int page=0;
    int count=0;
    string w;
    while ((page=x.find(dlim))!=string::npos){
     w=x.substr(0,page); 
    
        if(w!=""){
    count++;
        }
        x.erase(0,page+dlim.length()) ;
    }
    if(x!=""){
       count++;
    }
    return count;
}

int  numbersplidsline(){
 return numbersplidsline(_name);
}

//upperfirstcharacterof string

static string upperfirstliterr(string s){
    bool isfirst=true;
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '&&isfirst){
            s[i]=toupper(s[i]);
        }

        isfirst=(s[i]==' ')?true:false;
    }
    return s;
}

string  upperfirstliterr(){
    return upperfirstliterr(_name);
}

//tlowerfirst characterof string

static string tlowerfirstliterr(string s){
   
    for(int i=0;i<s.length();i++){
            s[i]=tolower(s[i]);
    }
    return s;
}

string tlowerfirstliterr(){
   return tlowerfirstliterr(_name);
  
}

//change character

 static char invertlittercase(char c){
    return isupper(c)?tolower(c):toupper(c);
}

string invertalllitter(string x){
    for(int i=0;i<x.length();i++){
        x[i]=invertlittercase(x[i]);
    }
    return x;
}

string invertalllitter(){
    return invertalllitter(_name);
}

//number is smal charact
static int smalcaptialin(string s){
    int count =0;
    for(int i=0;i<s.length();i++){
        if(islower(s[i])){
            count++;
        }
    }
    return count;
}

int smalcaptialin(){
    return smalcaptialin(_name);
}
//number is big character

static int capitalcaptialin(string s){
    int count =0;
    for(int i=0;i<s.length();i++){
        if(isupper(s[i])){
            count++;
        }
    }
    return count;
}

int capitalcaptialin(){
    return capitalcaptialin(_name);
}

//isvowel
static bool isvowel(char c){
    c=tolower(c);
    return((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u'));
}

static int countvowel(string x){
    int count=0;
    for(int i=0;i<x.length();i++){
        if(isvowel(x[i])){
            count++;
        }
    }
    return count;
}

int countvowel(){
    return countvowel(_name);
}

//splid in vector
vector<string> splidslinenew(string x,string dlim){
vector<string>arr;
    int page=0;
    string w;
    while ((page=x.find(dlim))!=string::npos){
     w=x.substr(0,page); 
    
        if(w!=""){
     arr.push_back(w);
        }
        x.erase(0,page+dlim.length()) ;
    }
    if(x!=""){
        arr.push_back(x);
    }
    return arr;
}

vector<string> splidslinenew(string dlim){
   return splidslinenew(_name,dlim);
}

//term left
static string termlift(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
           return  s.substr(i,s.length());
            }
        }
        return "";
}

string termlift(){
    return termlift(_name);
}

//term right
static string termright(string s){
        for(int i=s.length();i>0;i--){
            if(s[i]!=' '){
            return  s.substr(0,i);
            }
        }
        return "";
}
string termright(){
    return termright(_name);
}
//=====

static string term(string s){
    return (termlift(termright(s)));
}


string term(){
    return term(_name);
}
//join string vector
 static string joinstring(vector<string>varr,string dlim){
    string s="";
    for(string&i:varr){
        s=s+i+dlim;
    }
    return s.substr(0,s.length());
}

//join string arr
static string joinstringarr(string arr[],int shorte,string dlim){
    string s="";
    for(int i=0;i<shorte;i++){
        s=s+arr[i]+dlim;

    }
    return s.substr(0,s.length()-dlim.length());
}

//to replace
string lowerallstring(string s){
    for(int i=0;i<s.length();i++){
        s=tolower(s[i]);
    }
    return s;
}
  string replacestring(string s,string from,string to,bool match=true){
vector<string>varr=splidslinenew(s," ");
for(string& i:varr){
    if(match){
        if(i==from){
            i=to;
        }
    }
    else{
        if(lowerallstring(i)==lowerallstring(from)){
            i=to;
        }
    }
}
return joinstring(varr," ");
}

string replacestring(string from,string to,bool match=true){
    return replacestring(_name,from,to);
}

//delete punct
string renampunct(string s){
    string w=""; 
       for(int i=0;i<s.length();i++){
        if(!ispunct(s[i])){
            w=w+s[i];
        }
    }
    return w;
}

string renampunct(){
    return renampunct(_name);
}

//reverdwordin string

string reverdwordinstring(string s){
    string s2="";
    vector<string>varr=splidslinenew(s," ");
    vector<string>::iterator iter=varr.end();
    while(iter!=varr.begin()){
        --iter;
        s2=s2+*iter+" ";
    }
    s2=s2.substr(0,s2.length()-1);
    return s2;
}

string reverdwordinstring(){
    return reverdwordinstring(_name);
}

};
#endif