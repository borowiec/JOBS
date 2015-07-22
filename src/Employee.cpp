#include "Employee.h"
#include <iostream>
#include <iomanip>      //do formatowania
using namespace std;



///////////////////KONSTRUKTORY////////////////////////
Employee::Employee()
{
    m_name="Gall";
    m_surname="Anonim";
    m_sex='?';
    m_company="NONE";
    m_salary=0.00;
    m_satisfaction=0;
    result[0]={0};
}

Employee::Employee(string name,string surname,string company,char sex,int satisfaction,double salary,int results[])
{
    m_name=name;
    m_surname=surname;
    m_sex=sex;
    m_company=company;
    m_salary=salary;
    m_satisfaction=satisfaction;
    for(int i=0;i<12;i++)
    result[i]=results[i];
}
//////////////////////DEKONSTRUKTOR////////////////////////////////
Employee::~Employee()
{
    ;
}

//////////////////FUNKCJE POKAZOWE/////////////////////////


int Employee::show_satif()
{
    cout.width(13);
    std::cout<<"Satisfacted: "<<m_satisfaction<<"%"<<std::endl;
    return m_satisfaction;
}

double Employee::show_salary()
{
    cout.width(13);
    std::cout<<left<<"Salary: "<<m_salary<<"$"<<std::endl;
    return m_salary;
}

void Employee::show_result()
{
    std::cout<<"Result: ";
    cout<<"     ";
    for(int i=0;i<12;i++)
        std::cout<<result[i]<<" | ";
    std::cout<<"\n";
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
    cout<<"=========================================================================\n";
}
//============================================================
////////////////////////////FUNKCJE USTAWIAJACE////////////////////////////


void Employee::set_satif(int satisfaction)
{
    m_satisfaction=satisfaction;
}

void Employee::set_salary(double salary)
{
    m_salary=salary;
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
    string name,surname,company;
    char sex;
    int satisfaction;
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
    cout<<"Podaj zadowolenie w % (0-100): ";
    do
    {
        cin>>satisfaction;
        if((satisfaction<1 || satisfaction>100))
            cout<<"Wartosc poza zakresem.Spróbuj jeszcze raz: ";
        if(cin.fail())
        {
            cin.clear();
            cin.sync();
        }
    }
    while (satisfaction<1 || satisfaction>100);

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
    set_satif(satisfaction);
    set_salary(salary);
    //set_result();
    cout<<"\nDodano pracownika!\n\n";
}

