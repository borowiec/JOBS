#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "Person.h"
using namespace std;

class Employee: public Person
{
    public:

        int show_satif();
        double show_salary();
        void show_result();

        //========prezentacja==========
        void present();
        //=============================

        void set_satif(int satifaction);
        void set_salary(double salary);
        void set_result();

        //=========ustawienia zbiorcze=========
        void set_employee();
        //=====================================

        //przeciazanie konstruktorów
        Employee();
        Employee(string name,string surname,string company,char sex,int satisfaction,double salary,int results[]);
        //destruktor
        virtual ~Employee();

    protected:
    private:
        string m_company;           //firma zatrudniajaca
        double m_salary;            //wynagrodzenie
        int m_satisfaction;         //zadowolenie w %
        int result[12]={0};         //miesieczny zysk dla firmy

};

#endif // EMPLOYEE_H
