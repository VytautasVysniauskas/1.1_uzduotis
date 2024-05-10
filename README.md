# 1_uzduotis

Versija 0.1 - Naudoja vektorius pirma karta, yra lyginamas ju ir C masyvu veikimas.

Versija 0.2 - Pradedamas darbas su didesniu mokiniu kiekiu, vyksta paprastas darbas su duomenimis.

Versija 0.3 - Nuo 1 failo persikeliama i 4, atskiriami specifiniai kodu laukai i jam patogias vietas.

Versija 0.4 - Yra testuojamas greitis tarp skirtingu duomenu kiekio ir matuojamas lyginant kaip jis keiciasi.

Versija 1.0 - Kuriami deque ir list tipu kodai, yra naudojamos 3 strategijos koda kompliuojant ir lyginamas ju visu greitis.

Versija 1.1 - Sukuriamos klases ir mokinamasi darbas su jomis, pratesiamas darbas su vektoriu kodu.

Versija 1.2 - Idedama penkiu metodu taisykle bei naujos ivesties/isvesties metodai.

Versija 1.5 - Pakeiciamas klasiu prieinamumas, sukuriamos bazines klases. Padaro koda saugesni ir lengvesni keitimui.

Versija 2.0 - Galutinis kodas ir senenses ju versijos yra dokumentuojamos.

**MakeFile parsisiuntimas**
Pries pradedant naudojima, jums pirmiausia reikes parsisiusti make naudojimui, stai ka jums reikia padaryti:
- Nueiti i https://gnuwin32.sourceforge.net/packages/make.htm ir parsisiusti naujausia versija
- Po parsisiuntimo reikia paleisti programa kuria parsiusiuntem, ji turetu parsiusti kita programma.
- Sekite visas instrunkcijas kurios parodytos, pasirinkite norima programos destinacija.
- Po parsisiuntimo nukopijuokite direktorija i bin.
- Eiti "edit the system environment variables" nustatymus"
- Spausti "environment variables"
- Ant Variable "Path" spausti ir tada spausti edit
- Sukurti new lauka ir iklijuoti nukopijuota direktorija
- Kad patvirtintumete instaliacija, comandos terminale irasykite "make --version" be kabuciu.

Po situ zingsiu make turetu buti instaliuotas jusu kompiuteryje, iskilus problemoms
galite paieskoti specifiniu sprendimu internete arba kitu budu instaliuoti make.

**MakeFile Naudojimas:**
Patikrinkite ar visi failai yra toje pacioje direktorijoj pries pradedant naudojima.
Per "Command Prompt" ar kitu pavadinimo command terminale įeikite į savo direktorija ir ten galite rasyti kelis dalykus:
- make vektoriai.exe (atnaujina vektoriu kodo failus, reikia įvykdyti prieš pirmą naudojima)
- make list.exe (atnaujina listu kodo failus, reikia įvykdyti prieš pirmą naudojima)
- make deque.exe (atnaujina deque kodo failus, reikia įvykdyti prieš pirmą naudojima)
- make runV (Paleidžia programa kuri veikia vektoriais)
- make runL (Paleidžia programa kuri veikia listais)
- make runD (Paleidžia programa kuri veikia deque)
- make delete (Ištrina failus kurie automatiškai sukuriami naudojant programą)

Kaip Naudoti programoj:
Kur praso rasyti raide reikia rasyti TIK viena raide.
Failo pavadinimus rasyti pilnus, kuriant tekstinius nepamirskite prideti .txt prie galo.
Jusu bus klausiami dalykai tokia eile, R reiskia atssakyti raide, S - žodžiu:
- Ar norite generuoti duomenis? (R)
- Irasykite failo pavadinima kuriame bus irasyti generuoti duomenys. (S) (Jeigu pasirinkote generuoti duomenis)
- Ar norite duomenys rasyti ranka ar skaityti is failo? (R)
- Is kurio failo norite skaityti duomenys? (S) (Jeigu pasirinkote skaityti is failo)
- Kuria tvarka norite juos rusiuoti? (R)
- Ar norite atsakyma spauzdinti i faila ar ekrana? (R)
- Ar norite kad rezultatai rodyti vidurki ar mediana? (R)

Rankinis duomenu rasymas yra irgi taip pat paprastai apibudinami. Jum bus pasakyta kada rasyti 0 jeigu norite baigti rasyti duomenis.
Jums reikes rasyti
- Vardas
- Pavarde
- Namu darbu rezultatus (Iki tol kol irasyte 0)
- Egzamino rezultata

**Galutinis versijos kodo greitis yra:**

|           	| **Duomenu nuskaitymas is failo i konteineri** 	| **Duomenu rusiavimas atitinkaman konteinery** 	| **Duomenu skirstymas i 2 konteinerius** 	|
|-----------	|:---------------------------------------------:	|:---------------------------------------------:	|:---------------------------------------:	|
| 1 000     	|                                       0.00892 	|                                       0.00353 	|                                 0.15742 	|
| 10 000    	|                                       0.08458 	|                                       0.04412 	|                                 0.17132 	|
| 100 000   	|                                       0.81230 	|                                       0.59777 	|                                 0.22856 	|
| 1 000 000 	|                                       8.33326 	|                                       7.78423 	|                                 0.64258 	|
