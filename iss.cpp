#include "astronaut.h"
#include "racheta.h"
#include "ssi.h"


//random
std::random_device rd;
std::mt19937 gen(rd()); 
std::uniform_int_distribution<> distrib(1, 6); 


//functii
std::string ViataRachetaToString(ViataRacheta v) {
    switch (v) {
        case DISTRUSA: return "DISTRUSA";
        case VIATA_CRITICAL_DE_MICA: return "VIATA CRITICAL DE MICA";
        case VIATA_MICA: return "VIATA MICA";
        case VIATA_BUNA: return "VIATA BUNA";
        case ARMURA: return "ARMURA";
        case ARMURA_BUNA: return "ARMURA BUNA";
        default: return "Valoare incorecta";
    }
}


// Astronaut

int Astronaut::numarAstronauti = 0; // initializare variabila statica

Astronaut::Astronaut(std::string nume, std::string prenume, int varsta, double salariu, int mancarePeZi) 
    : nume(nume), prenume(prenume), varsta(varsta), salariu(salariu), mancarePeZi(mancarePeZi) { ++numarAstronauti;}

void Astronaut::print(std::ostream& os) const {
    os << "id:" << id << " | " << nume << " " << prenume << ", varsta: " << varsta << ", salariu: " << salariu << ", mananca pe zi: " << mancarePeZi << ", viata: " << sanatate;
}

std::ostream& operator<<(std::ostream& os, const Astronaut& a) {
    a.print(os);
    return os;
}

void Astronaut::crestere_salariu() {
    if (zileInSpatiu < 10) {
        salariu *= 1.1;
    } else if (zileInSpatiu < 20) {
        salariu *= 1.2;
    } else {
        salariu *= 1.3;
    }
}

void Astronaut::vindeca(Astronaut& a) {
    std::cout << "Doar un medic poate vindeca!\n";
}

// se da cu zarul, daca pica 5 astronautul pierde 10 viata, daca pica 6 pierde 20 de viata
void Astronaut::inrautatireStareSanatateDupaOZi() {
    int rnd = distrib(gen);
    if (rnd == 5){
        std::cout<< "Astronautul " << getNume() << " a pierdut 10 viata!!\n";
        sanatate -= 10;
    }else if(rnd == 6){
        sanatate -= 20;
        std::cout<< "Astronautul " << getNume() << " a pierdut 20 viata!!\n";
    }

}

int& Astronaut::getSanatate() {
    return sanatate;
}

const std::string Astronaut::getNume() const {
    return nume + " " + prenume;
}

// Medic
Medic::Medic(std::string nume, std::string prenume, int varsta, int salariu, int mancarePeZi, std::string specializare, int experienta)
    : Astronaut(nume, prenume, varsta, salariu, mancarePeZi), specializare(specializare), experienta(experienta) {}

void Medic::print(std::ostream& os) const {
    Astronaut::print(os);
    os << ", specializare: " << specializare << ", experienta: " << experienta << " ani";
}

void Medic::vindeca(Astronaut& a) {
    if (a.getSanatate() < 50) {
        a.getSanatate() += 20;
        std::cout << "Medicul: " << getNume() << " a vindecat astronautul: " << a.getNume() << " aflat in stare critica!\n";
    } else if (a.getSanatate() < 90) {
        a.getSanatate() += 10;
        std::cout << "Medicul: " << getNume() << " a vindecat astronautul: " << a.getNume() << " aflat intr-o stare de sanatate buna!\n";
    } else {
        std::cout << "Astronautul este deja sanatos!\n";
    }
}

// Inginer
Inginer::Inginer(std::string nume, std::string prenume, int varsta, int salariu, int mancarePeZi, std::string specializare, int experienta)
    : Astronaut(nume, prenume, varsta, salariu, mancarePeZi), specializare(specializare), experienta(experienta) {}

void Inginer::print(std::ostream& os) const {
    Astronaut::print(os);
    os << ", specializare: " << specializare << ", experienta: " << experienta << " ani";
}

void Inginer::reparare() {
    std::cout << "Inginerul: " << getNume() << " a reparat nava!\n";
}

void Inginer::vindeca(Astronaut& a) {
    std::cout << "Inginerul nu poate vindeca!\n";
}

void Inginer::reparare(Racheta& r) {
    if (r.viata == DISTRUSA) {
        std::cout << "Racheta este distrusa si nu poate fi reparata!\n";
    } else if (r.viata == VIATA_CRITICAL_DE_MICA) {
        r.viata = VIATA_MICA;
        std::cout << "Inginerul: " << getNume() << " a reparat racheta!\n";
    } else if (r.viata == VIATA_MICA) {
        r.viata = VIATA_BUNA;
        std::cout << "Inginerul: " << getNume() << " a reparat racheta!\n";
    } else {
        std::cout << "Racheta este deja in stare buna!\n";
    }
}

// Racheta

int Racheta::numarRachete = 0; // initializare variabila statica

Racheta::Racheta(std::string nume, int combustibil, ViataRacheta viata)
    : nume(nume), COMBUSTIBIL_MAX(combustibil), viata(viata) {++numarRachete; this->combustibil = COMBUSTIBIL_MAX;}

Racheta::~Racheta() {
    for (auto astronaut : echipaj) {
        delete astronaut;
    }
}

void Racheta::adaugaAstronaut(Astronaut* a) {
    echipaj.push_back(a);
}

std::ostream& operator<<(std::ostream& os, const Racheta& r) {
    os << "id:" << r.id << "| Racheta: " << r.nume << ", combustibil: " << r.combustibil << ", viata: " << ViataRachetaToString(r.viata) << ", hrana: " << r.hrana << "\n";
    return os;
}

void Racheta::afisazaEchipaj() const {
    for (const auto& astronaut : echipaj) {
        std::cout << *astronaut << std::endl;
    }
}

void Racheta::manancaHrana() {
    int s = 0;
    for(auto x: echipaj){
        s+= x->getMancarePeZi();
    }
    hrana -= s;
    if (hrana < s) std::cout<< "Nu o sa mai ajunga hrana pentru o noua zi!\n";
    else std::cout << "Hrana a fost consumata. Hrana ramasa: " << hrana << "\n";

}

void Racheta::consumCombustibil() {
    combustibil -= 10;
    if (combustibil < 0) std::cout << "Racheta a ramas fara combustibil si pluteste in spatiu!\n";
    else std::cout << "Racheta a consumat combustibil. Combustibil ramas: " << combustibil << "\n";
}

void Racheta::sfarsitZiPentruNava() {
    for(int i = 0; i < echipaj.size(); i++){
        if (echipaj[i]->getSanatate() > 0){
        echipaj[i]->inrautatireStareSanatateDupaOZi();
        if (echipaj[i]->getSanatate() <= 0) {
            std::cout << "Astronautul " << echipaj[i]->getNume() << " a murit!\n";            }
        }
    }
    echipaj.erase(std::remove_if(echipaj.begin(), echipaj.end(), [](Astronaut* a) { return a->getSanatate() <= 0; }), echipaj.end());
    manancaHrana();
    consumCombustibil();
    if (hrana < 0 or combustibil < 0 or echipaj.size() == 0){
        std::cout << "Racheta a ramas fara resurse!\n";
        viata = DISTRUSA;
    }else{
        asteroizi();
    }

    if (viata == DISTRUSA){
        std::cout << "Racheta " << nume << " a fost distrusa!\n";
    }

}

// asteroizi - se da cu zarul,daca pica 5 se pierde o viata, daca pica 6 se pierd 2 vieti
void Racheta::asteroizi() {
    int rnd = distrib(gen);
    if (rnd == 5){
        std::cout<< "Racheta " << nume << " a fost lovita de asteroizi si a pierdut o viata! ";
        viata = static_cast<ViataRacheta>(static_cast<int>(viata) - 1);
        std::cout << "Viata ramasa: " << ViataRachetaToString(viata) << "\n";
    }else if(rnd == 6){
        std::cout<< "Racheta " << nume << " a fost lovita de un asteroid urias si a pierdut 2 viata! ";
        viata = static_cast<ViataRacheta>(static_cast<int>(viata) - 2);
        std::cout << "Viata ramasa: " << ViataRachetaToString(viata) << "\n";
    }
}

const Astronaut* Racheta::acceseazaAstronaut(int id) const {
    for (const auto& astronaut : echipaj) {
        if (astronaut->getId() == id) {
            return astronaut;
        }
    }
    throw std::runtime_error("Astronautul cu id-ul dat nu exista!");
}

// RachetaMica
RachetaMica::RachetaMica(std::string nume)
    : Racheta(nume, COMBUSTIBIL_RACHETA_MICA, VIATA_BUNA) {}

std::unique_ptr<Racheta> RachetaMica::clone() const {
    return std::make_unique<RachetaMica>(*this);
}

// RachetaMedie
RachetaMedie::RachetaMedie(std::string nume)
    : Racheta(nume, COMBUSTIBIL_RACHETA_MEDIE, ARMURA) {}

std::unique_ptr<Racheta> RachetaMedie::clone() const {
    return std::make_unique<RachetaMedie>(*this);
}

// RachetaMare
RachetaMare::RachetaMare(std::string nume)
    : Racheta(nume, COMBUSTIBIL_RACHETA_MARE, ARMURA_BUNA) {}

std::unique_ptr<Racheta> RachetaMare::clone() const {
    return std::make_unique<RachetaMare>(*this);
}


// StatiaSpatialaInternationala

void StatiaSpatialaInternationala::trecereZi() {
    for (auto& racheta : rachete) {
        racheta->sfarsitZiPentruNava();
    }
    std::cout << "A trecut o zi!\n";
    rachete.erase(std::remove_if(rachete.begin(), rachete.end(), [](const std::unique_ptr<Racheta>& r) { return r->getViata() == DISTRUSA; }), rachete.end());
    std::cout << "Rachetele ramase:\n";
    for (const auto& racheta : rachete) {
        std::cout << *racheta << std::endl;
    }
}

const std::unique_ptr<Racheta>& StatiaSpatialaInternationala::acceseazaRacheta(int id) const {
    for (const auto& racheta : rachete) {
        if (racheta->getId() == id) {
            return racheta;
        }
    }
    throw std::runtime_error("Racheta cu id-ul dat nu exista!");
}
void StatiaSpatialaInternationala::adaugaNava() {
    std::string nume;
    int tipRacheta;
    std::cout << "Introduceti numele rachetei: ";
    std::cin >> nume;
    std::cout << "Introduceti tipul rachetei (1 - Mica, 2 - Medie, 3 - Mare): ";
    std::cin >> tipRacheta;

    std::unique_ptr<Racheta> racheta;
    switch (tipRacheta) {
        case 1:
            racheta = std::make_unique<RachetaMica>(nume);
            break;
        case 2:
            racheta = std::make_unique<RachetaMedie>(nume);
            break;
        case 3:
            racheta = std::make_unique<RachetaMare>(nume);
            break;
        default:
            throw std::out_of_range("Tip de racheta invalid!");
            return;
    }

    adaugaRacheta(std::move(racheta));
}

void StatiaSpatialaInternationala::adaugaEchipaj() {
    int idRacheta;
    std::cout << "Introduceti id-ul rachetei la care doriti sa adaugati astronauti: ";
    std::cin >> idRacheta;
    if (std::cin.fail()) {
        throw std::runtime_error("Input invalid: trebuie sa introduci un numar intreg.");
    };
    try{
        acceseazaRacheta(idRacheta);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }
    auto& racheta = acceseazaRacheta(idRacheta);
    std::string nume, prenume, specializare;
    int varsta, salariu, mancarePeZi, experienta;

    std::cout << "Introduceti numele astronautului: ";
    std::cin >> nume;
    std::cout << "Introduceti prenumele astronautului: ";
    std::cin >> prenume;
    std::cout << "Introduceti varsta astronautului: ";
    std::cin >> varsta;
    std::cout << "Introduceti salariul astronautului: ";
    std::cin >> salariu;
    std::cout << "Introduceti cat mananca astronautul intr-o zi: ";
    std::cin >> mancarePeZi;
    std::cout << "Introduceti specializarea astronautului (Medic/Inginer - orice altceva va crea un astronaut generic): ";
    std::cin >> specializare;

    if (specializare == "Medic") {
        std::cout << "Introduceti experienta medicului (ani): ";
        std::cin >> experienta;
        racheta->adaugaAstronaut(new Medic(nume, prenume, varsta, salariu, mancarePeZi, specializare, experienta));
    } else if (specializare == "Inginer") {
        std::cout << "Introduceti experienta inginerului (ani): ";
        std::cin >> experienta;
        racheta->adaugaAstronaut(new Inginer(nume, prenume, varsta, salariu, mancarePeZi, specializare, experienta));
    } else {
        racheta->adaugaAstronaut(new Astronaut(nume, prenume, varsta, salariu, mancarePeZi));
    }
}

void StatiaSpatialaInternationala::puneCombustibilNavei() {
    int idRacheta;
    std::cout << "Introduceti id-ul rachetei la care doriti sa adaugati combustibil: ";
    std::cin >> idRacheta;
    if (std::cin.fail()) {
        throw std::runtime_error("Input invalid: trebuie sa introduci un numar intreg.");
    };
    try{
        acceseazaRacheta(idRacheta);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }
    auto& racheta = acceseazaRacheta(idRacheta);
    racheta->adaugaCombustibil();
}
void StatiaSpatialaInternationala::puneHranaNavei() {
    int idRacheta;
    std::cout << "Introduceti id-ul rachetei la care doriti sa adaugati hrana: ";
    std::cin >> idRacheta;
    if (std::cin.fail()) {
        throw std::runtime_error("Input invalid: trebuie sa introduci un numar intreg.");
    };
    try{
        acceseazaRacheta(idRacheta);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }
    auto& racheta = acceseazaRacheta(idRacheta);
    racheta->adaugaHrana();
}

void StatiaSpatialaInternationala::afisazaEchipajNava() {
    int idRacheta;
    std::cout << "Introduceti id-ul rachetei a carei echipaj doriti sa-l afisati: ";
    std::cin >> idRacheta;
    if (std::cin.fail()) {
        throw std::runtime_error("Input invalid: trebuie sa introduci un numar intreg.");
    };
    try{
        acceseazaRacheta(idRacheta);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }
    auto& racheta = acceseazaRacheta(idRacheta);
    racheta->afisazaEchipaj();
}

void StatiaSpatialaInternationala::afisazaRachete() const {
    std::cout << "Rachetele disponibile:\n";
    for (const auto& racheta : rachete) {
        std::cout << *racheta << std::endl;
    }
}

void StatiaSpatialaInternationala::adaugaRacheta(std::unique_ptr<Racheta> racheta) {
    rachete.push_back(std::move(racheta));
}

void StatiaSpatialaInternationala::reparareRacheta() {
    int idRacheta;
    std::cout << "Introduceti id-ul rachetei pe care doriti sa o reparati: ";
    std::cin >> idRacheta;
    if (std::cin.fail()) {
        throw std::runtime_error("Input invalid: trebuie sa introduci un numar intreg.");
    };
    try{
        acceseazaRacheta(idRacheta);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }
    auto& racheta = acceseazaRacheta(idRacheta);
    for (auto& astronaut : racheta->echipaj) {
        if (dynamic_cast<Inginer*>(astronaut)) {
            dynamic_cast<Inginer*>(astronaut)->reparare(*racheta);
            return;
        }
    }
    std::cout << "Nu exista inginer in echipaj!\n";
}

void StatiaSpatialaInternationala::vindecaPeCelMaiRanit() {
    int idRacheta;
    std::cout << "Introduceti id-ul rachetei de pe care se afla cel pe care freti sa-l vindecati: ";
    std::cin >> idRacheta;
    if (std::cin.fail()) {
        throw std::runtime_error("Input invalid: trebuie sa introduci un numar intreg.");
    };
    try{
        acceseazaRacheta(idRacheta);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }
    auto& racheta = acceseazaRacheta(idRacheta);
    Astronaut* celMaiRanit = nullptr;
    for (auto& astronaut : racheta->echipaj) {
        if (!celMaiRanit || astronaut->getSanatate() < celMaiRanit->getSanatate()) {
            celMaiRanit = astronaut;
        }
    }
    if (celMaiRanit) {
        for (auto& astronaut : racheta->echipaj) {
            if (dynamic_cast<Medic*>(astronaut)) {
                dynamic_cast<Medic*>(astronaut)->vindeca(*celMaiRanit);
                return;
            }
        }
        std::cout << "Nu exista medic in echipaj!\n";
    } else {
        std::cout << "Nu exista astronauti in echipaj!\n";
    }
}