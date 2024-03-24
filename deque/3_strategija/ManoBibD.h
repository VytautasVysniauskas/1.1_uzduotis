#pragma once
#include "BibliotekosD.h"
using namespace std;
using namespace std::chrono;

struct mokiniai
{
	string name;
	string surname;
	deque<int> ndRez;
	int egzRez;
	double average;
	double med;
};

void spauzdinimasFaile(deque<mokiniai>&, deque<mokiniai>&, int, duration<double>&);
void spauzdinimasEkrane(deque<mokiniai>&, int);
void vidurys(deque<mokiniai>&, int);
int skaitymasRanka(deque<mokiniai>&, int);
int skaitymasFailo(deque<mokiniai>&, int, duration<double>&);
void rikiavimas(deque<mokiniai>&, int, char);
void duomenuGeneravimas(int);
void kiekGeneruoti();
