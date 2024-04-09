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

void spauzdinimasFaile(list<mokiniai>&, list<mokiniai>&, list<mokiniai>&, int, duration<double>&, duration<double>&);
void spauzdinimasEkrane(list<mokiniai>&, int, duration<double>&);
void vidurys(list<mokiniai>&, int);
int skaitymasRanka(list<mokiniai>&, int);
int skaitymasFailo(list<mokiniai>&, int, duration<double>&, duration<double>&);
void rikiavimas(list<mokiniai>&, int, char);
int duomenuGeneravimas(list<mokiniai>&, int, duration<double>&);
int kiekGeneruoti(list<mokiniai>&, int, duration<double>&, duration<double>&);
