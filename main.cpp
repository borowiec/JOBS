/*
Program operuje na dynamicznej bazie danych pracownikow.
Aktualnie użytkownik może dodawać nowych pracowników, usuwać, a także korzystać z zapisu i odczytu plików CSV.

- dodano mozliwosc wyboru pracownika do usuniecia
- poprawiono blad zwiazany z dodawaniem kolejnych obiektow podczas wczytywania
- wydzielone funkcje
- pobieranie nazwy uzytkownika dzieki czemu plik zapisuje sie/odczytuje na pulpicie

*/
#include <iostream>     /* cout */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <locale.h>     /* setlocale */
#include <vector>       /* vector */
#include <fstream>      /* files */
#include <string>       /* string */
#include <sstream>      /* sstream */
#include <windows.h>    /* GetUserName */
#include "Employee.h"   //klasa pracownik
//#include "Employer.h" //klasa pracodawca
using namespace std;

void wyswietl_emp_tab(vector < Employee > &tab );
string return_username();
int write_to_file(vector <Employee> &tab, string path="C:\\Users\\"+return_username()+"\\Desktop\\plik.csv");
int read_from_file(vector <Employee> &tab,string path="C:\\Users\\"+return_username()+"\\Desktop\\plik.csv");

int main()
{
    setlocale(LC_ALL,"");   //polskie znaki w konsoli
    //Person p1; blad! nie mozna tworzyc obiektu klasy abstrakcyjnej!
    srand(time( NULL ));    //start czasu

    int choice=1;           //zmienna do wyboru opcji
    int a=0;                //zmienna indeksowa dynamicznej tablicy obiektów
    string linia(60,'*');   //graficzna linia

    //losowa tablica wyników
    int tab[12];
    for(int i=0;i<12;i++)
    tab[i]=rand() % 56 + 44;   // 44-100

    //dynamiczna tablica obiektów typu Employee
    vector <Employee> emp_tab;

    //======================MENU==============================================
    cout<<linia<<endl;
    cout<<"Witaj w bazie danych ludzi pracy! Wybierz czynnosc:\n"
    "1 - wyswietlenie pracownikow\n"
    "2 - dodaj nowego pracownika\n"
    "3 - usun pracownika\n"
    "4 - zapisz do pliku .csv\n"
    "5 - odczyt z pliku\n"
    "0 - koniec\n";
    cout<<linia<<endl;
    //======================MENU==============================================
    while(choice)
    {

        cout<<"Twoj wybor: ";
        cin>>choice;
        while(cin.fail()) // dopóki podawane sa bledne dane
        {
          cout<<"Podaj liczbe z zakresu! "; //komunikat bledu
          cin.clear();                      //kasowanie flagi bledu strumienia
          cin.sync();                       //kasowanie zbednych znaków z bufora
          cin>>choice;
        }

        switch(choice)
        {
            case 0: //opuszczenie switch, wyjscie z programu
                cout<<"Do widzenia!\nAll right reserved by Mateusz Borowiec\n";
                break;
            case 1: //wyswietlenie dynamicznej tablicy
                {
                    wyswietl_emp_tab(emp_tab);
                    break;
                }

            case 2: //dodanie nowego obiektu do tablicy
                {
                    cout<<"Dodawanie nowego pracownika:\n";
                    emp_tab.push_back(Employee());
                    a++;
                    emp_tab[a-1].set_employee();
                    break;
                }

            case 3: //usuniecie elementu tablicy
                {
                    int who=emp_tab.size();
                    if(emp_tab.size())      //czy mozna usunac?
                    {
                        do
                        {
                        if(cin.fail())
                        {
                            cin.clear();    //kasowanie flagi bledu strumienia
                            cin.sync();     //kasowanie zbednych znaków z bufora
                            cout<<"Zle dane!\n";
                        }
                        cout<<"Podaj numer pracownika, ktorego chcesz usunac (1-"<<emp_tab.size()<<"): ";
                        cin>>who;
                        } while(who<=0 || who>(emp_tab.size()));
                        who--;
                        //if((emp_tab.begin()+who)>(emp_tab.begin()+a))
                            emp_tab.erase(emp_tab.begin()+who);
                    }
                    else cout<<"Nie mozna usunac! Pusta baza!\n";

                    //if(emp_tab.size()) emp_tab.erase(emp_tab.begin()+a);
                    break;
                }

            case 4: //zapis do pliku CSV
                {
                    if(emp_tab.size())
                        write_to_file(emp_tab);  //dodac sprawdzanie czy zapis sie powiodl

                    else cout<<"Nie ma co zapisać! Pusta baza!\n";
                    break;
                }

            case 5: //odczyt z pliku CSV
                {
                    if(read_from_file(emp_tab))
                        cout<<"plik udalo sie otworzyc\n";
                    else cout<<"blad otwarcia pliku!\n";
                    break;
                }

            default:
                {
                    cout<<"Podaj wlasciwa wartosc!\n";
                    cin.clear();
                    cin.sync();
                    break;
                }
        }
    }


    return 0;
}

void wyswietl_emp_tab(vector <Employee> &tab )
{
    if (!tab.size()) cout<<"Pusto!:(\n";
    else
        {
        for(int i=0;i<tab.size();i++)
           tab[i].present();
        }
}

string return_username()
{
    char username[20];
    DWORD username_len = 21;
    GetUserName(username, &username_len);
    string str(username);
    return str;
}

int write_to_file(vector <Employee> &tab, string write_path)
{
    ofstream NewFile;
    //string write_path;

    //==== PODAWANIE LOKALIZACJI:
    //cout<<"Podaj lokalizacje (np.C:\\users\\plik.csv): ";
    //cin>>sciezka_zapisu;
    //===========================
    //==== LOKALIZACJA NA PULPICIE:
    //write_path="C:\\Users\\"+return_username()+"\\Desktop\\plik.csv";
    //===========================

    NewFile.open(write_path);
    NewFile<<"Imie;Nazwisko;Plec;Firma;Zadowolenie;Wynagrodzenie"<<endl;
    for(int i=0;i<tab.size();i++)
    {
        NewFile<<tab[i].show_name()<<";";
        NewFile<<tab[i].show_surname()<<";";
        NewFile<<tab[i].show_sex()<<";";
        NewFile<<tab[i].show_company()<<";";
        NewFile<<tab[i].show_satif()<<";";
        NewFile<<tab[i].show_salary()<<";";
        NewFile<<"\n";
    }
    cout<<"\nZapisano "<<write_path<<"!\n\n";
    NewFile.close();
}

int read_from_file(vector <Employee> &tab,string read_path)
{
    ifstream file;
    //string read_path;

    //==== PODAWANIE LOKALIZACJI:
    //cout<<"Podaj lokalizacje (np.C:\\users\\plik.csv): ";
    //cin>>read_path;
    //===========================
    //==== LOKALIZACJA NA PULPICIE:
    //read_path="C:\\Users\\"+return_username()+"\\Desktop\\plik.csv";
    //===========================
    file.open(read_path);

    if(file.good())
    {
        //cout<<"plik udalo sie otworzyc\n";
        string wiersz;  //przechowuje wiersz
        int lwiersz=0;  //liczba wierszy
        string item;

        //usuniecie poprzednich elementow
        tab.clear();

        //analiza wierszy
        while(getline(file, wiersz)) //dopoki wiersz niepusty
        {
            lwiersz++;
            if(lwiersz==1) continue; //pomijamy 1 wiersz (legende)

            stringstream ss(wiersz);
            Employee *empl = new Employee(); //utworzenie dynamicznego obiektu

            //uzupelnianie danych nowego obiektu:
            //imie
            getline(ss, item, ';');
            empl->set_name(item);
            //nazwisko
            getline(ss, item, ';');
            empl->set_surname(item);
            //plec
            getline(ss, item, ';');
            empl->set_sex(item[0]);
            //firma
            getline(ss, item, ';');
            empl->set_company(item);
            //zadowolenie
            getline(ss, item, ';');
            empl->set_satif(atoi(item.c_str()));
            //wynagrodzenie
            getline(ss, item, '\n');
            empl->set_salary(atof(item.c_str()));

            //dodanie obiektu do tablicy
            tab.push_back(*empl);
            cout<<"Utworzono "<<tab.size()<<" obiektow\n";

        }
    file.close();
    return 1;

    }
    else
    {
        //cout<<"otwarcie pliku sie nie powiodlo\n";
        file.close();
        return 0;
    }
}
