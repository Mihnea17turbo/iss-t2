#pragma once
#include <iostream>
#include <string>

class Racheta; // forward declaration

class Astronaut {
private:
    static int numarAstronauti;
    const std::string nume;
    const std::string prenume;
    int varsta;
    double salariu;
    int zileInSpatiu = 0;
    const int mancarePeZi;
    int sanatate = 100;
    int id = numarAstronauti;

public:
    Astronaut(std::string nume, std::string prenume, int varsta, double salariu, int mancarePeZi);
    virtual ~Astronaut() = default;
    Astronaut(const Astronaut&) = default;
    Astronaut& operator=(const Astronaut&) = default;

    virtual void print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Astronaut& a);

    void crestere_salariu();
    virtual void vindeca(Astronaut& a);
    int& getSanatate();
    const std::string getNume() const;
    void inrautatireStareSanatateDupaOZi();
    const int getMancarePeZi() const { return mancarePeZi; }
    const int getId() const { return id; }
};

class Medic : public Astronaut {
private:
    const std::string specializare;
    int experienta;

public:
    Medic(std::string nume, std::string prenume, int varsta, int salariu, int mancarePeZi, std::string specializare, int experienta);
    Medic(const Medic&) = default;
    Medic& operator=(const Medic&) = default;

    void print(std::ostream& os) const override;
    void vindeca(Astronaut& a) override;
};

class Inginer : public Astronaut {
private:
    const std::string specializare;
    int experienta;

public:
    Inginer(std::string nume, std::string prenume, int varsta, int salariu, int mancarePeZi, std::string specializare, int experienta);
    Inginer(const Inginer&) = default;
    Inginer& operator=(const Inginer&) = default;

    void print(std::ostream& os) const override;
    void reparare();
    void vindeca(Astronaut& a) override;
    void reparare(Racheta& r);
};
