//
// Created by lip_k on 4/15/2024.
//

#ifndef PROJAKA_UTILS_H
#define PROJAKA_UTILS_H
#include<string>
#include "../znajomy/Ksiazka.h"
#include <json.hpp>

using namespace std;
class Utils {
public:
    static Ksiazka wczytaj(const string& path);

    static void zapisz(const string& path, const Ksiazka& ksiazka);
    string sprawdzanie_znakow();

private:
    static nlohmann::json to_json(const Osoba& przyj);
};

#endif //PROJAKA_UTILS_H
