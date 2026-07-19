
#include<iostream>
#include<random>
#include<ctime>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;
enum enquick{en1=20,en2=50,en3=100,en4=200,en5=400,en6=600,en7=800,en8=1000};
enum enlog{q=1,normal=2,depos=3,check=4,lo=5};
void checkpassword();

void PRINTheader(string account ,string pin);
struct bank{
    string accountnumber;
    string pincod;
    string name;
    string phone;
    int accountbalance;
    bool markfordelete=false;
};


vector<string> splidsline(string x,string dlim){
vector<string>arr;
    size_t page=0;
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

bank convgration(string line ,string dlim="#//#"){
    vector<string>varry;
    varry=splidsline(line,dlim);
    bank s;
    s.accountnumber=varry[0];
    s.pincod=varry[1];
    s.name=varry[2];
    s.phone=varry[3];
    s.accountbalance=stoi(varry[4]);
    return s;
}

 string convertbanktostring(bank s,string dlim="#//#"){
    string x="";
    x+=s.accountnumber+dlim;
    x+=s.pincod+dlim;
    x+=s.name+dlim;
    x+=s.phone+dlim;
    x+=to_string(s.accountbalance)+dlim;
    return x;
 }

vector<bank> showfile(string file){
    vector <bank>vclient;
    fstream myfile;
    myfile.open(file,ios::in);
    if(myfile.is_open()){
        string line;
        bank s;
        while (getline(myfile,line))
        {
            s=convgration(line);
            vclient.push_back(s);
        }
        myfile.close();
    }
    else{
        cout<<"error in open file"<<endl;
    }
    return vclient;
}

string readaccount(){
string x;
cout<<"please enter account number"<<endl;
cin>>x;
return x;
}

string readpincode(){
string x;
cout<<"please enter pincode number"<<endl;
cin>>x;
return x;
}

int choselist(){
    int number;
    cout<<"please choice what do you went [1 to 8]"<<endl;
    cin>>number;
    return number;
}

 bool checkstring(string account,string pin,bank &s){
    vector<bank>varr=showfile("myfile.text");
    for(bank &i:varr){
        if(i.accountnumber==account&&i.pincod==pin){
            s=i;
            return true;
        }
    }
    return false;
 }

 
vector<bank> saveclientdata(string file,vector<bank>&vclient)
{
       
    string dataline;
    fstream myfile;

    myfile.open(file, ios::out);

    if (myfile.is_open())
    {
        for (bank &i : vclient)
        {
            if (i.markfordelete == false)
            {
                dataline = convertbanktostring(i); // not delete the line
                myfile << dataline << endl;
            }
        }

        myfile.close();
    }

    return vclient;
}


 int choseqiickdrow(enquick quick){

switch (quick)
{
case 20:{
    return 20;
    break;}

case 50:{
return 50;
break;}

case 100:{
return 100;
break;}

case 200:{
return 200;
break;}

case 400:{
return 400;
break;}

case 600:{
return 600;
break;}

case 800:{
return 800;
break;} 

case 1000:{
return 1000;
break;}
}
 }



 void printquickbalance(){
    cout<<"[1]=20         [2]=50 "<<endl;
     cout<<"[3]=100         [4]=200 "<<endl;
      cout<<"[5]=400          [6]=600 "<<endl;
       cout<<"[7]=800          [8]=1000 "<<endl;
}

//quick with drow
 void finalquickwithdraw(string account,string pin){
      vector<bank>varr=showfile("myfile.text");
      bank s;
    char sure='y';
      for(bank&i:varr){
        if(i.accountnumber==account&&i.pincod==pin){
              printquickbalance();
            int a;
            a=i.accountbalance;
            cout<< "blance is:"<<a<<endl;

              enquick x = static_cast<enquick>(choselist());
              int w=choseqiickdrow(x);
              cout<<w<<endl;
              cout<<"are you sure?"<<endl;
              cin>>sure;
              if(sure=='y'){
              if(a>=w){
                i.accountbalance=i.accountbalance+(-w);
              
              saveclientdata("myfile.text",varr);
              cout<<"new balance:"<<i.accountbalance;
              }
              else{
                cout<<"less many of the account";
              }
            }
        }
      }
    }

//normalwithdrow


    int withdrowenter(){
    int many;
    cout<<"please enter the with drow of 5's?"<<endl;
    cin>>many;
    
    return many;
}
void withdrow(string account,string pin){
    vector<bank>vclient=showfile("myfile.text");
    char w='y';
    bank s;
      
       int x;
       x=withdrowenter();
       while(x%5!=0){
        x=withdrowenter();
       }
        for(bank &i:vclient){
        if(i.accountnumber==account&&i.pincod==pin){
            int a;
            a=i.accountbalance;
            cout<<"your balance is:"<<a<<endl;
            if(a>=x){
           i.accountbalance= i.accountbalance+(-1*x);
           saveclientdata("myfile.text",vclient);
           cout<<"new balancee:"<<i.accountbalance<<endl;
                }
                else{
                    cout<<"leas many "<<endl;
                }
               }
            }
        
        cout<<"done"<<endl;
        }


    //depost


int depostenter(){
    int many;
    cout<<"please enter the deposit?"<<endl;
    cin>>many;
    return many;
}

void depost(string account,string pin){
    vector<bank>vclient=showfile("myfile.text");
    char w='y';
    bank s;
         int x=depostenter();
         cout<<endl;
        for(bank &i:vclient){
            if(i.accountnumber==account&&i.pincod==pin){
                int a=i.accountbalance;
                cout<<"you balance is :"<<a<<endl;
           i.accountbalance= i.accountbalance+x; 
           saveclientdata("myfile.text",vclient);
           cout<<"new balance:"<<i.accountbalance;
        }
        }
        cout<<endl;
        cout<<"done"<<endl;
}


//check balance



void checkthebalance(string account,string pin){
    vector<bank>vclient=showfile("myfile.text");
    bank s;

        for(bank &i:vclient){
            if(i.accountnumber==account&&i.pincod==pin){
                int a=i.accountbalance;
                cout<<"you balance is :"<<a<<endl;
          
               }
            }
        cout<<endl;
        cout<<"done"<<endl;
}
 

void gobackmainmenue(string account,string pin){
    
    cout<<endl;
    cout<<"press any key to go back to main menue"<<endl;
    system("pause>0");
    PRINTheader(account ,pin);}


void startatmain(enlog choice,string account,string pin){
  
    bank s;
    vector<bank>vclient=showfile("myfile.text");
   
    switch (choice)
    {
    case 1:{
         system("cls");
        finalquickwithdraw(account,pin);
        gobackmainmenue(account,pin);
         break;
    }
    case 2:{
        system("cls");
       withdrow(account,pin);
            gobackmainmenue(account,pin);
        break;
    }
    case 3:{
         system("cls");
       depost(account,pin);
        gobackmainmenue(account,pin);
        break;
    }
    case 4:{
        system("cls");
      checkthebalance(account,pin);
        gobackmainmenue(account,pin);
        break;
    }
     case 5:{
        system("cls");
        checkpassword();
        gobackmainmenue(account,pin);
        break;
    }
    }
    
}

void PRINTheader(string account ,string pin){
     cout<<" ===================================                          "<<endl;
    cout<<"     ATMmain menue screen                               "<<endl;
    cout<<" ===================================                          "<<endl;
    cout<<"[1] quick with drow"<<endl;
    cout<<"[2] normal with drow "<<endl;   
    cout<<"[3] deposit"<<endl;
    cout<<"[4] cheack balance"<<endl;
     cout<<"[5] log out"<<endl;
 enlog x = static_cast<enlog>(choselist());
 startatmain(x,account,pin);
}

void checkpassword(){
    cout<<"-----------------------------------"<<endl;
    cout<<"                 log in screan     "<<endl;
    cout<<"------------------------------------"<<endl;
    bank s;
    string account=readaccount();
    string pin=readpincode();
    if(checkstring(account,pin,s)){
        PRINTheader(account,pin);
    }
    else{
        cout<<"no find the accountnumber";
    }
}


 int main(){

    checkpassword();
    return 0;

 }



