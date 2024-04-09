#include "BibliotekosL.h"
using namespace std;
using namespace std::chrono;

int main()
{
	auto laikas1 = duration<double>::zero();
	auto laikas2 = duration<double>::zero();
	auto laikas3 = duration<double>::zero();
	int dydis = 0;
	list<mokiniai> M(1000000);
	list<mokiniai> B(0);
	char raide;

	cout << "Ar norite generuoti duomenys?" << endl << "(T) - taip / (bet koks kitas simbolis) - ne" << endl;
	cin >> raide;

	if (raide == 'T' || raide == 't')
	{
		dydis = kiekGeneruoti(M, dydis);
		M.clear();
		M.resize(1000000);
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

	rikiavimas(M, dydis, raide);

	cout << "Ar norite rezultata spauzdinti faile ar ekrane?" << endl << "Faile (F) / Ekrane (bet koks kitas zenklas)" << endl;
	cin >> raide;
	if (raide == 'E' || raide == 'e')
	{
		spauzdinimasEkrane(M, dydis);
	}
	else
	{
		spauzdinimasFaile(M, B, dydis);
	}

	cout << "\nDuomenu is failo i konteineri nuskaitymas: " << fixed << setprecision(5) << laikas1.count() << endl;
	cout << "Duomenu rusiavimas konteineryje: " << fixed << setprecision(5) << laikas2.count() << endl;
	cout << "Duomenu skirstymas i 2 konteinerius: " << fixed << setprecision(5) << laikas3.count() << endl;
	return 0;
}
