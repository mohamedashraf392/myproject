#pragma once
#ifndef CLSUSER_H
#define CLSUSER_H
#include <iostream>
#include"clsinputvalidate.h"
#include"clsperson.h"
#include"string.h"
#include"data.h"
#include"clsutil.h"
#include<ctime>
#include<fstream>
# include<cmath>
#include<vector>
using namespace std;

class clsuser:public clsperson{
    private:
    enum enmode{emptmode=0,updatamode=1,addnewclient=2};
    enmode _mode;
    string _name;
    string _password;
    int _permission;
    bool _markfalse=false;
    string dayall;

static clsuser _ConvertLinetouserObject(string line,string splid="#//#"){
    vector<string>vclient;
    vclient=clstring::splidsline(line,splid);

  return  clsuser(enmode::updatamode,vclient[0],vclient[1],vclient[2],vclient[3],vclient[4],clsUtil::DecryptText(vclient[5]),stod(vclient[6]));
}

  static clsuser _GetEmptyClientObject(){
    return clsuser(enmode::emptmode,"","","","","","",0);
  }

      static  vector <clsuser> _LoadClientsDataFromFile()
    {

        vector <clsuser> vClients;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsuser Client = _ConvertLinetouserObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

     static string _ConverClientObjectToLine(clsuser Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client._firstname + Seperator;
        stClientRecord += Client._listname + Seperator;
        stClientRecord += Client._email + Seperator;
        stClientRecord += Client._phone + Seperator;
        stClientRecord += Client._name+ Seperator;
        stClientRecord +=clsUtil::EncryptText(Client._password) + Seperator;
        stClientRecord += to_string(Client._permission);

        return stClientRecord;

    }

    static void _SaveCleintsDataToFile(vector <clsuser>& vClients)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsuser C : vClients)
            {
                DataLine = _ConverClientObjectToLine(C);
                MyFile << DataLine << endl;

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsuser> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsuser& C : _vClients)
        {
            if (C.getname() == getname())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _adddateinfile(string data){
        fstream myfile;
        myfile.open("Users.txt",ios::out | ios::app);
        if(myfile.is_open()){
            myfile<<data<<endl;
        }
        myfile.close();

    }

  
void _adduser(){
     _adddateinfile( _ConverClientObjectToLine(*this));
     cout<<endl;
}




  public:

    enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64,pLogRegist=128
    };

    struct logregist{
        string dat;
        string user;
        string password;
        int permission;
    };

clsuser(enmode mode,string first,string list,string email,string phone,string name,string pass,int per)
:clsperson(first,list,email,phone){
_mode=mode;
_name=name;
_password=pass;
_permission=per;
}

bool isempty(){
    return _mode==enmode::emptmode;
}

 void setname(string name){
_name=name;
}

string getname(){
    return _name;
}


void setpassword(string pass){
_password=pass;
}

string getpassword(){
    return _password;
}


void setoermission(int per){
_permission=per;
}

int  getpermission(){
    return _permission;
} 


static clsuser find(string password){

    fstream MyFile ;
    MyFile.open("Users.txt",ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
               clsuser user = _ConvertLinetouserObject(Line);
                if (user.getname() == password)
                {
                    MyFile.close();
                    return user;
                }
              
            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }


static clsuser find(string name, string pass ){

    fstream MyFile ;
    MyFile.open("Users.txt",ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
               clsuser user = _ConvertLinetouserObject(Line);
                if (user.getname() ==name&&user.getpassword()==pass )
                {
                    MyFile.close();
                    return user;
                }
              
            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }


  static  bool userfind(string password){
       clsuser user= clsuser::find(password);
       return (!(user.isempty()));

    }

     static  vector<clsuser> getclientlist(){
        return _LoadClientsDataFromFile();
    }

    
static int permissionnew(){
    int permission=0;
    char w='y';
    cout<<"do you went to give full access?"<<endl;
    cin>>w;
    if(w=='y'){
        return -1;
    }

    
    cout<<"show client?"<<endl;
    cin>>w;
    if(w=='y'){
        permission+=clsuser::enPermissions::pListClients;
    }


    cout<<"add client?"<<endl;
    cin>>w;
    if(w=='y'){
        permission+=clsuser::enPermissions::pAddNewClient;
    }

    
    cout<<"delete client?"<<endl;
    cin>>w;
    if(w=='y'){
        permission+=clsuser::enPermissions::pDeleteClient;
    }

    
    cout<<"update client?"<<endl;
    cin>>w;
    if(w=='y'){
        permission+=clsuser::enPermissions::pUpdateClients;
    }

    
    cout<<"find client?"<<endl;
    cin>>w;
    if(w=='y'){
        permission+=clsuser::enPermissions::pFindClient;
    }

    
    cout<<"transaction client?"<<endl;
    cin>>w;
    if(w=='y'){
        permission+=clsuser::enPermissions::pTranactions;
    }
    
    cout<<" mange user client?"<<endl;
    cin>>w;
    if(w=='y'){
        permission+=clsuser::enPermissions::pManageUsers;
    }

     cout<<" log regist?"<<endl;
    cin>>w;
    if(w=='y'){
        permission+=clsuser::enPermissions::pLogRegist;
    }

    return permission;

}


    
 static void readclient(clsuser& client,string name){
    cout<<"please enter firstname "<<endl;
   client._firstname=clsvalidate::readstring();
   cout<<"pleas ente listname"<<endl;
   client._listname=clsvalidate::readstring();

   cout<<"pleas ente email"<<endl;
   client._email=clsvalidate::readstring();

   cout<<"pleas ente phone"<<endl;
   client._phone=clsvalidate::readstring();

   //cout<<"pleas ente name"<<endl;
   //client._name=clsvalidate::readstring();
   client._name=name;

cout<<"password;"<<endl;
    client._password=clsvalidate::readstring();
    
    //clsUtil::EncryptText( client._password,5);

   cout<<"pleas enter the permission"<<endl;
   client._permission=permissionnew();

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
            if(clsuser::userfind(_name)){
                return enSaveResults::failaccountnumberexit;
                break;
            }
            else{
                _adduser();

            }
        }
    }
}




        static clsuser getaddnew(string account){
            return clsuser(enmode::addnewclient,"","","","",account,"",0);
        }



        
  static vector<clsuser> saveclientdata(vector<clsuser>&vclient)
{
       
    string dataline;
    fstream myfile;

    myfile.open("Users.txt", ios::out);

    if (myfile.is_open())
    {
        for (clsuser &i : vclient)
        {
            if (i._markfalse == false)
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
        
        vector <clsuser> _vClients;
        _vClients = _LoadClientsDataFromFile();
        for(clsuser& i:_vClients){
            if(i.getname()==_name){
            i._markfalse=true;
            
            }
            
        }
     saveclientdata(_vClients);
        *this=_GetEmptyClientObject();
        return true;

    }


 bool ischeckaccesspermision(enPermissions permisions){
        if(this->_permission==enPermissions::eAll){
            return true;
        }

        if((this->_permission&permisions)==permisions){
            return true;
        }
        else
        return false;

    }






    
string changedatatostring(clsuser i,string dlim="#//#"){

   string x;
   clsdata dat=clsdata::getsystemday();

   x=to_string(dat.getday())+"/";
   x+=to_string(dat.getmonth())+"/";
   x+=to_string(dat.getyear())+"/ ";
   x+=to_string(dat.gethour())+"/ ";
    x+=to_string(dat.getmintus())+"/ ";
     x+=to_string(dat.getsecond())+dlim;
     x+=i.getname()+dlim;
    x+=clsUtil::EncryptText(i.getpassword())+dlim;
    x+=to_string(i.getpermission());
   return x;
}

 void _adddateinfilenew(string data){
        fstream myfile;
        myfile.open("regist.txt",ios::out | ios::app);
        if(myfile.is_open()){
            myfile<<data<<endl;
        }
        myfile.close();

    }

    void addusernew(){
        _adddateinfilenew(changedatatostring(*this));
    }


    //log regist

static logregist _ConvertLinetouserObjectinregist(string line,string splid="#//#"){
    vector<string>vclient;
    vclient=clstring::splidsline(line,splid);
    logregist s;
        s.dat=vclient[0];
        s.user=vclient[1];
        s.password=clsUtil::DecryptText(vclient[2]);
        s.permission=stoi(vclient[3]);
  
    return s;
}
   
      static  vector <logregist> _LoadClientsDataFromFileinregist()
    {

        vector <logregist> vClients;

        fstream MyFile;
        MyFile.open("regist.txt", ios::in);//read Mode

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