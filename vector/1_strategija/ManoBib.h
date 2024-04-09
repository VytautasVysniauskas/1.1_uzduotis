#pragma once
#include "Bibliotekos.h"
using namespace std;
using namespace std::chrono;

struct mokiniai
{
	string name;
	string surname;
	vector<int> ndRez;
	int egzRez;
	double average;
	double med;
};

void spauzdinimasFaile(vector<mokiniai>&, vector<mokiniai>&, vector<mokiniai>&, int, int, int, duration<double>&);
void spauzdinimasEkrane(vector<mokiniai>&, int, duration<double>&);
void vidurys(vector<mokiniai>&, int);
int skaitymasRanka(vector<mokiniai>&, int);
int skaitymasFailo(vector<mokiniai>&, int, duration<double>&, duration<double>&);
void rikiavimas(vector<mokiniai>&, int, char);
int duomenuGeneravimas(vector<mokiniai>&, int, duration<double>&);
int kiekGeneruoti(vector<mokiniai>&, int, duration<double>&, duration<double>&);
