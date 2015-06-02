#ifndef EMPLOYER_H
#define EMPLOYER_H
#include "Person.h"

class Employer: Person
{
    public:

        string show_name();
        string show_surname();
        char show_sex();
        string show_company();
        double show_salary();

        //========prezentacja==========
        void present();
        //=============================

        void set_name(string n);
        void set_surname(string s);
        void set_sex(char c);
        void set_company(string c);
        void set_salary(double s);

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

        string company;         //nazwa pracodawcy
        double salary;          //wynagrodzenie pracodawcy
};

#endif // EMPLOYER_H
