#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
//Interfejs to klasa abstrakcyjna kt�ra ma tylko i wy��cznie metody czysto wirtualne i nie ma �adnych p�l.
//Aby klasa by�a abstrakcyjna to musi mie� przynajmniej jedn� metod� czysto wirtualn� - czyli metod� wirtualn� kt�ra nie ma cia�a

class Person
{
    public:
        Person();
        virtual ~Person();
    protected:
        string name;
        string surname;
        char sex;
        string company;
    private:


};

#endif // PERSON_H
