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
struct pazenge
{
	string name;
	string surname;
	deque<int> ndRez;
	int egzRez;
	double average;
	double med;
};
struct buki
{
	string name;
	string surname;
	deque<int> ndRez;
	int egzRez;
	double average;
	double med;
};

void spauzdinimasFaile(deque<mokiniai>&, int, duration<double>&, duration<double>&);
void spauzdinimasEkrane(deque<mokiniai>&, int, duration<double>&);
void vidurys(deque<mokiniai>&, int);
int skaitymasRanka(deque<mokiniai>&, int);
int skaitymasFailo(deque<mokiniai>&, int, duration<double>&, duration<double>&);
void rikiavimas(deque<mokiniai>&, int, char);
void pazangusIrBuki(deque<mokiniai>&, deque<pazenge>&, deque<buki>&, int, duration<double>&, duration<double>&, duration<double>&);
int duomenuGeneravimas(deque<mokiniai>&, int, duration<double>&);
int kiekGeneruoti(deque<mokiniai>&, int, duration<double>&, duration<double>&);
