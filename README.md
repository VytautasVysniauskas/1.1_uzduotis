# 1.1_versija

Testavimui tarp classiu ir struct buvo daromi su vectoriais. Stai 100 000 ir 1 000 000 duomenu rezultatai:

**100 000:**
Struct vector
|              	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|--------------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1     	|                                                   0,82614 	|                         0,11318 	|                              0,32348 	|
| Testas 2     	|                                                   0,84393 	|                         0,11940 	|                              0,32837 	|
| Testas 3     	|                                                   0,87882 	|                         0,12216 	|                              0,31279 	|
| **Vidurkis** 	|                                                   0,84963 	|                         0,11825 	|                              0,32155 	|

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
| Testas 1     	|                                                   10.62181 	|                         8.24743 	|                              0.55264 	|
| Testas 2     	|                                                   12.69932 	|                         8.67723 	|                              0.55909 	|
| Testas 3     	|                                                   12.25448 	|                         7.30902 	|                              0.56442 	|
| **Vidurkis** 	|                                                   11.85854 	|                         8.07789 	|                              0.55872 	|

Class vector
|              	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|--------------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1     	|                                                   8.13025 	|                         6.12964 	|                              0.40791 	|
| Testas 2     	|                                                   8.14225 	|                         6.12066 	|                              0.41009 	|
| Testas 3     	|                                                   8.06156 	|                         6.13562 	|                              0.41689 	|
| **Vidurkis** 	|                                                   8.11135 	|                         6.12864 	|                              0.41163 	|

Kaip matome struct ir classes vektoriai yra panasuas greicio su 100 000 duomenu taciau classes vectoriai tampa zymiai greitesni su 1 000 000 duomenu.
