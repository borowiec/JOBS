#include "Person.h"
#include <iostream>
#include <iomanip>      //do formatowania
using namespace std;

Person::Person()
{
    //ctor
}

Person::~Person()
{
    //dtor
}

string Person::show_name()
{
    cout.width(13);
    cout<<left<<"Name: "<<m_name<<endl;
    return m_name;
}

string Person::show_surname()
{
    cout.width(13);
    cout<<"Surname: "<<m_surname<<std::endl;
    return m_surname;
}

char Person::show_sex()
{
    cout.width(13);
    cout<<"Sex: "<<m_sex<<endl;
    return m_sex;
}

string Person::show_company()
{
    cout.width(13);
    std::cout<<"Company: "<<m_company<<std::endl;
    return m_company;
}

///////////////////////////////////////////////////////

void Person::set_name(string name)
{
    m_name=name;
}

void Person::set_surname(string surname)
{
    m_surname=surname;
}

void Person::set_sex(char sex)
{
    m_sex=sex;
}

void Person::set_company(string company)
{
    m_company=company;
}
