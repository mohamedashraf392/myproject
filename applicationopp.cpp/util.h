#pragma once
#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include"data.h"
#include<ctime>
# include<cmath>
#include<vector>
using namespace std;
class util{
    public:
 static int randnumber(int from,int to){
    return rand()%(to-from+1)+from;
}

enum enchar{smalllitter=1,capitallitter=2,digit=3,spacilcharacter=4,max=5};


static char randlitter(enchar chartype){

    if(chartype==max){
        chartype= enchar (randnumber(1,3));
    }

    switch(chartype){

        case enchar::smalllitter:{
            return char(randnumber(97,122));
            break;
        }

        case enchar::capitallitter:{
            return char(randnumber(65,90));
            break;
        }

        case enchar::digit:{
            return char(randnumber(48,57));
            break;
        }

        
        case enchar::spacilcharacter:{
            return char(randnumber(33,47));
            break;
        }
    }
}

   static string genertword(enchar chartype,int lengthword){
    string word;

        for(int i=1;i<=lengthword;i++){
            word=word+ randlitter(chartype);
        }
    return word;
   }

 static  string genertkey(enchar chartype){
    string key;
    key=genertword(chartype,4)+"-";
    key+=genertword(chartype,4)+"-";
    key+=genertword(chartype,4)+"-";
    key+=genertword(chartype,4);
    return key;
   }

   static void genertkeys(enchar chartype,int number){
    for(int i=1;i<=number;i++){
      cout<<"key["<<i<<"]:";
      cout<<genertkey(chartype)<<endl; 
    }
   }

 static void swap(int& x,int& y){
    int temp;
    temp=x;
    x=y;
    y=temp;
   }

   static void swapdouble(double& x,double& y){
    double temp;
    temp=x;
    x=y;
    y=temp;
   }

   
   static void swapstring(string& x,string& y){
    string temp;
    temp=x;
    x=y;
    y=temp;
   }

  static void swapdata(clsdata& x,clsdata& y){
 clsdata::swapdata(x,y);
   }

 static  void shufly(int arr[100],int length){
    for(int i=0;i<length;i++){
        swap(arr[randnumber(1,length)-1],arr[randnumber(1,length)-1]);
    }
   }

   
 static  void shuflystring(string arr[100],int length){
    for(int i=0;i<length;i++){
        swapstring(arr[randnumber(1,length)-1],arr[randnumber(1,length)-1]);
    }
   }

 static  void fularrofrandnumber(int arr[100],int length,int from,int to){
    for(int i=0;i<length;i++){
        arr[i]=randnumber(from,to);
    }
   }

   
 static  void fularrofrandword(string arr[100],int length,enchar chartype){
    for(int i=0;i<length;i++){
        arr[i]=genertword(chartype,4);
    }
   }


   
 static  void fularrofrandkeys(string arr[100],int length,enchar chartype){
    for(int i=0;i<length;i++){
        arr[i]=genertkey(chartype);
    }
   }

 static string  tabs(int numberoftebs){
    string t="";
    for(int i=1;i<=numberoftebs;i++){
        t=t+"\t";
        cout<<t;
    }
    return t;
}


    static string  EncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }

};


#endif