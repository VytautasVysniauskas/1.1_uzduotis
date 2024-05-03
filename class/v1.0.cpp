#include "Bibliotekos.h"
using namespace std;
using namespace std::chrono;


std::ostream& operator<<(std::ostream& os, const mokiniai& m) {
	os << std::setw(15) << std::left << m.getSurname() << std::setw(15) << std::left << m.getName()
		<< std::setw(10) << std::left << m.getAverage();
	return os;
}

std::istream& operator>>(std::istream& is, mokiniai& m) {
	std::string line;
	std::getline(is, line);

	std::stringstream ss(line);
	std::string name, surname;
	double average;
	ss >> surname >> name >> average;
	
	m.setName(name);
	m.setSurname(surname);
	m.setAverage(average);

	return is;
}

int main()
{
	auto laikas1 = duration<double>::zero();
	auto laikas2 = duration<double>::zero();
	auto laikas3 = duration<double>::zero();
	int dydis = 0;
	vector<mokiniai> M(1000000);
	vector<mokiniai> B(0);
	char raide;

	cout << "Ar norite generuoti duomenys?" << endl << "(T) - taip / (bet koks kitas simbolis) - ne" << endl;
	cin >> raide;

	if (raide == 'T' || raide == 't')
	{
		kiekGeneruoti();
	}

	cout << "Pasrinkite ar norite duomenys rasyti ranka, ar skaityti is failo. Rasykite atitinkama raide." << endl << "Rasyti ranka - (R) / Skaityti is failo - bet koks kitas zenklas" << endl;
	cin >> raide;

	if (raide == 'R' || raide == 'r')
	{
		dydis = skaitymasRanka(M, dydis);
	}
	else
	{
		dydis = skaitymasFailo(M, dydis, laikas1);
		if (dydis == 0)
		{
			return 0;
		}
	}

	vidurys(M, dydis);

	cout << "Pasirinkite pagal ka norite surusiuoti rezultatus (Mazejimo tvarka arba abaceles didejimo)" << endl << "Vardus (V) / Pavardes (P) / Gal. Vidurki (A) / Gal. Mediana (bet koks kitas zenklas)" << endl;
	cin >> raide;
	auto pradzia2 = steady_clock::now();
	rikiavimas(M, dydis, raide);
	auto pabaiga2 = steady_clock::now();
	laikas2 = duration_cast<duration<double>>(pabaiga2 - pradzia2);

	cout << "Ar norite rezultata spauzdinti faile ar ekrane?" << endl << "Faile (F) / Ekrane (bet koks kitas zenklas)" << endl;
	cin >> raide;

	if (raide == 'E' || raide == 'e')
	{
		spauzdinimasEkrane(M, dydis);
	}
	else
	{
		spauzdinimasFaile(M, B, dydis, laikas3);
	}

	cout << "\nDuomenu nuskaitymas is failo i konteineri: " << fixed << setprecision(5) << laikas1.count() << endl;
	cout << "Duomenu rusiavimas atitinkamam konteinery: " << fixed << setprecision(5) << laikas2.count() << endl;
	cout << "Duomenu skirtstymas i 2 konteinerius: " << fixed << setprecision(5) << laikas3.count() << endl;
	return 0;
}
