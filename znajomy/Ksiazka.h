//
// Created by lip_k on 4/15/2024.
//

#ifndef PROJAKA_KSIAZKA_H
#define PROJAKA_KSIAZKA_H
#include<vector>
#include<iostream>
#include"Osoba.h"
#include"wypozyczenie.h"
#include<algorithm>
using namespace std;

class Ksiazka {

private:
    vector<Osoba> ksiaz;
    vector<Wypozyczenie> wypozyczenia;
    void sortuj();
    void przemebluj();

public:
    void dodaj(Osoba przyj);
    void usun(int id);
    void wypozycz(const Osoba& wlasciciel, const Osoba& wypozyczajacy, const std::string& tytul_ksiazki);
    const vector<Wypozyczenie>& wszystkie_wypozyczenia() const;
    Ksiazka();
    Ksiazka(Osoba);
    const vector<Osoba>& lista() const;
    const Osoba& znajdz_osobe(int id) const;
    bool czy_pusta();
};


#endif //PROJAKA_KSIAZKA_H
