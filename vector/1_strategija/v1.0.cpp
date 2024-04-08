#include "Bibliotekos.h"
using namespace std;
using namespace std::chrono;

int main()
{
	auto cin1 = duration<double>::zero();
	auto cin2 = duration<double>::zero();
	auto cin3 = duration<double>::zero();
	auto cin4 = duration<double>::zero();
	auto cin5 = duration<double>::zero();
	auto cin10 = duration<double>::zero();
	auto laikas1 = duration<double>::zero();
	auto laikas2 = duration<double>::zero();
	auto laikas3 = duration<double>::zero();
	auto pradzia = steady_clock::now();
	int dydis = 0;
	vector<mokiniai> M(1000000);
	vector<pazenge> P(0);
	vector<buki> B(0);
	char raide;

	cout << "Ar norite generuoti duomenys?" << endl << "(T) - taip / (bet koks kitas simbolis) - ne" << endl;
	auto pradzia7 = steady_clock::now();
	cin >> raide;
	auto pabaiga7 = steady_clock::now();
	auto cin9 = duration_cast<duration<double>>(pabaiga7 - pradzia7);

	if (raide == 'T' || raide == 't')
	{
		dydis = kiekGeneruoti(M, dydis, cin1, cin2);
		pazangusIrBuki(M, dydis, laikas2, laikas3, cin3);
		cout << "Sukurti 2 atskiri failai:\npazenge.txt ir buki.txt" << endl << endl;
		M.clear();
		M.resize(1000000);
	}

	cout << "Pasrinkite ar norite duomenys rasyti ranka, ar skaityti is failo. Rasykite atitinkama raide." << endl << "Rasyti ranka - (R) / Skaityti is failo - bet koks kitas zenklas" << endl;
	auto pradzia4 = steady_clock::now();
	cin >> raide;
	auto pabaiga4 = steady_clock::now();
	auto cin6 = duration_cast<duration<double>>(pabaiga4 - pradzia4);

	if (raide == 'R' || raide == 'r')
	{
		dydis = skaitymasRanka(M, dydis);
	}
	else
	{
		dydis = skaitymasFailo(M, dydis, laikas1, cin4);
		if (dydis == 0)
		{
			return 0;
		}
	}

	vidurys(M, dydis);

	cout << "Pasirinkite pagal ka norite surusiuoti rezultatus (Mazejimo tvarka arba abaceles didejimo)" << endl << "Vardus (V) / Pavardes (P) / Gal. Vidurki (A) / Gal. Mediana (bet koks kitas zenklas)" << endl;
	auto pradzia5 = steady_clock::now();
	cin >> raide;
	auto pabaiga5 = steady_clock::now();
	auto cin7 = duration_cast<duration<double>>(pabaiga5 - pradzia5);
	if (raide == 'V' || raide == 'v')
	{
		rikiavimas(M, dydis, raide);
	}
	else if (raide == 'P' || raide == 'p')
	{
		rikiavimas(M, dydis, raide);
	}
	else if (raide == 'A' || raide == 'a')
	{
		rikiavimas(M, dydis, raide);
	}
	else
	{
		rikiavimas(M, dydis, raide);
	}

	cout << "Ar norite rezultata spauzdinti faile ar ekrane?" << endl << "Faile (F) / Ekrane (bet koks kitas zenklas)" << endl;
	auto pradzia6 = steady_clock::now();
	cin >> raide;
	auto pabaiga6 = steady_clock::now();
	auto cin8 = duration_cast<duration<double>>(pabaiga6 - pradzia6);

	if (raide == 'E' || raide == 'e')
	{
		spauzdinimasEkrane(M, dydis, cin5);
	}
	else
	{
		spauzdinimasFaile(M, dydis, cin5, cin10);
	}

	auto pabaiga = steady_clock::now();
	auto laikas = duration_cast<duration<double>>(pabaiga - pradzia - cin1 - cin2 - cin3 - cin4 - cin5 - cin6 - cin7 - cin8 - cin9 - cin10);

	cout << "\nDuomenu is failo nuskaitymo laikas: " << fixed << setprecision(5) << laikas1.count() << endl;
	cout << "Duomenu rusiavimas i atskirus konteinerius: " << fixed << setprecision(5) << laikas2.count() << endl;
	cout << "Duomenu isvedimas i 2 atskirus failus: " << fixed << setprecision(5) << laikas3.count() << endl;
	cout << "Visos programos veikimo laikas: " << fixed << setprecision(5) << laikas.count() << endl;
	return 0;
}
