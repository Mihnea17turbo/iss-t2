#include <iostream>
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
    - adaugaNava() - adaugă o rachetă nouă în stația spațială internațională. Utilizatorul va introduce numele rachetei și tipul acesteia (mică, medie sau mare).
    - adaugaEchipaj() - adaugă astronauți la o rachetă existentă. Utilizatorul va introduce id-ul rachetei și detaliile astronautului (nume, prenume, varsta, salariu, mancarePeZi,specializare).
    - afisazaRachete() - afișează toate rachetele existente în stația spațială internațională.
    - afisazaEchipajNava() - afișează echipajul unei rachete existente. Utilizatorul va introduce id-ul rachetei.
    - puneHranaNavei() - adaugă hrană la o rachetă existentă. Utilizatorul va introduce id-ul rachetei.
    - puneCombustibilNavei() - adaugă combustibil la o rachetă existentă. Utilizatorul va introduce id-ul rachetei.
    - reparareRacheta() - repară o rachetă existentă daca exista un inginer pe nava. Utilizatorul va introduce id-ul rachetei.
    - vindecaPeCelMaiRanit() - vindecă astronautul cel mai rănit dintr-o rachetă existentă daca exista un medic pe nava. Utilizatorul va introduce id-ul rachetei.
    - trecereZi() - simulează trecerea unei zile pentru toate rachetele existente. Aceasta va consuma combustibilul și hrana, va verifica starea de sănătate a astronauților și va gestiona evenimentele (ex: asteroizi).
    - iesire() - iese din program.
*/


int main() {
    StatiaSpatialaInternationala ssi;
    try{
        while (true) {
            std::cout << "1. Adauga racheta\n2. Adauga astronaut\n3. Afiseaza rachete\n4. Afiseaza echipaj\n5. Adauga hrana\n6. Adauga combustibil\n7. Reparare racheta\n8. Vindeca astronaut\n9. Trecere zi\n10. Iesi din program\n";
            int optiune;
            std::cin >> optiune;
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
                case 10: return 0; // iesire din program
                default: throw std::invalid_argument("Optiune invalida!");
            }
        }
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