# 1_uzduotis

**INSTRUKCIJA**

**Kaip parsisiusti programa**

Parsisiusnte zip faila is release puslapio, atidarykite "SetupVektoriai.exe". Nuo ten instrukcijos bus surasytos.

**Kaip Naudoti programoj:**

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

Vektoriu std::vector ir savo sukurtu MyVector push_back vidutiniai laikai buvo tikrinami, stai ju rezultatai:
| **Elementu kiekis** 	| **std::vector** 	| **MyVector** 	|
|---------------------	|:---------------:	|:------------:	|
| 100 000             	|         0.00112 	|      0.00101 	|
| 1 000 000           	|         0.01030 	|      0.01023 	|
| 10 000 000          	|         0.10099 	|      0.09233 	|
| 100 000 000         	|         1.13986 	|      0.98796 	|

Toliau yra lyginami viso kodo std::vector ir MyVector naudojimo greitis:

**Versija 1.5 (std::vector)**

|           	| **Duomenu nuskaitymas is failo i konteineri** 	| **Duomenu rusiavimas atitinkaman konteinery** 	| **Duomenu skirstymas i 2 konteinerius** 	|
|-----------	|:---------------------------------------------:	|:---------------------------------------------:	|:---------------------------------------:	|
| 100 000   	|                                       0.81490 	|                                       0.59987 	|                                 0.22893 	|
| 1 000 000 	|                                       8.31426 	|                                       7.78633 	|                                 0.63868 	|


**Versija 3.0 (MyVector)**
|           	| **Duomenu nuskaitymas is failo i konteineri** 	| **Duomenu rusiavimas atitinkaman konteinery** 	| **Duomenu skirstymas i 2 konteinerius** 	|
|-----------	|:---------------------------------------------:	|:---------------------------------------------:	|:---------------------------------------:	|
| 100 000   	|                                       0.83456 	|                                       0.58032 	|                                 0.64616 	|
| 1 000 000 	|                                       8.31576 	|                                       7.58593 	|                                 0.84472 	|
