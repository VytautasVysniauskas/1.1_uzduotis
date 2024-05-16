# 1_uzduotis

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
