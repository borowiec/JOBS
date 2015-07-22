#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
//Interfejs to klasa abstrakcyjna która ma tylko i wylacznie metody czysto wirtualne i nie ma zadnych pól.
//Aby klasa byla abstrakcyjna to musi miec przynajmniej jedna metode czysto wirtualna=0
//Klasa PERSON jest klasą abstrakcyjną. Nie reprezentuje żadnego konkretnego obiektu, nie da się też go utworzyć.


class Person
{
    public:

        Person();
        virtual ~Person();

        string show_name();
        string show_surname();
        char show_sex();
        string show_company();

        void set_name(string n);
        void set_surname(string s);
        void set_sex(char c);
        void set_company(string c);

        virtual void present()=0;

    protected:
        string m_name;
        string m_surname;
        char m_sex;
        string m_company;
    private:
};

#endif // PERSON_H
