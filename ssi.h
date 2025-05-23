#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "racheta.h"

class StatiaSpatialaInternationala {
private:
    std::vector<std::unique_ptr<Racheta>> rachete;
    StatiaSpatialaInternationala() {}
    StatiaSpatialaInternationala(const StatiaSpatialaInternationala&) = delete;
    StatiaSpatialaInternationala& operator=(const StatiaSpatialaInternationala&) = delete;
    static StatiaSpatialaInternationala* instance;

public:
    static StatiaSpatialaInternationala* getInstance() {
    if (instance == nullptr) {
        instance = new StatiaSpatialaInternationala();
    }
    return instance;
}
    void adaugaRacheta(std::unique_ptr<Racheta> racheta);
    void afisazaRachete() const;
    void trecereZi();
    const std::unique_ptr<Racheta>& acceseazaRacheta(int id) const;
    void adaugaNava();
    void adaugaEchipaj();
    void puneCombustibilNavei();
    void puneHranaNavei();
    void afisazaEchipajNava();
    void reparareRacheta();
    void vindecaPeCelMaiRanit();
    void printFinal();
};

