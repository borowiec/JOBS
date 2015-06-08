#ifndef EMPLOYER_H
#define EMPLOYER_H
#include "Person.h"

class Employer: Person
{
    public:


        double show_salary();
        void set_salary(double s);

        //========prezentacja==========
        void present();
        //=============================

        //=========ustawienia zbiorcze=========
        void set_employee();
        //=====================================

        //przeciazanie konstruktorów
        Employer();
        Employer(string n,string m,string comp,char c,double sd);

        //destruktor
        virtual ~Employer();
    protected:
    private:
        double salary;          //wynagrodzenie pracodawcy
};

#endif // EMPLOYER_H
