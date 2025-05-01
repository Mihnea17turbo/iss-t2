# iss-t2
Proiect t2-t3 oop InternationalSpaceStation


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


Cerințe:

	 separarea codului din clase în fișiere header (.h sau.hpp) și surse (.cpp)
	o clasele mici și legate între ele se pot afla în aceeași pereche de fișiere header-sursă
	o FĂRĂ using namespace std
	 moșteniri:
	o minim o clasă de bază și 3 clase derivate din aceeași ierarhie
	o ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
	 funcții virtuale (pure):
	o minim o funcție virtuală va fi specifică temei (i.e. nu simple citiri/afișări sau preluate din
	biblioteci i.e. draw/update/render)
	o funcțiile virtuale vor fi apelate prin pointeri la clasa de bază
	o pointerii la clasa de bază vor fi atribute ale altei clase, nu doar niște pointeri/referințe în
	main
	 constructori virtuali (clone) - sunt necesari, dar nu se consideră funcții specifice temei
	 apelarea constructorului din clasa de bază din constructori din derivate
	 clasă cu atribut de tip pointer la o clasă de bază cu derivate; aici apelați funcțiile virtuale prin
	pointer de bază, eventual prin interfața non-virtuală din bază
	o suprascriere cc/op= pentru copieri/atribuiri corecte, copy and swap
	o dynamic_cast/std::dynamic_pointer_cast pentru downcast cu sens
	o smart pointers (recomandat)
	 excepții
	o ierarhie proprie cu baza std::exception sau derivată din std::exception
	o minim 3 clase pentru erori specifice distincte. Clasele de excepții trebuie să trateze
	categorii de erori distincte (exemplu de erori echivalente: citire fișiere cu diverse extensii)
	o utilizare cu sens: de exemplu, throw în constructor, try/catch în main
	 funcții și atribute statice
	 STL
	 cât mai multe const
	 funcții de nivel înalt, de eliminat cât mai mulți getters/setters/funcții low-level

