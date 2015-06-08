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
    cout<<left<<"Name: "<<name<<endl;
    return name;
}

string Person::show_surname()
{
    cout.width(13);
    cout<<"Surname: "<<surname<<std::endl;
    return surname;
}

char Person::show_sex()
{
    cout.width(13);
    cout<<"Sex: "<<sex<<endl;
    return sex;
}

string Person::show_company()
{
    cout.width(13);
    std::cout<<"Company: "<<company<<std::endl;
    return company;
}

///////////////////////////////////////////////////////

void Person::set_name(string n)
{
    name=n;
}

void Person::set_surname(string s)
{
    surname=s;
}

void Person::set_sex(char c)
{
    sex=c;
}

void Person::set_company(string c)
{
    company=c;
}
