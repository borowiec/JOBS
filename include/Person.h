#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
//Interfejs to klasa abstrakcyjna która ma tylko i wylacznie metody czysto wirtualne i nie ma zadnych pól.
//Aby klasa byla abstrakcyjna to musi mieæ przynajmniej jedna metode czysto wirtualna=0
//Klasa PERSON jest klasą abstrakcyjną. Nie reprezentuje żadnego konkretnego obiektu, nie da się też go utworzyć.


class Person
{
    public:
        Person();
        virtual ~Person();
        virtual string show_name()=0;
        virtual string show_surname()=0;
        virtual char show_sex()=0;
        virtual void set_name(string n)=0;
        virtual void set_surname(string s)=0;
        virtual void set_sex(char c)=0;
    protected:
        string name;
        string surname;
        char sex;
        string company;
    private:
};

#endif // PERSON_H
