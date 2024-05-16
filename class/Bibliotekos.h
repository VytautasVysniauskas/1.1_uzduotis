/**
 * @file
 * @brief Sis failas yra itraukiamas tik viena karta kompiliavimo metu.
 *
 * Sis failas itraukia standartinius C++ bibliotekos antraðtes ir "ManoBib.h", kuris tiketinai apibrezia papildomus vartotojo nustatytø tipu ar funkciju.
 *
 * Itrauktos antrastes:
 * - <iostream>: Ivedimo/isvedimo srautu palaikymui.
 * - <iomanip>: Papildomiems manipuliatoriams, naudojamiems su iostream srautais.
 * - <vector>: Dinaminio masyvo palaikymui.
 * - <algorithm>: Algoritmams, naudojamiems su konteineriais, pvz., rikiavimui ir ieskojimui.
 * - <cmath>: Matematiniu funkciju apibrezimams, tokiu kaip sqrt(), sin(), cos(), ir kt.
 * - <random>: Atsitiktiniu skaiciu generatoriu palaikymui.
 * - <chrono>: Laiko matavimo ir valdymo palaikymui.
 * - <list>: Dvikryptiems saraaams palaikymui.
 * - <deque>: Sarasams, kuriems galima iterpti/istrinti is abieju galu.
 * - <memory>: Dinaminio atminties valdymui ir protinguju rodykles palaikymui.
 * - "ManoBib.h": Papildoma biblioteka, kur yra visos funkcijos.
 *
 * Itraukdami siuos failus, sis failas sukuria aplinka, leidziancia naudoti daug standartiniu C++ funkciju ir papildomu funkciju, apibrëztø "ManoBib.h".
 * Tai taip pat gali buti naudinga programai, nes kodas tampa maziau priklausomas nuo konkretaus failu struktûros ar sekos.
 */
#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <chrono>
#include <list>
#include <deque>
#include <memory>
#include "ManoBib.h"
#include <iterator>
#include <stdexcept>
