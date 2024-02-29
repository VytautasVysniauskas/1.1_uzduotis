#pragma once


struct mokiniai
{
	string name;
	string surname;
	double average;
	double med;
};

void spauzdinimasFaile(mokiniai M[], int dydis);
void spauzdinimasEkrane(mokiniai M[], int dydis);
void vidurys(vector<vector<int>>& ndrez, vector<double>& mediana);
void skaitymasRanka(vector<string>& mokiniuV, vector<string>& mokiniuP, vector<vector<int>>& ndrez, vector<int>& egzrez, vector<double>& vidurkis);
int skaitymasFailo(vector<string>& mokiniuV, vector<string>& mokiniuP, vector<vector<int>>& ndrez, vector<int>& egzrez, vector<double>& vidurkis);
void rikiavimas(mokiniai M[], int dydis, char pasirinkimas);