//
// Created by lip_k on 4/15/2024.
//

#ifndef PROJAKA_KSIAZKA_H
#define PROJAKA_KSIAZKA_H
#include<vector>
#include<iostream>
#include"Osoba.h"
#include<algorithm>
using namespace std;

class Ksiazka {

private:
    vector<Osoba> ksiaz;
    void sortuj();
    void przemebluj();

public:
    void dodaj(Osoba przyj);
    void usun(int id);
    Ksiazka();
    Ksiazka(Osoba);
    const vector<Osoba>&lista() const;
    bool czy_pusta();
};


#endif //PROJAKA_KSIAZKA_H
