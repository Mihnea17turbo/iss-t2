#include <iostream>
#include <fstream>
#include "astronaut.h"
#include "racheta.h"
#include "ssi.h"

/*
Programul simulează interacțiunea cu o stație spațială internațională (StatiaSpatialaInternationala).
Utilizatorul poate adăuga rachete și astronauți,
poate gestiona resursele (hrană și combustibil), poate repara rachete, vindeca astronauți și poate simula trecerea timpului.
Totul se face dintr-un meniu interactiv în linia de comandă până când utilizatorul alege să iasă.

Funcționarea principală – main()
 - Inițializează un obiect ssi de tip StatiaSpatialaInternationala.

 - Afișează un meniu interactiv cu 10 opțiuni.

 - Primește de la utilizator un număr (optiune) și execută funcția corespunzătoare.

 - Meniul continuă să ruleze până când utilizatorul selectează opțiunea 10 (ieșire) sau pana pune un input invalid.

 Functiile apelate:
    - 1)adaugaNava() - adaugă o rachetă nouă în stația spațială internațională. Utilizatorul va introduce numele rachetei și tipul acesteia (mică, medie sau mare folosind 1 pt mica,2 pt medie, 3 pt mare).
    - 2)adaugaEchipaj() - adaugă astronauți la o rachetă existentă. Utilizatorul va introduce id-ul rachetei și detaliile astronautului (nume, prenume, varsta, salariu, mancarePeZi,specializare(Medic/Inginer)).
    - 3)afisazaRachete() - afișează toate rachetele existente în stația spațială internațională.
    - 4)afisazaEchipajNava() - afișează echipajul unei rachete existente. Utilizatorul va introduce id-ul rachetei.
    - 5)puneHranaNavei() - adaugă hrană la o rachetă existentă. Utilizatorul va introduce id-ul rachetei.
    - 6)puneCombustibilNavei() - adaugă combustibil la o rachetă existentă. Utilizatorul va introduce id-ul rachetei.
    - 7)reparareRacheta() - repară o rachetă existentă daca exista un inginer pe nava. Utilizatorul va introduce id-ul rachetei.
    - 8)vindecaPeCelMaiRanit() - vindecă astronautul cel mai rănit dintr-o rachetă existentă daca exista un medic pe nava. Utilizatorul va introduce id-ul rachetei.
    - 9)trecereZi() - simulează trecerea unei zile pentru toate rachetele existente. Aceasta va consuma combustibilul și hrana, va verifica starea de sănătate a astronauților și va gestiona evenimentele (ex: asteroizi).
    - 10)iesire() - iese din program.
*/


int main() {
    StatiaSpatialaInternationala ssi;
    std::ifstream fin("input.txt");
    if (!fin) {
        std::cerr << "Eroare la deschiderea fisierului input.txt" << std::endl;
        return 1;
    }
    std::cin.rdbuf(fin.rdbuf()); // redirectioneaza std::cin catre fisierul din care se citeste
    std::cout<< "\nJurnal de bord:\n";
    std::cout<< "=====================\n\n";
    try{
        while (true) {
            // std::cout << "1. Adauga racheta\n2. Adauga astronaut\n3. Afiseaza rachete\n4. Afiseaza echipaj\n5. Adauga hrana\n6. Adauga combustibil\n7. Reparare racheta\n8. Vindeca astronaut\n9. Trecere zi\n10. Iesi din program\n";
            int optiune;
            if (!(std::cin >> optiune)) break;
            switch (optiune) {
                case 1: ssi.adaugaNava(); break;
                case 2: ssi.adaugaEchipaj(); break;
                case 3: ssi.afisazaRachete(); break;
                case 4: ssi.afisazaEchipajNava(); break;
                case 5: ssi.puneHranaNavei(); break;
                case 6: ssi.puneCombustibilNavei(); break;
                case 7: ssi.reparareRacheta(); break;
                case 8: ssi.vindecaPeCelMaiRanit(); break;
                case 9: ssi.trecereZi(); break;
                case 10: break; // iesire din program
                default: throw std::invalid_argument("Optiune invalida!");
            }
        }
    
    std::cout << "\nRezultat sfarsit de misiune\n";
    std::cout << "=====================\n\n";
    std::cout << "Rachete ramase:\n";
    ssi.printFinal();

    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }catch (...) {
        std::cout << "A aparut o eroare neasteptata!" << std::endl;
    }
}