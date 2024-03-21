#pragma once
#include "BibliotekosL.h"
using namespace std;
using namespace std::chrono;

struct mokiniai
{
	string name;
	string surname;
	list<int> ndRez;
	int egzRez;
	double average;
	double med;
};

void spauzdinimasFaile(list<mokiniai>&, int);
void spauzdinimasEkrane(list<mokiniai>&, int);
void vidurys(list<mokiniai>&, int);
int skaitymasRanka(list<mokiniai>&, int);
int skaitymasFailo(list<mokiniai>&, int, duration<double>&);
void rikiavimas(list<mokiniai>&, int, char);
void pazangusIrBuki(list<mokiniai>&, list<mokiniai>&, int, duration<double>&, duration<double>&);
int duomenuGeneravimas(list<mokiniai>&, int);
int kiekGeneruoti(list<mokiniai>&, int);