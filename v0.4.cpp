#include "Bibliotekos.h"
using namespace std;

int main()
{
	struct mokiniai M[10000];
	char raide;

	vector<string> mokiniuV;
	vector<string> mokiniuP;
	vector<vector<int>> ndrez;
	vector<int>	egzrez;
	vector<double> vidurkis;
	vector<double> mediana;

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
		skaitymasRanka(mokiniuV, mokiniuP, ndrez, egzrez, vidurkis);
	}
	else
	{
		if (skaitymasFailo(mokiniuV, mokiniuP, ndrez, egzrez, vidurkis) == 0)
		{
			return 0;
		}
	}

	for (auto& eile : ndrez)
	{
		sort(eile.begin(), eile.end());
	}

	vidurys(ndrez, mediana);

	int dydis = min({ mokiniuV.size(), mokiniuP.size(), vidurkis.size(), mediana.size() });
	for (int i = 0; i < dydis; i++)
	{
		M[i].name = mokiniuV[i];
		M[i].surname = mokiniuP[i];
		M[i].average = vidurkis[i];
		M[i].med = mediana[i];
	}

	cout << "Pasirinkite pagal ka norite surusiuoti rezultatas (Mazejimo tvarka arba abaceles didejimo)" << endl << "Vardus (V) / Pavardes (P) / Gal. Vidurki (A) / Gal. Mediana (bet koks kitas zenklas)" << endl;
	cin >> raide;
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

	cout << "Ar norite rezultata spauzdinti faile ar ekrane?" << endl << "Faile (F) / Ekrane (bt koks kitas zenklas)" << endl;
	cin >> raide;

	if (raide == 'E' || raide == 'e')
	{
		spauzdinimasEkrane(M, dydis);
	}
	else
	{
		spauzdinimasFaile(M, dydis);
	}

	return 0;
}
