//
// Created by lip_k on 7/4/2024.
//

#ifndef PROJAKA_LISTA_WYPOZYCZEN_H
#define PROJAKA_LISTA_WYPOZYCZEN_H

#include <chrono>

struct Wypozyczenie {
    const Osoba &wlasciciel;
    const Osoba &wypozyczajacy;
    const std::string tytul_ksiazki;
    const std::chrono::system_clock::time_point czas_wypozyczenia;
};


#endif //PROJAKA_LISTA_WYPOZYCZEN_H
