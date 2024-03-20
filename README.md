# 1_uzduotis

**Sistemos parametrai:** Intel(R) Core(TM) i5-10300H CPU @ 2.50GHz   2.50 GHz. RAM 16.0GB

**Vectoriai**

1 000:
|              	| **Duomenu is failo nuskaitymas** 	| **Duomenu rusiavimas i atskirus konteinerius** 	| **Duomenu isvedimas i 2 askirus failus** 	| **Visos programos laikas** 	|
|--------------	|:--------------------------------:	|:----------------------------------------------:	|:----------------------------------------:	|:--------------------------:	|
| Testas 1     	|                          0,03151 	|                                        0,00199 	|                                  0,00299 	|                    0,30354 	|
| Testas 2     	|                          0,02779 	|                                        0,00100 	|                                  0,00399 	|                    0,29783 	|
| Testas 3     	|                          0,02841 	|                                        0,00199 	|                                  0,00377 	|                    0,28731 	|
| **Vidurkis** 	|                         0,029237 	|                                        0,00166 	|                                  0,00358 	|                    0,29623 	|

10 000:
|              	| **Duomenu is failo nuskaitymas** 	| **Duomenu rusiavimas i atskirus konteinerius** 	| **Duomenu isvedimas i 2 askirus failus** 	| **Visos programos laikas** 	|
|--------------	|:--------------------------------:	|:----------------------------------------------:	|:----------------------------------------:	|:--------------------------:	|
| Testas 1     	|                          0,14121 	|                                        0,01975 	|                                  0,03336 	|                    0,65337 	|
| Testas 2     	|                          0,13032 	|                                        0,01487 	|                                  0,03158 	|                    0,64517 	|
| Testas 3     	|                          0,17080 	|                                        0,01521 	|                                  0,03176 	|                    0,69745 	|
| **Vidurkis** 	|                          0,14744 	|                                        0,01661 	|                                  0,03223 	|                    0,66533 	|

100 000:
|              	| **Duomenu is failo nuskaitymas** 	| **Duomenu rusiavimas i atskirus konteinerius** 	| **Duomenu isvedimas i 2 askirus failus** 	| **Visos programos laikas** 	|
|--------------	|:--------------------------------:	|:----------------------------------------------:	|:----------------------------------------:	|:--------------------------:	|
| Testas 1     	|                          0,32614 	|                                        0,11318 	|                                  0,32348 	|                    3,95262 	|
| Testas 2     	|                          0,84393 	|                                        0,11940 	|                                  0,32837 	|                    5,00145 	|
| Testas 3     	|                          0,87882 	|                                        0,12216 	|                                  0,31279 	|                    4,80857 	|
| **Vidurkis** 	|                          0,68296 	|                                        0,11825 	|                                  0,32155 	|                    4,58755 	|

1 000 000:
|              	| **Duomenu is failo nuskaitymas** 	| **Duomenu rusiavimas i atskirus konteinerius** 	| **Duomenu isvedimas i 2 askirus failus** 	| **Visos programos laikas** 	|
|--------------	|:--------------------------------:	|:----------------------------------------------:	|:----------------------------------------:	|:--------------------------:	|
| Testas 1     	|                          8,25955 	|                                        1,24183 	|                                  3,20701 	|                   47,84092 	|
| Testas 2     	|                          8,05084 	|                                        1,18114 	|                                  3,15434 	|                   47,45204 	|
| Testas 3     	|                          8,11172 	|                                        1,18472 	|                                  3,05693 	|                   49,11679 	|
| **Vidurkis** 	|                          8,14070 	|                                        1,20256 	|                                  3,13943 	|                   48,13658 	|

**Deque**
1 000:
|              	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|--------------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1     	|                                                   0.00895 	|                         0.02394 	|                              0.00997 	|
| Testas 2     	|                                                   0.00897 	|                         0.00499 	|                              0.00299 	|
| Testas 3     	|                                                   0.00898 	|                         0.00598 	|                              0.00299 	|
| **Vidurkis** 	|                                                   0.00897 	|                         0.01164 	|                              0.00532 	|

10 000:
|              	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|--------------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1     	|                                                   0.09673 	|                         0.07679 	|                              0.02493 	|
| Testas 2     	|                                                   0.09076 	|                         0.06981 	|                              0.02394 	|
| Testas 3     	|                                                   0.09076 	|                         0.13963 	|                              0.03690 	|
| **Vidurkis** 	|                                                   0.09275 	|                         0.09541 	|                              0.02859 	|

100 000:
|              	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|--------------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1     	|                                                   1.11238 	|                         0.98736 	|                              0.27977 	|
| Testas 2     	|                                                   1.31560 	|                         0.95867 	|                              0.27230 	|
| Testas 3     	|                                                   1.46857 	|                         1.04547 	|                              0.26928 	|
| **Vidurkis** 	|                                                   1.29885 	|                         0.99717 	|                              0.27378 	|

1 000 000:
|              	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|--------------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1     	|                                                  10.77466 	|                        12.37858 	|                              2.61010 	|
| Testas 2     	|                                                   9.07082 	|                        11.51124 	|                              2.57560 	|
| Testas 3     	|                                                   9.93175 	|                        11.47874 	|                              2.60594 	|
| **Vidurkis** 	|                                                   9.92574 	|                        11.78952 	|                              2.59721 	|


**Lists**
1 000:
|              	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|--------------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1     	|                                                   0.01296 	|                         1.14586 	|                              0.73854 	|
| Testas 2     	|                                                   0.01197 	|                         1.12726 	|                              0.73404 	|
| Testas 3     	|                                                   0.01396 	|                         0.92665 	|                              0.81035 	|
| **Vidurkis** 	|                                                   0.01286 	|                         1.06659 	|                              0.75993 	|

10 000:
|              	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|--------------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1     	|                                                   0.13065 	|                         1.06181 	|                              0.80043 	|
| Testas 2     	|                                                   0.13264 	|                         1.20746 	|                              0.71838 	|
| Testas 3     	|                                                   0.13265 	|                         1.14781 	|                              0.74092 	|
| **Vidurkis** 	|                                                   0.13198 	|                         1.13903 	|                              0.75324 	|

100 000:
|              	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|--------------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1     	|                                                   1.47833 	|                         0.95581 	|                              0.98047 	|
| Testas 2     	|                                                   1.48148 	|                         0.97961 	|                              0.97971 	|
| Testas 3     	|                                                   1.53137 	|                         0.95918 	|                              0.99839 	|
| **Vidurkis** 	|                                                   1.49706 	|                         0.96487 	|                              0.98619 	|

1 000 000:
|              	| **Duomenu is failo nuskaitymas ir skyrimas i konteineri** 	| **Studentu rusiavimo funkcija** 	| **Studentu skirstymas i dvi grupes** 	|
|--------------	|:---------------------------------------------------------:	|:-------------------------------:	|:------------------------------------:	|
| Testas 1     	|                                                  14.37596 	|                         0.97886 	|                              3.61226 	|
| Testas 2     	|                                                  13.79815 	|                         0.98787 	|                              3.29464 	|
| Testas 3     	|                                                  12.61501 	|                         0.93605 	|                              2.87775 	|
| **Vidurkis** 	|                                                  13.59637 	|                         0.96759 	|                              3.26155 	|
