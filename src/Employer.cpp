#include "Employer.h"
#include <iostream>
#include <iomanip>      //do formatowania
using namespace std;


///////////////////KONSTRUKTORY////////////////////////
Employer::Employer()
{
    name="Mateusz";
    surname="Borowiec";
    sex='M';
    company="NONE";
    salary=0.00;
}

Employer::Employer(string n,string m,string comp,char c,double sd)
{
    name=n;
    surname=m;
    sex=c;
    company=comp;
    salary=sd;
}
//////////////////////DEKONSTRUKTOR////////////////////////////////
Employer::~Employer()
{
   ;
}

//////////////////FUNKCJE POKAZOWE/////////////////////////
string Employer::show_name()
{
    cout.width(13);
    cout<<left<<"Name: "<<name<<endl;
    return name;
}

string Employer::show_surname()
{
    cout.width(13);
    cout<<"Surname: "<<surname<<std::endl;
    return surname;
}

char Employer::show_sex()
{
    cout.width(13);
    cout<<"Sex: "<<sex<<endl;
    return sex;
}

string Employer::show_company()
{
    cout.width(13);
    std::cout<<"Company: "<<company<<std::endl;
    return company;
}

double Employer::show_salary()
{
    cout.width(13);
    std::cout<<left<<"Salary: "<<salary<<"$"<<std::endl;
    return salary;
}

void Employer::present()
{
    cout<<"=========================================================================\n";
    show_name();
    show_surname();
    show_sex();
    show_company();
    show_salary();
    cout<<"=========================================================================\n";
}
//============================================================
////////////////////////////FUNKCJE USTAWIAJACE////////////////////////////
void Employer::set_name(string n)
{
    name=n;
}

void Employer::set_surname(string s)
{
    surname=s;
}

void Employer::set_sex(char c)
{
    sex=c;
}

void Employer::set_company(string c)
{
    company=c;
}

void Employer::set_salary(double s)
{
    salary=s;
}

void Employer::set_employee()
{
    //zmienne przechowujace
    string n,sr,cmp;
    char sx;
    double sal;

    //wprowadzanie danych
    cout<<"Podaj imie: ";
    cin>>n;
    cout<<"Podaj nazwisko: ";
    cin>>sr;
    cout<<"Podaj plec (M/K): ";
    do
    {
        cin.clear();
        cin.sync();
        cin>>sx;
        if(sx!='M' && sx!='K')
            cout<<"Niewlasciwy znak. Spróbuj jeszcze raz: ";
    } while((sx!='M' && sx!='K'));

    cin.sync();
    cout<<"Podaj nazwe firmy: ";
    getline(cin,cmp);

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
    set_salary(sal);
    //set_result();
    cout<<"\nDodano pracodawce!\n\n";
}
