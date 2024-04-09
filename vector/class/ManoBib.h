#pragma once
#include "Bibliotekos.h"
using namespace std;
using namespace std::chrono;

class mokiniai {
private:
    string name;
    string surname;
    vector<int> ndRez;
    int egzRez;
    double average;
    double med;

public:
    mokiniai() :
        name(""), surname(""), egzRez(0), average(0), med(0) {}

    mokiniai(const string& n) :
        name(n), surname(""), egzRez(0), average(0), med(0) {}

    mokiniai(const string& n, const string& s) :
        name(n), surname(s), egzRez(0), average(0), med(0) {}

    mokiniai(const string& n, const string& s, int egz) :
        name(n), surname(s), egzRez(egz), average(0), med(0) {}

    mokiniai(const string& n, const string& s, int egz, double av) :
        name(n), surname(s), egzRez(egz), average(av), med(0) {}

    mokiniai(const string& n, const string& s, int egz, double av, double med) :
        name(n), surname(s), egzRez(egz), average(av), med(med) {}

    ~mokiniai() 
    {
        ndRez.clear();
    }

    const string& getName() const { return name; }
    const string& getSurname() const { return surname; }
    const vector<int>& getNdRez() const { return ndRez; }
    int getEgzRez() const { return egzRez; }
    double getAverage() const { return average; }
    double getMed() const { return med; }

    void setName(const string n) { name = n; }
    void setSurname(const string s) { surname = s; }
    void setEgzRez(int egz) { egzRez = egz; }
    void setNdRez(int nd) { ndRez.push_back(nd); }
    void setAverage(double ndRez, double egz) { average = 0.4 * ndRez + 0.6 * egz; }
    void setMed(double vid1, double vid2) { med = (vid1 + vid2) / 2; }
    void setMed(double vid) { med = vid; }
};

void spauzdinimasFaile(vector<mokiniai>&, vector<mokiniai>&, int, duration<double>&);
void spauzdinimasEkrane(vector<mokiniai>&, int);
void vidurys(vector<mokiniai>&, int);
int skaitymasRanka(vector<mokiniai>&, int);
int skaitymasFailo(vector<mokiniai>&, int, duration<double>&);
void rikiavimas(vector<mokiniai>&, int, char);
void duomenuGeneravimas(int);
void kiekGeneruoti();
