#ifndef PROJAKA_OSOBA_H
#define PROJAKA_OSOBA_H
#include "iostream"
using namespace std;

class Osoba {

private:
    int ID;
    string imie;
    string nazwisko;
    string numer;
public:
    void setImie(string);
    string getImie() const;
    void setNazw(string);
    string getNazw() const;
    void setNum(string);
    string getNum() const;
    void setID(int id1);
    int getID();
    Osoba(string, string, string);
    string to_string();

};
#endif //PROJAKA_OSOBA_H
