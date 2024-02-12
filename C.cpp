#include <iostream>
#include <iomanip>
using namespace std;

void rikiavimas(int** ndRez, int ndDydziai[], int i)
{
	for (int j = 0; j < ndDydziai[i] - 1; j++)
	{
		for (int z = j; z < ndDydziai[i]; z++)
		{
			if (ndRez[i][j] > ndRez[i][z])
			{
				swap(ndRez[i][j], ndRez[i][z]);
			}
		}
	}
}

int main()
{
	string vardas, pav;
	int pDydis = 1, egzRez, dydis = 0, sk;
	string* vardai = new string[pDydis];
	string* pavardes = new string[pDydis];
	int** ndRez = new int* [pDydis];
	int* ndDydziai = new int [pDydis];

	double rezv[25], rezm[25];
	char raide;

	while (1)
	{
		cout << "Rasykite 3 dalykus: mokinio varda, pavarde ir egzamino rezultata. Jei norite daugiau neberasyti, rasykite 0 kaip viena is rezultatu" << endl;
		cin >> vardas >> pav >> egzRez;
		if (vardas == "0" || pav == "0" || egzRez == 0)
		{
			break;
		}

		if (dydis == pDydis)
		{
			pDydis = pDydis * 2;
			string* nVardai = new string[pDydis];
			string* nPavardes = new string[pDydis];
			int** nNdRez = new int* [pDydis];
			int* nNdDydziai = new int[pDydis];

			for (int i = 0; i < dydis; i++)
			{
				nVardai[i] = vardai[i];
				nPavardes[i] = pavardes[i];
				nNdRez[i] = ndRez[i];
				nNdDydziai[i] = ndDydziai[i];
			}

			delete[] vardai;
			delete[] pavardes;
			delete[] ndRez;
			delete[] ndDydziai;

			vardai = nVardai;
			pavardes = nPavardes;
			ndRez = nNdRez;
			ndDydziai = nNdDydziai;
		}

		int ndDydis = 0;
		double vid = 0.0;
		ndRez[dydis] = new int[100];

		while (1)
		{
			cout << "Rasykite sekanti mokinio nd rezultata. Jeigu norite baigti, rasykite 0" << endl;
			cin >> sk;
			if (sk == 0)
			{
				break;
			}
			ndRez[dydis][ndDydis] = sk;
			ndDydis++;
			vid = vid + sk;
		}

		vardai[dydis] = vardas;
		pavardes[dydis] = pav;
		ndDydziai[dydis] = ndDydis;

		vid = vid / ndDydis;
		rezv[dydis] = egzRez * 0.6 + vid * 0.4;

		rikiavimas(ndRez, ndDydziai, dydis);

		if (ndDydis % 2 == 0)
		{
			int v = ndDydis / 2;
			rezm[dydis] = (ndRez[dydis][v - 1] + ndRez[dydis][v]) / 2.0;
		}
		else
		{
			int v = (ndDydis - 1) / 2;
			rezm[dydis] = ndRez[dydis][v];
		}

		dydis++;
	}

	for (int i = 0; i < dydis; i++)
	{
		cout << vardai[i] << " " << pavardes[i] << " " << rezv[i] << " "  << rezm[i] << endl;

		for (int j = 0; j < ndDydziai[i]; j++)
		{
			cout << ndRez[i][j] << " ";
		}

		cout << endl << endl;
	}

	return 0;
}
