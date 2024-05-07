#pragma once
#include "Bibliotekos.h"

/**
 * @brief Bazinë klase, kuri atstovauja asmeniui.
 *
 * Si klasë apibrezia bendrus atributus ir metodus asmeniui.
 */
using namespace std;
using namespace std::chrono;

class zmogus {
protected:
    string name;
    string surname;
    
public:
    /**
    * @brief Numatytasis konstruktorius.
    */
    zmogus() : name(""), surname("") {}
    /**
    * @brief Konstruktorius su vardo parametru.
    *
    * @param n - Asmens vardas.
    */
    zmogus(const string& n) : name(n), surname("") {}
    /**
     * @brief Konstruktorius su vardo ir pavardës parametrais.
     *
     * @param n - Asmens vardas.
     * @param s - Asmens pavarde.
     */
    zmogus(const string& n, const string& s) : name(n), surname(s) {}

    virtual ~zmogus() {} /**< Virtualus destruktorius. */

    /**
    * @brief Abstraktus metodas, skirtas atspausdinti informacija apie asmeni.
    *
    * Si metoda privalo igyvendinti isvestinës klases.
    */

    virtual void printInfo() const = 0;

    /**
     * @brief Gauna asmenio vardà.
     *
     * @return Asmens vardas.
     */

    const string& getName() const { return name; }
    /**
     * @brief Gauna asmenio pavarde.
     *
     * @return Asmens pavarde.
     */
    const string& getSurname() const { return surname; }
};
/**
 * @brief Klase, kuri atstovauja mokiniui.
 *
 * Si klase isplecia bazine klase zmogus ir prideda specifinius mokinio atributus ir metodus.
 */

class mokiniai : public zmogus {
private:
    std::string name; /**< Mokinio vardas */
    std::string surname; /**< Mokinio pavarde */
    std::vector<int> ndRez; /**< Mokinio namu darbu rezultatai */
    int egzRez; /**< Mokinio galutinis egzamino rezultatas */
    double average; /**< Mokinio vidurkis */
    double med; /**< Mokinio mediana */

public:

    // Konstruktoriu, destruktoriu ir priskyrimo operatoriu deklaracijos...

    // Getteriu ir setteriu deklaracijos...
    mokiniai() : egzRez(0), average(0), med(0) {}
    mokiniai(const std::string& n) : name(n), egzRez(0), average(0), med(0) {}
    mokiniai(const std::string& n, const std::string& s) : name(n), surname(s), egzRez(0), average(0), med(0) {}
    mokiniai(const std::string& n, const std::string& s, int egz) : name(n), surname(s), egzRez(egz), average(0), med(0) {}
    mokiniai(const std::string& n, const std::string& s, int egz, double av) : name(n), surname(s), egzRez(egz), average(av), med(0) {}
    mokiniai(const std::string& n, const std::string& s, int egz, double av, double m) : name(n), surname(s), egzRez(egz), average(av), med(m) {}

    mokiniai(const mokiniai& other) : name(other.name), surname(other.surname), ndRez(other.ndRez), egzRez(other.egzRez), average(other.average), med(other.med) {}

    mokiniai(mokiniai&& other) noexcept : name(std::move(other.name)), surname(std::move(other.surname)), ndRez(std::move(other.ndRez)), egzRez(other.egzRez), average(other.average), med(other.med) {
        other.egzRez = 0;
        other.average = 0;
        other.med = 0;
    }

    mokiniai& operator=(const mokiniai& other) {
        if (this != &other) {
            name = other.name;
            surname = other.surname;
            ndRez = other.ndRez;
            egzRez = other.egzRez;
            average = other.average;
            med = other.med;
        }
        return *this;
    }

    mokiniai& operator=(mokiniai&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            surname = std::move(other.surname);
            ndRez = std::move(other.ndRez);
            egzRez = other.egzRez;
            average = other.average;
            med = other.med;
            other.egzRez = 0;
            other.average = 0;
            other.med = 0;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const mokiniai& m);
    friend std::istream& operator>>(std::istream& is, mokiniai& m);

    const std::string& getName() const { return name; }
    const std::string& getSurname() const { return surname; }
    const std::vector<int>& getNdRez() const { return ndRez; }
    int getEgzRez() const { return egzRez; }
    double getAverage() const { return average; }
    double getMed() const { return med; }

    void setName(const std::string& n) { name = n; }
    void setSurname(const std::string& s) { surname = s; }
    void setEgzRez(int egz) { egzRez = egz; }
    void setNdRez(int nd) { ndRez.push_back(nd); }
    void setAverage(double ndRezAvg, double egz) { average = 0.4 * ndRezAvg + 0.6 * egz; }
    void setAverage(double av) { average = av; }
    void setMed(double vid1, double vid2) { med = (vid1 + vid2) / 2; }
    void setMed(double m) { med = m; }

    /**
    * @brief Abstraktus metodas, skirtas atspausdinti informacija apie mokini.
    *
    * Perraso bazines klases metoda.
    */

    void printInfo() const override
    {
        cout << "Name: " << getName() << ", Surname: " << getSurname() << std::endl;
    }
};

// Funkciju prototipu deklaracijos, jos aprasytos ManoBib.cpp faile.


void spauzdinimasFaile(vector<mokiniai>&, vector<mokiniai>&, int, duration<double>&);
void spauzdinimasEkrane(vector<mokiniai>&, int);
void vidurys(vector<mokiniai>&, int);
int skaitymasRanka(vector<mokiniai>&, int);
int skaitymasFailo(vector<mokiniai>&, int, duration<double>&);
void rikiavimas(vector<mokiniai>&, int, char);
void duomenuGeneravimas(int);
void kiekGeneruoti();
