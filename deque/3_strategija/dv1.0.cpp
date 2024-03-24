#include "BibliotekosD.h"
using namespace std;
using namespace std::chrono;

int main()
{
	auto laikas1 = duration<double>::zero();
	auto laikas2 = duration<double>::zero();
	auto laikas3 = duration<double>::zero();
	auto pradzia = steady_clock::now();
	int dydis = 0;
	deque<mokiniai> M(1000000);
	deque<mokiniai> B(0);
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
			cout << "Nepavyko nuskaityti duomenu, patikrinkite savo duomenu faila ir bandykite vel." << endl;
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
		cout << endl << "Sukurti 2 rez failai: pazenge.txt ir buki.txt" << endl;
	}


	cout << "\nDuomenu is failo nuskaitymas ir skyrimas i konteineri: " << fixed << setprecision(5) << laikas1.count() << endl;
	cout << "Studentu rusiavimo funkcija: " << fixed << setprecision(5) << laikas2.count() << endl;
	cout << "Studentu skirstymas i dvi grupes: " << fixed << setprecision(5) << laikas3.count() << endl;
	return 0;
}
