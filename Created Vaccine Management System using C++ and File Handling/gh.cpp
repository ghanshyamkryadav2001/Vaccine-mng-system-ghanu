#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
#define num_of_vaccine 200

int password();
void menu();
void show();
class vaccine
{
    int age;
    int temperature;
    int blood_pressure;
    char gender;
    string name;
    string aadhar;
    string profession;
    string address;
    string mobile_number;
    int cnt;
public:
    void search_data();
    
    void add_new();
    void setdata();
    void view_vaccine();
    void showdata();
    void search_by_aadhar();
    void search_by_age();
    void search_by_profession();
    void search_by_gender();
    void search_by_name();
    void people_list();
    void show_list();
};
void show()
{
    cout<<setw(20)<<setiosflags(ios::left)<<"Name ";
    cout<<setw(20)<<"Aadhar No.";
    cout<<setw(10)<<"Age";
    cout<<setw(18)<<"Profession";
    cout<<setw(8)<<"B.P.";
    cout<<setw(15)<<"Temperature";
    cout<<setw(7)<<"gender";
    cout<<setw(15)<<"Mobile No.";
    cout<<"Address"<<endl;
}

void vaccine ::view_vaccine()
{
    ifstream ind;
    int i=0;
    ind.open("vaccinetrial.txt");
    ind.seekg(0,ios::beg);
    while(ind.read((char*)this,sizeof(vaccine)))
    {
        i++;
    }
    ind.close();
    int ch;
    int s=num_of_vaccine-i;
       cout<<"\n\n\t\t\########## VACCINE MANAGEMENT SYSTEM  ##########\n\n"<<endl;
    cout<<"\t\t\t\t\t\t By:- Ghanshyam Kumar Yadav "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\tVACCINE STATISTICS";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"\t\t 1. Add more        \t\t\t2.View available \n\t\t\t\t\t 3. Back"<<endl;
    cin>>ch;
int keep_updated=0;
     fstream file("mydata.txt",ios::out|ios::in);
    file.read((char*)&keep_updated,sizeof(keep_updated));
    switch(ch)
    {
    case 1:
        int m;
        cout<<"\t Enter number of vaccines you want to add "<<endl;
        cin>>m;
        keep_updated=keep_updated+m;
        file.write((char*)&keep_updated,sizeof(keep_updated));
        cout<<"\t\t Now total number of vaccines are : "<<keep_updated+s;
        break;
    case 2:
        cout<<"\n\nAvailable number of vaccines are :"<<s+keep_updated;
        break;
    case 3:
        system("cls");
        menu();
    default:
        system("cls");
        cout<<"\nEnter valid option "<<endl;
        menu();
    }
    file.close();
    getch();
}
void vaccine::show_list()
{
    cout<<"\n";
    cout<<setw(20)<<setiosflags(ios::left)<<name;
    cout<<setw(20)<<aadhar;
    cout<<setw(10)<<age;
    cout<<setw(18)<<profession;
    cout<<setw(8)<<blood_pressure;
    cout<<setw(15)<<temperature;
    cout<<setw(7)<<gender;
    cout<<setw(15)<<mobile_number;
    cout<<address<<endl;
}
void vaccine::search_data()
{
    vaccine item;
        cout<<"\n\n\t\t\########## VACCINE MANAGEMENT SYSTEM  ##########\n\n"<<endl;
    cout<<"\t\t\t\t\t\t  By:- Ghanshyam Kumar Yadav "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\tSEARCHING STATISTICS";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"From which option you want to perform searching "<<endl;
    cout<<"\n\t\t 1. By aadhar \t\t\t 2. By Age "<<endl;
    cout<<"\n\t\t 3. By profession \t\t 4. By gender "<<endl;
    cout<<"\n\t\t 5. By name          \t\t 6. List of people vaccinated"<<endl;
    cout<<"\n\n\t\tEnter your choice ...............";
    int ch;
    cin>>ch;
    switch(ch)
    {
    case 1:
        system("cls");
        search_by_aadhar();
        getch();
        break;
    case 2:
        system("cls");
        search_by_age();
        getch();
        break;
    case 3:
        system("cls");
        search_by_profession();
        getch();
        break;
    case 4:
        system("cls");
        search_by_gender();
        getch();
        break;
    case 5:
        system("cls");
        search_by_name();
        getch();
        break;
    case 6:
        system("cls");
        people_list();
        getch();
    default:
        system("cls");
        cout<<"ENTER VALID OPTION"<<endl;
        menu();
    }
}
void vaccine :: search_by_name()
{
         cout<<"\n\n\t\t\########## VACCINE MANAGEMENT SYSTEM  ##########\n\n"<<endl;
    cout<<"\t\t\t\t\t\t By:- Ghanshyam Kumar Yadav "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t  SEARCHING BY NAME ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter name to be searched : "<<endl;
    ifstream file("vaccinetrial.txt");
    cin.ignore();
    string name1;
    getline(cin,name1);
    cin.ignore();
    file.read((char*)this,sizeof(vaccine));
    show();
    int p=0; int flag=0;
    while(!file.eof())
    {
        if(name==name1)
     {
     show_list();
        p++;
        flag=1;
     }
        file.read((char*)this,sizeof(vaccine));
    }
    cout<<endl;
    if(!flag)
       cout<<"\t\t\t data not available";
       file.close();

}
void vaccine::search_by_aadhar()
{
    ifstream in("vaccinetrial.txt");
    int flag =0;
    string adh_num;
       cout<<"\n\n\t\t\########## VACCINE MANAGEMENT SYSTEM  ##########\n\n"<<endl;
    cout<<"\t\t\t\t\t\t By:- Ghanshyam Kumar Yadav "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t AADHAR SEARCHING ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter your Aadhar number "<<endl;
    cin.ignore();
    getline(cin,adh_num);
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(adh_num==aadhar)
        {
            showdata();
            flag=1;
            break;
        }
    in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        cout<<"Aadhar number not found "<<endl;
    }
    in.close();
}
void vaccine::search_by_age()
{
   ifstream in("vaccinetrial.txt");
    int flag =0;
    int a,p=0;
       cout<<"\n\n\t\t\########## VACCINE MANAGEMENT SYSTEM  ##########\n\n"<<endl;
    cout<<"\t\t\t\t\t\t By:- Ghanshyam Kumar Yadav "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t AGE SEARCHING ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"enter Age by which you want to search "<<endl;
    cin>>a;
    show();
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(a==age)
        {
            show_list();
            flag=1;
            p++;
        }
    in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
    cout<<"Age you entered is not found"<<endl;
    }
    cout<<"\n\n\n\nNO of people vaccinated  by this age"<<p;
    in.close();

}
void vaccine::search_by_profession()
{
    ifstream in("vaccinetrial.txt");
    int flag =0;
    int p=0;
    string prof;
       cout<<"\n\n\t\t\########## VACCINE MANAGEMENT SYSTEM  ##########\n\n"<<endl;
    cout<<"\t\t\t\t\t\t  By:- Ghanshyam Kumar Yadav "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t PROFESSION SEARCHING ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"enter Profession by which you want to search "<<endl;
    cin.ignore();
    getline(cin,prof);
    show();
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(prof.compare(profession)==0)
        {
            show_list();
            flag=1;
            p++;
        }
    in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
    cout<<"The profession you have Enter does not exist"<<endl;
    }
    cout<<"\n\n\n NO of people vaccinated by this profession "<<p<<endl;
    in.close();
}
void vaccine::search_by_gender()
{
    ifstream in("vaccinetrial.txt");
    int flag =0;
    char g;
    int p=0;
       cout<<"\n\n\t\t\########## VACCINE MANAGEMENT SYSTEM  ##########\n\n"<<endl;
    cout<<"\t\t\t\t\t\t By:-Ghanshyam Kumar Yadav "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t GENDER SEARCHING ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter gender by which you want to search "<<endl;
    cin>>g;
    show();
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(toupper(g)==toupper(gender))
        {
            show_list();
            flag=1;
            p++;
        }
    in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
    cout<<"The gender you entered does not exist "<<endl;
    }
    cout<<"\n\n\n NO. of people vaccinated by this gender "<<p<<endl;
    in.close();
}
void vaccine :: people_list()
{     cout<<"\n\n\t\t\########## VACCINE MANAGEMENT SYSTEM  ##########\n\n"<<endl;
    cout<<"\t\t\t\t\t\t By:-Ghanshyam Kumar Yadav "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t LIST OF PEOPLE VACCINATED  ";
    cout<<"\n\t\t\t*****************************************\n\n";
    ifstream file;
    file.open("vaccinetrial.txt");
    show();
    file.read((char*)this,sizeof(vaccine));
    while(!file.eof())
    {
        show_list();
        file.read((char*)this,sizeof(vaccine));

    }
}
void vaccine::setdata()
{
      cout<<"\n\n\t\t\########## VACCINE MANAGEMENT SYSTEM  ##########\n\n"<<endl;
    cout<<"\t\t\t\t\t\t By:- Ghanshyam Kumar Yadav "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cin.ignore();
        cout<<"\n\t\t Enter your name :-  ";
        getline(cin,name);
        cout<<"\n\t\t Enter your aadhar :-  ";
        getline(cin,aadhar);
        cout<<"\n\t\t Enter your gender (M|F) :-  ";
        cin>>gender;
        cout<<"\n\t\t Enter your age:- ";
        cin>>age;
        cin.ignore();
        cout<<"\n\t\t Enter your profession :-  ";
        getline(cin,profession);
        cout<<"\n\t\t Enter your B.P. :-  ";
        cin>>blood_pressure;
        cout<<"\n\t\t Enter your Body temperature:-  ";
        cin>>temperature;
        cin.ignore();
        cout<<"\n\t\t Enter your permanent address :-  ";
        getline(cin,address);
        cout<<"\n\t\t Enter your Mobile number :- ";
        getline(cin,mobile_number);
}
void vaccine::showdata()
{
       cout<<"\n\n\t\t\########## VACCINE MANAGEMENT SYSTEM  ##########\n\n"<<endl;
    cout<<"\t\t\t\t\t\t  By:- Ghanshyam Kumar Yadav"<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t DETAILS  ";
    cout<<"\n\t\t\t*****************************************\n\n";
   cout<<"\t\t Name is: "<<name<<endl;
   cout<<"\t\t Aadhar number is: "<<aadhar<<endl;
    cout<<"\t\t Your age is "<<age<<endl;
    cout<<"\t\t Profession is : "<<profession<<endl;
    cout<<"\t\t Gender is : "<<gender<<endl;
    cout<<"\t\t Blood pressure is :"<<blood_pressure<<endl;
    cout<<"\t\t Body temperature is : "<<temperature<<endl;
    cout<<"\t\t Address is "<<address<<endl;
    cout<<"\t\t Mobile number is: "<<mobile_number<<endl;
}
void vaccine::add_new()
{
    fstream outin;
    outin.open("vaccinetrial.txt",ios::app|ios::in);
    setdata();
    outin.write((char*)this,sizeof(vaccine));
    cout<<"YOUR DATA HAS BEEN SUCCESSFULLY INSERTED "<<endl;
    getch();
    outin.close();
}

void menu()
{
    system("cls");
       cout<<"\n\n\t\t\########## VACCINE MANAGEMENT SYSTEM  ##########\n\n"<<endl;
    cout<<"\t\t\t\t\t\t By:- Ghanshyam Kumar Yadav "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t\tMENU";
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\n\t\t1: Add NEW Record\t\t\t 2: View VACCINE DATA"<<endl;
    cout<<"\n\t\t3: search   \t\t\t\t 4: exit"<<endl;
}
int main()
 {
     vaccine obj;
     int k=3;
     int num_vac;
      cout<<"\n\n\t\t\########## VACCINE MANAGEMENT SYSTEM  ##########\n\n"<<endl;
    cout<<"\t\t\t\t\t\t  By:- Ghanshyam Kumar Yadav "<<endl;
     cout<<"\t\n\n Press any key to continue.............  "<<endl;
    getch();
    B:
    system("cls");
    cout<<"\n\n\t\t\t\t*********************************************";
    cout<<"\n\t\t\t\t\tEnter User name and Password\n";
    cout<<"\t\t\t\t*********************************************\n";
    while(k>=1)
    {
    int c = password();
    if(c==1)
        break;
    else
        cout<<"\n\n\t\t Wrong Password Or User Name \n\n\t\t You Can try Only "<<k-1<<" times more";
    k--;
    if(k<1)
        {
            for(int i=59; i>=0; i--)
            {
              system("cls");
              cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE!!";
              cout<<"\n\n\n\n\n\n\t\t\t\t\tTRY AFTER "<<i<<" SECONDS.....";
              Sleep(1000);
            }
              k=3;
              goto B;
        }
    }
      int ch;
      do{
            cout<<"\n\n\t\t\########## VACCINE MANAGEMENT SYSTEM  ##########\n\n"<<endl;
            cout<<"\t\t\t\t\t\t By:- Ghanshyam Kumar Yadav "<<endl;
            menu();
            cout<<"\n\t\n\tChoose according to your need : ";
            cin>>ch;
             vaccine v1;
      switch(ch)
       {
         case 1: system("cls");
                obj.add_new();
                 break;
         case 2: system("cls");
                obj.view_vaccine();
                 break;
         case 3:system("cls");
                obj.search_data();
                 break;
         case 4:  system("cls");
                    exit(0);
         default: system("cls");
                  cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
                  cout<<"\n\n\t\t\t\t\t****HAVE A NICE DAY*****";
                  Sleep(3000);
                  exit(0);
       }
      }while(ch!=0);

      return 0;
}
int password()
{
    string cname,pass;
    int ch, i=0,cap=0,capt=0;
    cout<<"\n\n\n\n\n\t\t\t\t\tUSER NAME:  ";
    cin.ignore();
    getline(cin,cname);
    cout<<"\n\t\t\t\t\tPASSWORD:    ";
    while((ch=getch())!= 13)
    {
        cout<<"*";
        pass.push_back(ch);
        i++;
    }
    srand(time(0));
    cap=rand();
    cout<<"\n\t\t\t\t\t CAPTCHA:->  "<<cap<<endl;
    cout<<" Please enter the valid captcha :-   ";
    cin>>capt;
    if( (cname=="amityadav") && (pass=="172000") && cap==capt)
        return 1;
    else
        return 0;
}




