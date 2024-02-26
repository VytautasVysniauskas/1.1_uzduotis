#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct mokiniai
{
	string name;
	string surname;
	double average;
	double med;
};

void spauzdinimasFaile(mokiniai M[], int dydis)
{
	string rFailasPav;
	cout << "Iveskite failo pavadinima, kuriame bus isvedami rezultatai." << endl;
	cin >> rFailasPav;

	FILE* rFailas = fopen(rFailasPav.c_str(), "w");

	char raide;
	cout << "Ar norite naudoti vidurki ar mediana? (Iveskite V arva M)" << endl;
	cin >> raide;

	if (raide == 'V' || raide == 'v')
	{
		fprintf(rFailas, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Vid.)");
		fprintf(rFailas, "-----------------------------------------------------------------\n");

		for (int i = 0; i < dydis; i++)
		{
			fprintf(rFailas, "%-15s%-15s%-20.2f\n", M[i].surname.c_str(), M[i].name.c_str(), M[i].average);
		}
	}
	else
	{
		fprintf(rFailas, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Vid.)");
		fprintf(rFailas, "-----------------------------------------------------------------\n");

		for (int i = 0; i < dydis; i++)
		{
			fprintf(rFailas, "%-15s%-15s%-20.2f\n", M[i].surname.c_str(), M[i].name.c_str(), M[i].med);
		}
	}

	cout << "Rezultatai isvesti faile: " << rFailasPav << endl;

	fclose(rFailas);

}

void spauzdinimasEkrane(mokiniai M[], int dydis)
{
	char raide;
	cout << "Ar norite naudoti vidurki ar mediana? (Iveskite V arva M)" << endl;
	cin >> raide;

	if (raide == 'V' || raide == 'v')
	{
		cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)\n";
		cout << "-----------------------------------------------------------------" << endl;
		for (int i = 0; i < dydis; i++)
		{
			cout << setw(15) << left << M[i].surname << setw(15) << left << M[i].name << setw(20) << left << fixed << std::setprecision(2) << M[i].average << endl;
		}
	}
	else
	{
		cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)\n";
		cout << "-----------------------------------------------------------------" << endl;
		for (int i = 0; i < dydis; i++)
		{
			cout << setw(15) << left << M[i].surname << setw(15) << left << M[i].name << setw(20) << left << fixed << std::setprecision(2) << M[i].med << endl;
		}
	}
}

void vidurys(vector<vector<int>>& ndrez, vector<double>& mediana)
{
	int size = ndrez.size();

	for (int i = 0; i < size; i++)
	{
		int dydis = ndrez[i].size();

		if (dydis % 2 == 0)
		{
			double vidurys1 = static_cast<double>(ndrez[i][dydis / 2]);
			double vidurys2 = static_cast<double>(ndrez[i][dydis / 2 - 1]);
			mediana.push_back((vidurys1 + vidurys2) / 2.0);
		}
		else
		{
			double vidurys = static_cast<double>(ndrez[i][dydis / 2]);
			mediana.push_back(vidurys);
		}
	}
}

void skaitymasRanka(vector<string>& mokiniuV, vector<string>& mokiniuP, vector<vector<int>>& ndrez, vector<int>& egzrez, vector<double>& vidurkis)
{
	string vardas, pav;
	int sk, test;

	while (1)
	{
		cout << "Rasykite mokinio varda. Jeigu daugiau nebenorite rasyti, rasykite 0." << endl;
		cin >> vardas;
		if (vardas == "0")
		{
			break;
		}

		cout << "Rasykite mokinio pavarda:" << endl;
		cin >> pav;

		mokiniuV.push_back(vardas);
		mokiniuP.push_back(pav);

		vector<int> eile;
		double x = 0.0;

		while (1)
		{
			cout << "Rasykite sekanti mokinio nd rezultata. Jeigu norite baigti, rasykite 0" << endl;
			cin >> sk;
			if (sk == 0)
			{
				break;
			}
			x = x + sk;
			eile.push_back(sk);
		}

		cout << "Rasykite mokinio egzamino rezultata:" << endl;
		cin >> test;
		egzrez.push_back(test);

		if (!eile.empty())
		{
			x = x / eile.size();
			vidurkis.push_back(0.4 * x + 0.6 * test);
		}

		ndrez.push_back(eile);
	}
}

int skaitymasFailo(vector<string>& mokiniuV, vector<string>& mokiniuP, vector<vector<int>>& ndrez, vector<int>& egzrez, vector<double>& vidurkis)
{
	string fileV;
	char vardas[100], pav[100], trash[100];
	int sk, test, ndSk = 0;

	cout << "Iveskite failo pavadinima, is kurio bus nuskaityti duomenys:" << endl;
	cin >> fileV;

	FILE* myFile = fopen(fileV.c_str(), "r");
	if (!myFile)
	{
		cerr << "Problema bandant atidaryti faila. Programa bus uzdaroma." << endl;
		return 0;
	}

	fscanf(myFile, "%s", &trash);
	fscanf(myFile, "%s", &trash);

	while (fscanf(myFile, "%s", &trash) == 1)
	{
		int c;
		c = fgetc(myFile);

		if (c == '\n' || c == EOF)
		{
			break;
		}
		ndSk++;
	}

	while (1)
	{
		if (fscanf(myFile, "%s", &vardas) == EOF)
		{
			break;
		}
		fscanf(myFile, "%s", &pav);

		mokiniuV.push_back(vardas);
		mokiniuP.push_back(pav);

		vector<int> eile;
		double x = 0.0;

		for (int i = 0; i < ndSk; i++)
		{
			fscanf(myFile, "%d", &sk);
			x = x + sk;
			eile.push_back(sk);
		}

		fscanf(myFile, "%d", &test);
		egzrez.push_back(test);

		if (!eile.empty())
		{
			x = x / eile.size();
			vidurkis.push_back(0.4 * x + 0.6 * test);
		}

		ndrez.push_back(eile);
	}

	fclose(myFile);

	return 1;
}

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

	cout << "Pasrinkite ar norite duomenys rasyti ranka, ar skaityti is failo. Rasykite atitinkama raide." << endl << "Rasyti ranka (R) / Skaityti is failo (F)" << endl;
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

	//cout << "Pasirinkite pagal ka norite surusiuoti rezultatas (Mazejimo tvarka)" << endl << "Vardus (V) / Pavardes (P) / Gal. Vidurki (A) / Gal. Mediana (M)" << endl;
	//cin >> raide;

	cout << "Ar norite rezultata spauzdinti faile ar ekrane?" << endl << "Faile (F) / Ekrane (E)" << endl;
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
