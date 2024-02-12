#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	string vardas, pav;
	int pDydis = 5, test, dydis = 0, sk;
	string* vardai = new string[pDydis];
	string* pavardes = new string[pDydis];
	int* egzRez = new int[pDydis];
	int** ndRez = new int* [pDydis];
	int* ndDydziai = new int[pDydis];

	double rezv[25], rezm[25];
	char raide;

	while (1)
	{
		cout << "Rasykite 3 dalykus: mokinio varda, pavarde ir egzamino rezultata. Jei norite daugiau neberasyti, rasykite 0 kaip viena is rezultatu" << endl;
		cin >> vardas >> pav >> test;
		if (vardas == "0" || pav == "0" || test == 0)
		{
			break;
		}

		if (dydis == pDydis)
		{
			pDydis = pDydis * 2;
			string* nVardai = new string[pDydis];
			string* nPavardes = new string[pDydis];
			int* nEgzRez = new int[pDydis];
			int** nNdRez = new int* [pDydis];
			int* nNdDydziai = new int[pDydis];

			for (int i = 0; i < dydis; i++)
			{
				nVardai[i] = vardai[i];
				nPavardes[i] = pavardes[i];
				nEgzRez[i] = egzRez[i];
				nNdRez[i] = ndRez[i];
				nNdDydziai[i] = ndDydziai[i];
			}

			delete[] vardai;
			delete[] pavardes;
			delete[] egzRez;
			delete[] ndRez;
			delete[] ndDydziai;

			vardai = nVardai;
			pavardes = nPavardes;
			egzRez = nEgzRez;
			ndRez = nNdRez;
			ndDydziai = nNdDydziai;
		}

		int ndDydis = 0;
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
		}


		vardai[dydis] = vardas;
		pavardes[dydis] = pav;
		egzRez[dydis] = test;
		ndDydziai[dydis] = ndDydis;
		dydis++;
	}

	for (int i = 0; i < dydis; i++)
	{
		cout << vardai[i] << " " << pavardes[i] << " " << egzRez[i] << " " << endl;

		for (int j = 0; j < ndDydziai[i]; j++)
		{
			cout << ndRez[i][j] << " ";
		}

		cout << endl << endl;
	}

	return 0;
}