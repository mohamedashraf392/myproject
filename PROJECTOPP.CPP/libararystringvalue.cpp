#include<iostream>
#include"string.h"
# include<cmath>
# include<string>
using namespace std; 

int main(){
    clstring s;
    clstring s2("Mohamed, Ashraf, mohamed");
    s.setname("ahmed ashraf MOHamed");
    cout<<"getname from s and s2"<<endl;
   cout<<s.getname()<<endl;
   cout<<s2.getname()<<endl;
   cout<<"===========start the library string=========="<<endl;

   cout<<"--------------splid line---------"<<endl;
    s.splidsline();
    cout<<endl;
    clstring::splidsline("mohames ahme ");
     cout<<endl;
     cout<<"-------------------------------"<<endl;

     cout<<"--------number of splid--------"<<endl;
     cout<<s.numbersplidsline()<<endl;
     cout<<"-------------------------------"<<endl;

      cout<<"--------uper first litter--------"<<endl;
     cout<<s.upperfirstliterr()<<endl;
     cout<<"----------------------------------"<<endl;

      cout<<"--------tlower all litter--------"<<endl;
     cout<<s2.tlowerfirstliterr()<<endl;
     cout<<"-------------------------------"<<endl;

      cout<<"--------invert all litter--------"<<endl;
      cout<<s.invertalllitter()<<endl;
      cout<<"-------------------------------"<<endl;
      
     cout<<"--------number of small litter--------"<<endl;
     cout<<s2.smalcaptialin()<<endl;
     cout<<"-------------------------------"<<endl;

      cout<<"--------number of capital litter--------"<<endl;
      cout<<s2.capitalcaptialin()<<endl;
      cout<<"----------------------------------------"<<endl;

      cout<<"--------number of vowel--------"<<endl;
      cout<<s2.countvowel()<<endl;
      cout<<"-------------------------------"<<endl;

    cout<<"--------splid string in vector--------"<<endl;
    vector<string>varr;
    varr=s2.splidslinenew(" ");
    for(string&i:varr){
        cout<<i<<endl;
    }
   cout<<"----------------------------------------"<<endl;

    cout<<"--------term lift--------"<<endl;
    cout<<s.termlift()<<endl;
    cout<<"-------------------------"<<endl;

    cout<<"--------term right--------"<<endl;
    cout<<s.termright()<<endl;
    cout<<"--------------------------"<<endl;

    cout<<"--------term lift and right--------"<<endl;
    cout<<s.term()<<endl;
    cout<<"-----------------------------------"<<endl;


    cout<<"--------join string in vector--------"<<endl;
    vector<string>arr{"ahmed","mohamed","omer"};
    cout<<clstring::joinstring(arr," ")<<endl;
    cout<<"-------------------------------------"<<endl;


    cout<<"--------join string in arry--------"<<endl;
    string arrye[]={"mhamed","ahmed","omer"};
    cout<<clstring::joinstringarr(arrye,3," ")<<endl;
    cout<<"---------------------------------"<<endl;
    
    cout<<"--------replace string --------"<<endl;
    cout<<s2.replacestring("Mohamed","hana")<<endl;
    cout<<"-----------------------------------"<<endl;

     cout<<"--------delete all punct in stringg--------"<<endl;
     cout<<s2.renampunct()<<endl;
     cout<<"-----------------------------------"<<endl;


    cout<<"--------reverd word in string-------"<<endl;
    cout<<s.reverdwordinstring()<<endl;
    cout<<"-----------------------------------"<<endl;


    return 0;
}