# 1_uzduotis

**1.5 VERSIJA**

Šioje kodo versijoje buvo pritaikyta bazinė klasė "zmogus" iš kurios parašyta išvestinė klasė "mokiniai"

Tai įrodyti buvo padarytas testas bandant sukurti zmogus objekta ir gavosi kompliavimo klaida (testo nuotraukas galite rasti "nuotraukos" aplanke)

Kodo veikimas ir greitis pasikeisti neturėtų, nes buvo tiktai pakeistas prieinamumas prie elementų, o ne pačių elementų veikimas tarpusavyje.

Tai galime palyginti su 1.2 ir 1.5 versijos kodo greičiais:

**Versijos 1.2 greitis:**

|           	| **Duomenu nuskaitymas is failo i konteineri** 	| **Duomenu rusiavimas atitinkaman konteinery** 	| **Duomenu skirstymas i 2 konteinerius** 	|
|-----------	|:---------------------------------------------:	|:---------------------------------------------:	|:---------------------------------------:	|
| 1 000     	|                                       0.00898 	|                                       0.00281 	|                                 0.11669 	|
| 10 000    	|                                       0.08178 	|                                       0.03793 	|                                 0.11672 	|
| 100 000   	|                                       0.80306 	|                                       0.51762 	|                                 0.15623 	|
| 1 000 000 	|                                       8.08041 	|                                       6.68701 	|                                 0.43285 	|


**Versijos 1.5 greitis:**

|           	| **Duomenu nuskaitymas is failo i konteineri** 	| **Duomenu rusiavimas atitinkaman konteinery** 	| **Duomenu skirstymas i 2 konteinerius** 	|
|-----------	|:---------------------------------------------:	|:---------------------------------------------:	|:---------------------------------------:	|
| 1 000     	|                                       0.00898 	|                                       0.00360 	|                                 0.15760 	|
| 10 000    	|                                       0.08368 	|                                       0.04400 	|                                 0.17059 	|
| 100 000   	|                                       0.81490 	|                                       0.59987 	|                                 0.22893 	|
| 1 000 000 	|                                       8.31426 	|                                       7.78633 	|                                 0.63868 	|

Nors pagal rezultatus matosi, kad 1.5 versijos kodas yra truputi lėtesnis, turiu perspėti dėl testavimui naudoto skirtingų kompiuterių pajėgumo, dėl to lygių testu negaliu pateikti.
Visas kodas ir jų penkių metodų taisyklė liko nepakeistas, kas tiko ir kas veikė versijoje 1.2 taip pat veikia ir versijoje 1.5. 
