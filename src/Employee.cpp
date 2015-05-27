#include "Employee.h"
#include <iostream>
#include <iomanip>      //do formatowania
using namespace std;

///////////////////KONSTRUKTORY////////////////////////
Employee::Employee()
{
    name="Gall";
    surname="Anonim";
    sex='?';
    company="NONE";
    salary=0.00;
    satisfaction=0;
    result[0]={0};
}

Employee::Employee(string n,string m,string comp,char c,int s,double sd,int t[])
{
    name=n;
    surname=m;
    sex=c;
    company=comp;
    salary=sd;
    satisfaction=s;
    for(int i=0;i<12;i++)
    result[i]=t[i];
}
//////////////////////DEKONSTRUKTOR////////////////////////////////
Employee::~Employee()
{
    ;
}

//////////////////FUNKCJE POKAZOWE/////////////////////////
string Employee::show_name()
{
    cout.width(13);
    cout<<left<<"Name: "<<name<<endl;
    return name;
}

string Employee::show_surname()
{
    cout.width(13);
    cout<<"Surname: "<<surname<<std::endl;
    return surname;
}

char Employee::show_sex()
{
    cout.width(13);
    cout<<"Sex: "<<sex<<endl;
    return sex;
}

string Employee::show_company()
{
    cout.width(13);
    std::cout<<"Company: "<<company<<std::endl;
    return company;
}

int Employee::show_satif()
{
    cout.width(13);
    std::cout<<"Satisfacted: "<<satisfaction<<"%"<<std::endl;
    return satisfaction;
}

double Employee::show_salary()
{
    cout.width(13);
    std::cout<<left<<"Salary: "<<salary<<"$"<<std::endl;
    return salary;
}

void Employee::show_result()
{
    std::cout<<"Result: ";
    cout<<"     ";
    for(int i=0;i<12;i++)
        std::cout<<result[i]<<" | ";
    std::cout<<"\n";
}

int Employee::show_number()
{
   ;
}

void Employee::present()
{
    cout<<"=========================================================================\n";
    show_name();
    show_surname();
    show_sex();
    show_company();
    show_salary();
    show_satif();
    show_result();
    show_number();
    cout<<"=========================================================================\n";
}
//============================================================
////////////////////////////FUNKCJE USTAWIAJACE////////////////////////////
void Employee::set_name(string n)
{
    name=n;
}

void Employee::set_surname(string s)
{
    surname=s;
}

void Employee::set_sex(char c)
{
    sex=c;
}

void Employee::set_company(string c)
{
    company=c;
}

void Employee::set_satif(int s)
{
    satisfaction=s;
}

void Employee::set_salary(double s)
{
    salary=s;
}

void Employee::set_result()
{
    for(int i=0;i<12;i++)
    {
        cout<<"Enter number: "<<i+1<<": ";
        cin>>result[i];
    }
}

void Employee::set_employee()
{
    //zmienne przechowujace
    string n,sr,cmp;
    char sx;
    int sat;
    double sal;

    //wprowadzanie danych
    cout<<"Podaj imiê: ";
    cin>>n;
    cout<<"Podaj nazwisko: ";
    cin>>sr;
    cout<<"Podaj p³eæ (M/K): ";
    do
    {
        cin.clear();
        cin.sync();
        cin>>sx;
        if(sx!='M' && sx!='K')
            cout<<"Niew³aœciwy znak. Spróbuj jeszcze raz: ";
    } while((sx!='M' && sx!='K'));
//    cin>>sx;
//    //zabezpieczenie przed niew³aœciwymi znakami
//    while(sx!=75 || sx!=77)
//    {
//        cout<<"Poda³eœ niew³aœciwy znak!\nJeszcze raz: ";
//        cin.clear();
//        cin.sync();
//        cin>>sx;
//        if(sx==75 || sx==77) break;
//    }
    cin.sync();
    cout<<"Podaj nazwê firmy: ";
    getline(cin,cmp);
    cout<<"Podaj zadowolenie w % (0-100): ";
    do
    {
        cin>>sat;
        if((sat<1 || sat>100))
            cout<<"Wartoœæ poza zakresem.Spróbuj jeszcze raz: ";
        if(cin.fail())
        {
            cin.clear();
            cin.sync();
        }
    }
    while (sat<1 || sat>100);

    cout<<"Podaj wynagrodzenie w $: ";
    do
    {
        cin>>sal;
         if(sal<=0)
            cout<<"Niepoprawne dane. Spróbuj jeszcze raz: ";
         if(cin.fail())
        {
            cin.clear();
            cin.sync();
        }

    } while(sal<=0);
    //wywolanie poszczegolnych funkcji
    set_name(n);
    set_surname(sr);
    set_sex(sx);
    set_company(cmp);
    set_satif(sat);
    set_salary(sal);
    //set_result();
    cout<<"\nDodano pracownika!\n\n";
}

