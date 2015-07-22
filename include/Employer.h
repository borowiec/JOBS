#ifndef EMPLOYER_H
#define EMPLOYER_H
#include "Person.h"

class Employer: Person
{
    public:


        double show_salary();
        void set_salary(double salary);

        //========prezentacja==========
        void present();
        //=============================

        //=========ustawienia zbiorcze=========
        void set_employee();
        //=====================================

        //przeciazanie konstruktorów
        Employer();
        Employer(string name,string surname,string company,char sex,double salary);

        //destruktor
        virtual ~Employer();
    protected:
    private:
        double m_salary;          //wynagrodzenie pracodawcy
};

#endif // EMPLOYER_H
