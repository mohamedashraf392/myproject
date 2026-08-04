#pragma once
#ifndef CLSBANKCLIENT_H
#define CLSBANKCLIENT_H
#include <iostream>
#include"clsinputvalidate.h"
#include"clsperson.h"
#include"string.h"
#include"data.h"
#include<ctime>
#include<fstream>
# include<cmath>
#include<vector>
using namespace std;

class clsbank:public clsperson{
    private:
    enum enmode{emptmode=0,updatamode=1,addnewclient=2};
    enmode _mode;
    string _accountnumber;
    double _accountbalance;
    string _pincode;
    bool _markfordelete=false;

static clsbank _ConvertLinetoClientObject(string line,string splid="#//#"){
    vector<string>vclient;
    vclient=clstring::splidsline(line,splid);

  return  clsbank(enmode::updatamode,vclient[0],vclient[1],vclient[2],vclient[3],vclient[4],vclient[5],stod(vclient[6]));
}

  static clsbank _GetEmptyClientObject(){
    return clsbank(enmode::emptmode,"","","","","","",0);
  }

  //updata
    static string _ConverClientObjectToLine(clsbank Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client._firstname + Seperator;
        stClientRecord += Client._listname + Seperator;
        stClientRecord += Client._email + Seperator;
        stClientRecord += Client._phone + Seperator;
        stClientRecord += Client._accountnumber+ Seperator;
        stClientRecord += Client._pincode + Seperator;
        stClientRecord += to_string(Client._accountbalance);

        return stClientRecord;

    }

    static  vector <clsbank> _LoadClientsDataFromFile()
    {

        vector <clsbank> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsbank Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsbank> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsbank C : vClients)
            {
                DataLine = _ConverClientObjectToLine(C);
                MyFile << DataLine << endl;

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsbank> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsbank& C : _vClients)
        {
            if (C.getaccountnumber() == getaccountnumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

  
    

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }


    public:
    //property
    struct logregist{
        string dat;
        string account1;
        string account2;
        double accountbalance1;
        double accountbalance2;
        double balance;
        string fullname;

    };

    clsbank(enmode mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        double AccountBalance) :clsperson(FirstName, LastName, Email, Phone)

    {
        _mode = mode;
        _accountnumber= AccountNumber;
        _pincode = PinCode;
        _accountbalance = AccountBalance;
    }

    bool isempty(){
        return (_mode==enmode::emptmode);
    }

    string getaccountnumber(){
        return _accountnumber;
    }

    void setaccountbalance(double balance){
        _accountbalance=balance;
    }
    
    double getaccountbalance(){
        return _accountbalance;
    }

     void setpincode(string balance){
      _pincode=balance;
    }
    
    string getpincode(){
        return _pincode;}


        //funcation of find

        //find client
   static clsbank Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsbank Client = _ConvertLinetoClientObject(Line);
                if (Client.getaccountnumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
              
            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

       
   static clsbank Find(string AccountNumber,string pin)
    {
       

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsbank Client = _ConvertLinetoClientObject(Line);
                if (Client.getaccountnumber() == AccountNumber&&Client.getpincode()==pin)
                {
                    MyFile.close();
                    return Client;
                }
              
            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static bool isclientexit(string accountnumber){
        clsbank Client = clsbank::Find(accountnumber);
        return (!Client.isempty());
    }



    //saveclient
    
 static void readclient(clsbank& client){
    cout<<"please enter firstname "<<endl;
   client._firstname=clsvalidate::readstring();
   cout<<"pleas ente listname"<<endl;
   client._listname=clsvalidate::readstring();

   cout<<"pleas ente email"<<endl;
   client._email=clsvalidate::readstring();

   cout<<"pleas ente phone"<<endl;
   client._phone=clsvalidate::readstring();

   cout<<"pleas ente pincode"<<endl;
   client._pincode=clsvalidate::readstring();

   cout<<"pleas ente account balance"<<endl;
   client._accountbalance=clsvalidate::readdoublenumber();

}



    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1,failaccountnumberexit=2 };

   enSaveResults Save()
    {

        switch (_mode)
        {
        case enmode::emptmode:
        {       
        
         return enSaveResults::svFaildEmptyObject;
        }

        case enmode::updatamode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enmode::addnewclient:
        {
            if(clsbank::isclientexit(_accountnumber)){
                   return enSaveResults::failaccountnumberexit;
            }
            else{

                _AddNew();
            }
            break;
        }

    }
        }


        static clsbank getaddnew(string account){
            return clsbank(enmode::addnewclient,"","","","",account,"",0);
        }


  static vector<clsbank> saveclientdata(vector<clsbank>&vclient)
{
       
    string dataline;
    fstream myfile;

    myfile.open("Clients.txt", ios::out);

    if (myfile.is_open())
    {
        for (clsbank &i : vclient)
        {
            if (i._markfordelete == false)
            {
                dataline = _ConverClientObjectToLine(i); // not delete the line
                myfile << dataline << endl;
            }
        }

        myfile.close();
    }

    return vclient;
}



 bool deleteclient(){
        
        vector <clsbank> _vClients;
        _vClients = _LoadClientsDataFromFile();
        for(clsbank& i:_vClients){
            if(i.getaccountnumber()==_accountnumber){
            i._markfordelete=true;
            
            }
            
        }
     saveclientdata(_vClients);
        *this=_GetEmptyClientObject();
        return true;

    }


  static  vector<clsbank> getclientlist(){
        return _LoadClientsDataFromFile();
    }


    static double gettotalbalanc(){
        vector<clsbank>vclient=clsbank::getclientlist();
        double totalbalance=0;
        for(clsbank i:vclient){
            totalbalance+=i._accountbalance;
        }
        return totalbalance;
    }

     void getdepost(int number){
           _accountbalance=_accountbalance+number;
           Save();
       
    }

  bool getwithdow(int number){
    if(number>_accountbalance){
        return false;
    }
    else{
        _accountbalance=_accountbalance+(-1*number);
        Save();
    }
       
    }

    bool transferscreen(clsbank& client2,double balance){




   if (balance >_accountbalance)
        {
            return false;
        }
    
        getwithdow(balance);
        client2.getdepost(balance);
        return true;
    } 




     
string changedatatostring(double balance,string name,clsbank i,string dlim="#//#"){

   string x;
   clsdata dat=clsdata::getsystemday();
   
   x=to_string(dat.getday())+"/";
   x+=to_string(dat.getmonth())+"/";
   x+=to_string(dat.getyear())+"/ ";
   x+=to_string(dat.gethour())+"/ ";
    x+=to_string(dat.getmintus())+"/ ";
     x+=to_string(dat.getsecond())+dlim;
     x+=getaccountnumber()+dlim;
     x+=i.getaccountnumber()+dlim;
       x+=to_string(getaccountbalance())+dlim;
    x+=to_string(i.getaccountbalance())+dlim;
    x+=to_string(balance)+dlim;
    x+=name+dlim;
   return x;
}

 void _adddateinfilenew(string data){
        fstream myfile;
        myfile.open("registlog.txt",ios::out | ios::app);
        if(myfile.is_open()){
            myfile<<data<<endl;
        }
        myfile.close();

    }

    void addusernew(double balance,string name,clsbank& i){
        _adddateinfilenew(changedatatostring(balance,name,i));
    }



    static logregist _ConvertLinetouserObjectinregist(string line,string splid="#//#"){
    vector<string>vclient;
    vclient=clstring::splidsline(line,splid);
    logregist s;
        s.dat=vclient[0];
        s.account1=vclient[1];
        s.account2=vclient[2];
        s.accountbalance1=stoi(vclient[3]);
         s.accountbalance2=stoi(vclient[4]);
          s.balance=stoi(vclient[5]);
            s.fullname=vclient[6];
    return s;
}
   
      static  vector <logregist> _LoadClientsDataFromFileinregist()
    {

        vector <logregist> vClients;

        fstream MyFile;
        MyFile.open("registlog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

           string Line;

         logregist s;
            while (getline(MyFile, Line))
            {
               
                if(Line!=""){

                s= _ConvertLinetouserObjectinregist(Line);

                vClients.push_back(s);
                }
            }

            MyFile.close();

        }

        return vClients;
        system("pause>null");

    }





};






#endif