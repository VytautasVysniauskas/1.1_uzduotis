# 1_uzduotis

**Versija 1.2**
Penkių metodų taisyklė yra pritaikyta visam kodui, tačiau jos asmeniškai testuojamos ir demonstruojamos nuotraukų faile.

Tokie yra nauji greičiai naudojant penkių metodų taisyklę duomenis rašant į failus:

|           	| **Duomenu nuskaitymas is failo i konteineri** 	| **Duomenu rusiavimas atitinkaman konteinery** 	| **Duomenu skirstymas i 2 konteinerius** 	|
|-----------	|:---------------------------------------------:	|:---------------------------------------------:	|:---------------------------------------:	|
| 1 000     	|                                       0.00898 	|                                       0.00281 	|                                 0.11669 	|
| 10 000    	|                                       0.08178 	|                                       0.03793 	|                                 0.11672 	|
| 100 000   	|                                       0.80306 	|                                       0.51762 	|                                 0.15623 	|
| 1 000 000 	|                                       8.08041 	|                                       6.68701 	|                                 0.43285 	|

Buvo ištestuojami metodai su rankiniu rašymu ir duomenų skaitymo iš failo, taip pat buvo pridėtas atskiras rašymo ranka būdas.

**ĮVESTIS**

Naujas rašymo ranka būdas - leidžia iš karto įvesti mokinio rezultatus (vardą, pavardę, vidurkį ir medianą).
Šis metodas pilnai naudoja nauja įvesties metodą.

Senas rašymo ranka būdas - atskirai įrašo mokinių namų darbų rezultatus ir tik tada gauna vidurkį ir medianą.
Šis metodas nenaudoja penkių metodų taisyklės ir priskiria kiekvieną rezultatą atskirai.

Skaitymas iš failo būdas - irgi atskirai įrašo mokinių namų darbų rezultatus, panašiai kaip senas rašymo būdas ranka tik viskas eina į failą.

**IŠVESTIS**

Išvestis į ekraną - naudoja nauja išvesties metodą. Yra papildomai pridėtas vidurkis arba mediana priklausant nuo varotojo pasirinkimo.

Išvestis į failą - atskiriant duomenis į failą, yra naudojama penkių metodų taisyklė skirta kopijuoti, perkelti ir šalinti elementus prieš juos išvedant į atitinkamus failus.
