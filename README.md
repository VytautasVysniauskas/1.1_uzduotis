# 1.1_versija

Testavimui tarp classiu ir struct buvo daromi su vectoriais. Stai 100 000 ir 1 000 000 duomenu rezultatai:

**100 000:**
Struct vector
|              	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|--------------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1     	|                                                   0,82614 	|                         0,47234 	|                              0,13318 	|
| Testas 2     	|                                                   0,84393 	|                         0,47024 	|                              0,13940 	|
| Testas 3     	|                                                   0,87882 	|                         0,46945 	|                              0,13216 	|
| **Vidurkis** 	|                                                   0,84963 	|                         0,47095 	|                              0,13825 	|

Class vector
|              	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|--------------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1     	|                                                   0.81186 	|                         0.47077 	|                              0.13666 	|
| Testas 2     	|                                                   0.82009 	|                         0.47360 	|                              0.13367 	|
| Testas 3     	|                                                   0.81385 	|                         0.47177 	|                              0.13165 	|
| **Vidurkis** 	|                                                   0.81527 	|                         0.47205 	|                              0.13399 	|

**1 000 000:**
Struct vector
|              	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|--------------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1     	|                                                    8.25292 	|                         6.00594 	|                              0.39794 	|
| Testas 2     	|                                                    7.87297 	|                         6.04685 	|                              0.41190 	|
| Testas 3     	|                                                    7.81211 	|                         6.02189 	|                              0.41194 	|
| **Vidurkis** 	|                                                    7.95468 	|                         6.02432 	|                              0.40235 	|

Class vector
|              	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|--------------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1     	|                                                   8.13025 	|                         6.12964 	|                              0.40791 	|
| Testas 2     	|                                                   8.14225 	|                         6.12066 	|                              0.41009 	|
| Testas 3     	|                                                   8.06156 	|                         6.13562 	|                              0.41689 	|
| **Vidurkis** 	|                                                   8.11135 	|                         6.12864 	|                              0.41163 	|

Kaip matome struct ir classes vektoriai yra panasaus greicio su 100 000 ir 1 000 000. Kodas veikia panasiai tarp vienas kito.

Toliau buvo daromi testai su O1, O2 ir O3 flagais compiliojant koda. Testai buvo daromi vel su vectoriais tarp struct ir class naudojant 100 000 duomenu.

**O1**
Struct vector dydis - 179 283 bytes
|          	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|----------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1 	|                                                   0.70814 	|                         0.10076 	|                              0.02496 	|
| Testas 2 	|                                                   0.70714 	|                         0.10054 	|                              0.02494 	|
| Testas 3 	|                                                   0.70913 	|                         0.10176 	|                              0.02394 	|
Class vector dydis - 162 152 bytes
|          	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|----------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1 	|                                                   0.69913 	|                         0.16757 	|                              0.02893 	|
| Testas 2 	|                                                   0.72506 	|                         0.16456 	|                              0.02892 	|
| Testas 3 	|                                                   0.69714 	|                         0.16556 	|                              0.02990 	|

**O2**
Struct vector dydis - 186 203 bytes
|          	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|----------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1 	|                                                   0.71113 	|                         0.10076 	|                              0.02576 	|
| Testas 2 	|                                                   0.70811 	|                         0.09974 	|                              0.02494 	|
| Testas 3 	|                                                   0.76598 	|                         0.10771 	|                              0.02697 	|
Class vector dydis - 160 732 bytes
|          	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|----------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1 	|                                                   0.69916 	|                         0.16559 	|                              0.03491 	|
| Testas 2 	|                                                   0.70016 	|                         0.16260 	|                              0.02992 	|
| Testas 3 	|                                                   0.69913 	|                         0.16260 	|                              0.03292 	|

**O3**
Struct vector dydis - 184 487 bytes
|          	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|----------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1 	|                                                   0.70611 	|                         0.10173 	|                              0.02394 	|
| Testas 2 	|                                                   0.70811 	|                         0.10472 	|                              0.02793 	|
| Testas 3 	|                                                   0.74105 	|                         0.10076 	|                              0.02494 	|
Class vector dydis - 172 782 bytes
|          	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|----------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1 	|                                                   0.76695 	|                         0.16356 	|                              0.02793 	|
| Testas 2 	|                                                   0.69817 	|                         0.16257 	|                              0.02896 	|
| Testas 3 	|                                                   0.70212 	|                         0.16060 	|                              0.02895 	|

Galime pastebeti kad visu 3 testu laikai truputi greiteja su kiekvienu skirtingu flagu, taciau struct zymiau trumpiau uztrunka su rusiavumo funkcija.
Taip pat, class vector exe failu dydis yra aiskiai mazesnis uz struct vector exe failu dydzius.
