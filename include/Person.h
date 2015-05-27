#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
//Interfejs to klasa abstrakcyjna która ma tylko i wy³¹cznie metody czysto wirtualne i nie ma ¿adnych pól.
//Aby klasa by³a abstrakcyjna to musi mieæ przynajmniej jedn¹ metodê czysto wirtualn¹ - czyli metodê wirtualn¹ która nie ma cia³a

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
