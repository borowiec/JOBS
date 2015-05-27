#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "Person.h"
using namespace std;

class Employee: public Person
{
    public:

        string show_name();
        string show_surname();
        char show_sex();
        string show_company();
        int show_satif();
        double show_salary();
        void show_result();

        //========prezentacja==========
        void present();
        //=============================

        void set_name(string n);
        void set_surname(string s);
        void set_sex(char c);
        void set_company(string c);
        void set_satif(int s);
        void set_salary(double s);
        void set_result();

        //=========ustawienia zbiorcze=========
        void set_employee();
        //=====================================

        //przeciazanie konstruktorów
        Employee();
        Employee(string n,string m,string comp,char c,int s,double sd,int t[]);
        //destruktor
        virtual ~Employee();

    protected:
    private:
        string company;         //firma zatrudniajaca
        double salary;          //wynagrodzenie
        int satisfaction;       //zadowolenie w %
        int result[12]={0};     //miesieczny zysk dla firmy

};

#endif // EMPLOYEE_H
