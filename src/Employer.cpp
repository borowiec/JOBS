#include "Employer.h"
#include <iostream>
#include <iomanip>      //do formatowania
using namespace std;


///////////////////KONSTRUKTORY////////////////////////
Employer::Employer()
{
    m_name="Mateusz";
    m_surname="Borowiec";
    m_sex='M';
    m_company="NONE";
    m_salary=0.00;
}

Employer::Employer(string name,string surname,string company,char sex,double salary)
{
    m_name=name;
    m_surname=surname;
    m_sex=sex;
    m_company=company;
    m_salary=salary;
}
//////////////////////DEKONSTRUKTOR////////////////////////////////
Employer::~Employer()
{
   ;
}

//////////////////FUNKCJE POKAZOWE/////////////////////////

double Employer::show_salary()
{
    cout.width(13);
    std::cout<<left<<"Salary: "<<m_salary<<"$"<<std::endl;
    return m_salary;
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


void Employer::set_salary(double salary)
{
    m_salary=salary;
}

void Employer::set_employee()
{
    //zmienne przechowujace
    string name,surname,company;
    char sex;
    double salary;

    //wprowadzanie danych
    cout<<"Podaj imie: ";
    cin>>name;
    cout<<"Podaj nazwisko: ";
    cin>>surname;
    cout<<"Podaj plec (M/K): ";
    do
    {
        cin.clear();
        cin.sync();
        cin>>sex;
        if(sex!='M' && sex!='K')
            cout<<"Niewlasciwy znak. Spróbuj jeszcze raz: ";
    } while((sex!='M' && sex!='K'));

    cin.sync();
    cout<<"Podaj nazwe firmy: ";
    getline(cin,company);

    cout<<"Podaj wynagrodzenie w $: ";
    do
    {
        cin>>salary;
         if(salary<=0)
            cout<<"Niepoprawne dane. Spróbuj jeszcze raz: ";
         if(cin.fail())
        {
            cin.clear();
            cin.sync();
        }

    } while(salary<=0);
    //wywolanie poszczegolnych funkcji
    set_name(name);
    set_surname(surname);
    set_sex(sex);
    set_company(company);
    set_salary(salary);
    //set_result();
    cout<<"\nDodano pracodawce!\n\n";
}
