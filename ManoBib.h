#pragma once
#include "Bibliotekos.h"
using namespace std;

struct mokiniai
{
	string name;
	string surname;
	double average;
	double med;
};
void spauzdinimasFaile(mokiniai[], int);
void spauzdinimasEkrane(mokiniai[], int);
void vidurys(vector<vector<int>>&, vector<double>&);
void skaitymasRanka(vector<string>&, vector<string>&, vector<vector<int>>&, vector<int>&, vector<double>&);
int skaitymasFailo(vector<string>&, vector<string>&, vector<vector<int>>&, vector<int>&, vector<double>&);
void rikiavimas(mokiniai[], int, char);