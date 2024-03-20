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
struct pazenge
{
	string name;
	string surname;
	vector<int> ndRez;
	int egzRez;
	double average;
	double med;
};
struct buki
{
	string name;
	string surname;
	vector<int> ndRez;
	int egzRez;
	double average;
	double med;
};

void spauzdinimasFaile(vector<mokiniai>&, int, duration<double>&, duration<double>&);
void spauzdinimasEkrane(vector<mokiniai>&, int, duration<double>&);
void vidurys(vector<mokiniai>&, int);
int skaitymasRanka(vector<mokiniai>&, int);
int skaitymasFailo(vector<mokiniai>&, int, duration<double>&, duration<double>&);
void rikiavimas(vector<mokiniai>&, int, char);
void pazangusIrBuki(vector<mokiniai>&, vector<pazenge>&, vector<buki>&, int, duration<double>&, duration<double>&, duration<double>&);
int duomenuGeneravimas(vector<mokiniai>&, int, duration<double>&);
int kiekGeneruoti(vector<mokiniai>&, int, duration<double>&, duration<double>&);
