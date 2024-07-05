//
// Created by lip_k on 4/12/2024.
//
#include<iostream>
#include "../znajomy/Ksiazka.h"
#include "../narzedzia/utils.h"
#include<regex>

using namespace std;
#ifndef PROJAKA_DOD_H
#define PROJAKA_DOD_H
class intr2 {
private:
     static string wpisz_argument(string brr);
     static string wpisz_path();
     static string wpisz_numer();
public:
    intr2();
    static void zapisz(Ksiazka& k);

    static void odczyt(Ksiazka& k);

    static void dodawanie(Ksiazka& k);

     static void usuwanie(Ksiazka &k);

     static void wyszuk_konk(Ksiazka &k);

     static void wyszuk_wszyst(Ksiazka &k);

     static void pomoc();

     static void wyjdz(int &i);

     void blad(string komunikat);

     static void dodaj_wypozyczenie(Ksiazka &k);

     static void wypisz_wypozyczenia(Ksiazka &k);
};

#endif //PROJAKA_DOD_H
