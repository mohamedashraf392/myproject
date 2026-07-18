
#include<iostream>
#include<random>
#include<ctime>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;
enum enchoice{SHOW=1,ADD=2,DELETE=3,UPDATE=4,FIND=5,TRAN=6,manguserr=7,exiteee=8};
enum entrans{DEPOSIT=1,WITHDRAW=2,TOTALBALANCE=3,MAINMENUE=4};
enum enclient{listuser=1,adduser=2,deleteuser=3,upusder=4,finuser=5,mainuser=6};

struct user{
    string name;
    string password;
    int permissions;
     bool markfordeletenew=false;
};


struct bank{
    string accountnumber;
    string pincod;
    string name;
    string phone;
    int accountbalance;
    bool markfordelete=false;
};

void printheader(user w);
void printheadernew();
void play(enchoice choice);
void gobackmainmenue(user s);

 void checkfindusername();
void newprint();
void gobackmainmenuenew();
void go();
  
//show client list
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
void PrintClientRecord(bank client){
    cout<<setw(15)<<left<<client.accountnumber;
     cout<<setw(10)<<left<<client.pincod;
      cout<<setw(40)<<left<<client.name;
       cout<<setw(12)<<left<<client.phone;
        cout<<setw(12)<<left<<client.accountbalance;
}

void PrintAllClientsData(  vector <bank> &vcustomer)
{
 // vector <bank> vcustomer=showfile("myfile.text");
cout << "\n\t\t\t\t\tClient List (" << vcustomer.size();
cout<<"\n_______________________________________________________";
cout << "_________________________________________\n" << endl;
cout << "| " << left << setw(15) << "Accout Number";
cout << "| " << left << setw(10) << "Pin Code";
cout << "| " << left << setw(40) << "Client Name";
cout << "| " << left << setw(12) << "Phone";
cout << "| " << left << setw(12) << "Balance";
cout <<"\n_______________________________________________________";
cout << "_________________________________________\n" << endl;
for (bank &Client : vcustomer)
{
PrintClientRecord(Client);
cout << endl;
}
cout <<"\n_______________________________________________________";
cout << "----------------------------------------------------------\n" << endl;
}
//add new client
bank  add(){
    bank s;
    cout<< "enter account number"<<endl;
    cin>>s.accountnumber;
    cout<<"enter pin code"<<endl;
    cin>>s.pincod;
    cout<<"enter name"<<endl;
    cin>>s.name;
    cout<<"enter phone"<<endl;
    cin>>s.phone;
    cout<<"enter account balance"<<endl;
    cin>>s.accountbalance;
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

void adddatatofile(string file,string date){
    fstream myfile;
    myfile.open(file,ios::out|ios::app);
    if(myfile.is_open()){
        myfile<<date<<endl;
        myfile.close();
    }
}


 void complete(){
    bank s;
    s=add();
   adddatatofile("myfile.text",convertbanktostring(s));
 }

 void final(){
    char x='y';
    cout<<"please enter the data of customer"<<endl;
    do{
        complete();
        cout<<"do you went add new customer "<<endl;
        cin>>x;
    }
    while(x=='y'||x=='Y');
 }


//find string in file

 bool checkstring(string account,bank &s){
    vector<bank>varr=showfile("myfile.text");
    for(bank &i:varr){
        if(i.accountnumber==account){
            s=i;
            return true;
        }
    }
    return false;
 }

 void find(string account,bank &s){
    if(checkstring(account,s)){
        PrintClientRecord(s);
    }
    else
    cout<<"no fid here";

 }

//delete string

 
bool deletline(string account,vector<bank>&vclient)
{
     
    for (bank& i : vclient)
    {
        if (i.accountnumber == account)
        {
            i.markfordelete = true;
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




bool delettheaccount(string account,vector<bank>&vclient)
{
      
    bank s;
    char anser = 'n';

    if (checkstring(account, s))
    {
        PrintClientRecord(s);
        cout << endl;
        cout << "do you went delete the line" << endl;
        cin >> anser;

        if (anser == 'y' || anser == 'Y')
        {
            deletline(account,vclient);
            saveclientdata("myfile.text",vclient);

            // vclient.clear();

            vclient = showfile("myfile.text");

            cout << "client delete" << endl;
            return true;
        }
    }
    else
    {
        cout << "client is not find" << endl;
        return false;
    }
}

//update client data

bank addto(string account){
    bank s;
    s.accountnumber=account;
    cout<<"enter pin code"<<endl;
    cin>>s.pincod;
    cout<<"enter name"<<endl;
    cin>>s.name;
    cout<<"enter phone"<<endl;
    cin>>s.phone;
    cout<<"enter account balance"<<endl;
    cin>>s.accountbalance;
    return s;  

}


bool updateclient(string account,vector<bank>&vclient)
{
      
    bank s;
    char anser = 'n';

    if (checkstring(account, s))
    {
        PrintClientRecord(s);
        cout << endl;
        cout << "do you went update the line" << endl;
        cin >> anser;

        if (anser == 'y' || anser == 'Y')
        {
            for (bank& i : vclient)
            {
                if (i.accountnumber == account)
                {
                    cout << "enter new data" << endl;
                    i = addto(account);
                    break;
                }
            }
            saveclientdata("myfile.text", vclient);


            cout << "client updated" << endl;
            return true;
        }
    }
    else
    {
        cout << "client is not find" << endl;
        return false;
    }
}


int choceatlist(){
    int element;
    cout<<endl;
    cout<<"choce what do you went do you went to do[1]from[6]"<<endl;
    cin>>element;
    return element;
}

void end(){
    cout<<"---------------------------------------"<<endl;
    cout<<"progrem is end"<<endl;
    cout<<"---------------------------------------"<<endl;
}

string ACOUNTNAME(){
    string x;
    cout<<"please enter the account went you check"<<endl;
    cin>>x;
    return x;
}


void gobackmainmenue(user s){
    
    cout<<endl;
    cout<<"press any key to go back to main menue"<<endl;
    system("pause>0");
    printheader(s);}

//new bank account
//depost many;
int depostenter(){
    int many;
    cout<<"please enter the deposit?"<<endl;
    cin>>many;
    return many;
}

void depost(string account,vector<bank>&vclient){
    char w='y';
    bank s;
    
    if(checkstring(account,s)){
        PrintClientRecord(s);
         int x=depostenter();
         cout<<endl;
        for(bank &i:vclient){
            if(i.accountnumber==account){
           i.accountbalance= i.accountbalance+x;}
        }
        saveclientdata("myfile.text",vclient);
        cout<<endl;
        cout<<"done"<<endl;


    }
}
   
//withdrow

    int withdrowenter(){
    int many;
    cout<<"please enter the with drow?"<<endl;
    cin>>many;
    
    return many;
}
void withdrow(string account){
    vector<bank>vclient=showfile("myfile.text");
    char w='y';
    bank s;
      
    if(checkstring(account,s)){
        

    
        PrintClientRecord(s);
        cout<<endl;
       int x;
       x=withdrowenter();
        for(bank &i:vclient){
        if(i.accountnumber==account){
           i.accountbalance= i.accountbalance+(-1*x);
            }
            }
        }
        
        saveclientdata("myfile.text",vclient);
        cout<<endl;
        cout<<"done"<<endl;
    }


//total balance

void totalbalince(){
    vector<bank>vclient=showfile("myfile.text");
    PrintAllClientsData(vclient);
    int total=0;
    for(bank &i:vclient) {

total+=i.accountbalance;
    }
    cout<<"the total balance is:"<<total;
}

//main menue

void mainto(){
    user s;
    printheader(s);
}

void playtransaction(entrans choice){
  
    bank s;
    vector<bank>vclient=showfile("myfile.text");
   
    switch (choice)
    {
    case 1:{
         system("cls");
        depost(ACOUNTNAME(),vclient);
        go();
         break;
    }
    case 2:{
        system("cls");
        withdrow(ACOUNTNAME());
            go();
        break;
    }
    case 3:{
         system("cls");
        totalbalince();
        go();
        break;
    }
    case 4:{
        system("cls");
        mainto();
        go();
        break;
    }
    }
    
}


void newprint(){
    cout<<" ===================================                          "<<endl;
    cout<<"     transaction menue screen                               "<<endl;
    cout<<" ===================================                          "<<endl;
    cout<<"[1] deposit money"<<endl;
    cout<<"[2] withdraw money "<<endl;   
    cout<<"[3] total balance"<<endl;
    cout<<"[4] main menue"<<endl;
 entrans x = static_cast<entrans>(choceatlist());
playtransaction(x);
}

void go(){
    cout<<endl;
    cout<<"press any key to go back to main menue"<<endl;
    system("pause>0");
    newprint();}

//new

//show new client list

user convgrationnew(string line ,string dlim="#//#"){
    vector<string>varry;
    varry=splidsline(line,dlim);
    user s;
    s.name=varry[0];
    s.password=varry[1];
    s.permissions=stoi(varry[2]);
    return s;
}

vector<user> showfilenew(string file){
    vector <user>vclient;
    fstream client;
    client.open(file,ios::in);
    if(client.is_open()){
        string line;
        user s;
        while (getline(client,line))
        {
            s=convgrationnew(line);
            vclient.push_back(s);
        }
        client.close();
    }
    else{
        cout<<"error in open file"<<endl;
    }
    return vclient;
}
void PrintClientRecordnew(user s){
    cout<<setw(15)<<left<<s.name;
     cout<<setw(25)<<left<<s.password;
      cout<<setw(10)<<left<<s.permissions;
}

void PrintAllClientsDatanew( )
{
vector <user> vcustomer=showfilenew("client.text");
cout << "\n\t\t\t\t\tClient List (" << vcustomer.size();
cout<<"\n_______________________________________________________";
cout << "_________________________________________\n" << endl;
cout << "| " << left << setw(15) << " user name";
cout << "| " << left << setw(20) << "Password";
cout << "| " << left << setw(10) << "permission";

cout <<"\n_______________________________________________________";
cout << "_________________________________________\n" << endl;
for (user &s : vcustomer)
{
PrintClientRecordnew(s);
cout << endl;
}
cout <<"\n_______________________________________________________";
cout << "----------------------------------------------------------\n" << endl;
}


//add new client

int permissionnew(){
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
        permission+=1;
    }


    cout<<"add client?"<<endl;
    cin>>w;
    if(w=='y'){
        permission+=2;
    }

    
    cout<<"delete client?"<<endl;
    cin>>w;
    if(w=='y'){
        permission+=4;
    }

    
    cout<<"update client?"<<endl;
    cin>>w;
    if(w=='y'){
        permission+=8;
    }

    
    cout<<"find client?"<<endl;
    cin>>w;
    if(w=='y'){
        permission+=16;
    }

    
    cout<<"transaction client?"<<endl;
    cin>>w;
    if(w=='y'){
        permission+=32;
    }
    
    cout<<" mange user client?"<<endl;
    cin>>w;
    if(w=='y'){
        permission+=64;
    }

    return permission;

}

user  addnew(){
    user s;
   cout<<"please enter user name"<<endl;
   cin>>s.name;
   cout<<"please enter password"<<endl;
   cin>>s.password;
   s.permissions=permissionnew();
    return s;
}
 string convertbanktostringnew(user s,string dlim="#//#"){
    string x="";
    x+=s.name+dlim;
    x+=s.password+dlim;
    x+=to_string(s.permissions)+dlim;
    return x;
 }

void adddatatofilenew(string file,string date){
    fstream client;
    client.open(file,ios::out|ios::app);
    if(client.is_open()){
        client<<date<<endl;
        client.close();
    }
}


 void completenew(){
    user s;
    s=addnew();
   adddatatofilenew("client.text",convertbanktostringnew(s));
 }

 void finalnew(){
    char x='y';
    cout<<"please enter the data of customer"<<endl;
    do{
        completenew();
        cout<<"do you went add new customer "<<endl;
        cin>>x;
    }
    while(x=='y'||x=='Y');
 }

//delete new

string nameclient(){
    string x;
    cout<<"please enter the account went to check"<<endl;
    cin>>x;
    return x;
}


 bool checkstringnew(string nameclient,user&s){
    vector <user> vcustomer=showfilenew("client.text");
    for(user &i:vcustomer){
        if(i.name==nameclient){
            s=i;
            return true;
        }
    }
    return false;
 }



vector<user> deletlinenew(string nameclient)
{
     
vector <user> vcustomer=showfilenew("client.text");
    for (user& i : vcustomer)
    {
        if (i.name == nameclient)
        {
            i.markfordeletenew = true;
            return vcustomer;
        }
    }
    return vcustomer;
}

vector<user> saveclientdatanew(string file,vector <user> &vcustomer)
{
         
//vector <user> vcustomer=showfilenew("client.text");
    string dataline;
    fstream client;

    client.open(file, ios::out);

    if (client.is_open())
    {
        for (user &i : vcustomer)
        {
            if (i.markfordeletenew == false)
            {
                dataline = convertbanktostringnew(i); 
                client << dataline << endl;
            }
        }

        client.close();
    }

    return vcustomer;
}




bool delettheaccountnew(string nameclient)
{
    user s;
    char anser = 'n';

    vector <user> vcustomer=showfilenew("client.text");
    if (checkstringnew(nameclient, s))
    {
        PrintClientRecordnew(s);
        cout << endl;
        cout << "do you went delete the line" << endl;
        cin >> anser;

        if (anser == 'y' || anser == 'Y')
        {
           vcustomer= deletlinenew(nameclient);
            saveclientdatanew("client.text",vcustomer);            
           vcustomer=showfilenew("client.text");
            cout << "client delete" << endl;
            return true;
        }
    }
    else
    {
        cout << "client is not find" << endl;
        return false;
    }
}


////update client


user  addnewupdata(string  nameclient){
    user s;
    s.name=nameclient;
   cout<<"please enter password"<<endl;
   cin>>s.password;
   s.permissions=permissionnew();
    return s;
}


bool updateclientnew(string nameclient)
{
       vector <user> vcustomer=showfilenew("client.text");
    user s;
    char anser = 'n';

    if (checkstringnew(nameclient, s))
    {
        PrintClientRecordnew(s);
        cout << endl;
        cout << "do you went update the line" << endl;
        cin >> anser;

        if (anser == 'y' || anser == 'Y')
        {
            for (user& i : vcustomer)
            {
                if (i.name == nameclient)
                {
                    cout << "enter new data" << endl;
                    i = addnewupdata(nameclient);
                    break;
                }
            }
            saveclientdatanew("client.text", vcustomer);


            cout << "client updated" << endl;
            return true;
        }
    }
    else
    {
        cout << "client is not find" << endl;
        return false;
    }
}

//find user



 void findnew(string nameclient){
    user s;
    if(checkstringnew(nameclient,s)){
        PrintClientRecordnew(s);
    }
    else
    cout<<"no fid here";

 }


void gobackmainmenuenew(){
    cout<<endl;
    cout<<"press any key to go back to main menue"<<endl;
    system("pause>0");
    printheadernew();}

 
void dataofuser(enclient client){
  
    user s;
    vector<bank>vclient=showfile("myfile.text");
   
    switch (client)
    {
    case 1:{
        system("cls");
        PrintAllClientsDatanew();
        gobackmainmenuenew();
         break;
    }
    case 2:{
        system("cls");
        finalnew();
            gobackmainmenuenew();
        break;
    }
    case 3:{
        system("cls");
        cout<<delettheaccountnew(nameclient());
        gobackmainmenuenew();
        break;
    }
    case 4:{
        system("cls");
        cout<<updateclientnew(nameclient());
        gobackmainmenuenew();
        break;
    }
    case 5:{
        system("cls");
        findnew(nameclient());
        gobackmainmenuenew();

        break;
    }
    case 6:{
        printheader(s);
        break;
    }
    }
   
}
void printheadernew(){
    cout<<" ===================================                          "<<endl;
    cout<<"              mange user main screen                               "<<endl;
    cout<<" ===================================                          "<<endl;
    cout<<"[1] show client list"<<endl;
    cout<<"[2] add new user "<<endl;
    cout<<"[3] delete user"<<endl;
    cout<<"[4] update user"<<endl;
    cout<<"[5] find user"<<endl;
    cout<<"[6] mainmenue"<<endl;
    enclient x = static_cast<enclient>(choceatlist());
    cout<<endl;
  dataofuser(x);
  cout<<endl;
    
}


string pass(){
    string x;
    cout<<"please enter password"<<endl;
    cin>>x;
    return x;
}
bool checkemail(string nameclient,string pass,user&s){
   
     vector <user> vcustomer=showfilenew("client.text");
    for(user &i:vcustomer){
        if(i.name==nameclient&&i.password==pass){
             s=i;
            return true;
        }
    }
    return false;
 }


bool isperformision(user& s,int choce){
    if(s.permissions==-1){
        return true;
    }
    int binarychoice=pow(2,choce-1);
    return (((s.permissions&binarychoice)==binarychoice)||choce==8);
}

 void checkfindusername(){
    cout<<"-------------------------------------"<<endl;
    cout<<"          login screen               "<<endl;
      cout<<"-------------------------------------"<<endl;
   user s;
    if(checkemail(nameclient(),pass(),s)){
       
        printheader(s);}
    
    else{
        cout<<"the account not find please try again";
    }
}

 
void play(user w,enchoice choice){

    bank s;
    vector<bank>vclient=showfile("myfile.text");
   if(isperformision(w,choice)){
    switch (choice)
    {
    case 1:{
        system("cls");
        PrintAllClientsData(vclient);
        gobackmainmenue(w);
         break;
    }
    case 2:{
        system("cls");
        final();
            gobackmainmenue(w);
        break;
    }
    case 3:{

        system("cls");
        cout<<delettheaccount(ACOUNTNAME(),vclient);
        gobackmainmenue(w);
        break;
    }
    case 4:{
        system("cls");
        cout<<updateclient(ACOUNTNAME(),vclient);
        gobackmainmenue(w);
        break;
    }
    case 5:{
        system("cls");
        find(ACOUNTNAME(),s);
        gobackmainmenue(w);

        break;
    }
    case 6:{
        newprint();
        break;
    }
    case 7:{
        printheadernew();
        break;
    }

     case 8:{
        checkfindusername();
        break;
    }

    }
}
else{
    cout<<"no permissio in the choice";
    gobackmainmenue(w);
}
}

void printheader(user w){
   
    cout<<" ===================================                          "<<endl;
    cout<<"              main menue screen                               "<<endl;
    cout<<" ===================================                          "<<endl;
    cout<<"[1] show client list"<<endl;
    cout<<"[2] add new client "<<endl;
    cout<<"[3] deleteclient"<<endl;
    cout<<"[4] update client"<<endl;
    cout<<"[5] find client"<<endl;
    cout<<"[6] trasaction"<<endl;
    cout<<"[7] mange user"<<endl;
    cout<<"[8] logout";
    enchoice x = static_cast<enchoice>(choceatlist());
    cout<<endl;
  play(w,x);
  cout<<endl;
    
}


int main(){
  checkfindusername();
    return 0;
}

    