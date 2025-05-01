#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <cstdlib>
#include <random>

#include "astronaut.h"

const int COMBUSTIBIL_RACHETA_MARE = 100;
const int COMBUSTIBIL_RACHETA_MEDIE = 70;
const int COMBUSTIBIL_RACHETA_MICA = 40;

enum ViataRacheta {
    DISTRUSA,
    VIATA_CRITICAL_DE_MICA,
    VIATA_MICA,
    VIATA_BUNA,
    ARMURA,
    ARMURA_BUNA
};

class StatiaSpatialaInternationala; 
class Astronaut;

class Racheta {
private:
    static int numarRachete;
    const int id = numarRachete;
    std::string nume;
    const int COMBUSTIBIL_MAX;
    int combustibil;
    ViataRacheta viata;
    std::vector<Astronaut*> echipaj;
    int hrana = 20;

public:
    Racheta(std::string nume, int combustibil, ViataRacheta viata);
    virtual ~Racheta();

    void adaugaAstronaut(Astronaut* a);
    virtual std::unique_ptr<Racheta> clone() const = 0;

    friend void Inginer::reparare(Racheta& r);
    friend std::ostream& operator<<(std::ostream& os, const Racheta& r);
    void afisazaEchipaj() const;
    void manancaHrana();
    void consumCombustibil();
    void adaugaHrana() {hrana = 20; std::cout << "Nava s-a umplut de provizii!\n";};
    void adaugaCombustibil(){combustibil = COMBUSTIBIL_MAX; std::cout << "Nava s-a umplut cu combustibil!\n";};
    void sfarsitZiPentruNava();
    void asteroizi();
    const ViataRacheta getViata() const { return viata; }
    const int getId() const { return id; }
    const Astronaut* acceseazaAstronaut(int id) const;
    friend class StatiaSpatialaInternationala;
};

class RachetaMica : public Racheta {
public:
    RachetaMica(std::string nume);
    RachetaMica(const RachetaMica&) = default;
    RachetaMica& operator=(const RachetaMica&) = default;

    std::unique_ptr<Racheta> clone() const override;
};

class RachetaMedie : public Racheta {
public:
    RachetaMedie(std::string nume);
    RachetaMedie(const RachetaMedie&) = default;
    RachetaMedie& operator=(const RachetaMedie&) = default;

    std::unique_ptr<Racheta> clone() const override;
};

class RachetaMare : public Racheta {
public:
    RachetaMare(std::string nume);
    RachetaMare(const RachetaMare&) = default;
    RachetaMare& operator=(const RachetaMare&) = default;

    std::unique_ptr<Racheta> clone() const override;
};
