#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void spauzdinimasFaile(vector<string>& mokiniuV, vector<string>& mokiniuP, vector<double>& vidurkis, vector<double>& mediana)
{

}

void spauzdinimasEkrane(vector<string>& mokiniuV, vector<string>& mokiniuP, vector<double>& vidurkis, vector<double>& mediana)
{
	char raide;
	cout << "Ar norite naudoti vidurki ar mediana? (Iveskite V arva M)" << endl;
	cin >> raide;

	int dydis = min({ mokiniuV.size(), mokiniuP.size(), vidurkis.size(), mediana.size() });

	if (raide == 'V' || raide == 'v')
	{
		cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)\n";
		cout << "-----------------------------------------------------------------" << endl;
		for (int i = 0; i < dydis; i++)
		{
			cout << setw(15) << left << mokiniuP[i] << setw(15) << left << mokiniuV[i] << setw(20) << left << fixed << std::setprecision(2) << vidurkis[i] << endl;
			;
		}
	}
	else
	{
		cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)\n";
		cout << "-----------------------------------------------------------------" << endl;
		for (int i = 0; i < dydis; i++)
		{
			cout << setw(15) << left << mokiniuP[i] << setw(15) << left << mokiniuV[i] << setw(20) << left << fixed << std::setprecision(2) << mediana[i] << endl;
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

	char pas;
	cout << "Ar norite rezultata spauzdinti faile ar ekrane?" << endl << "Faile (F) / Ekrane (E)" << endl;
	cin >> pas;

	if (pas == 'E' || pas == 'e')
	{
		spauzdinimasEkrane(mokiniuV, mokiniuP, vidurkis, mediana);
	}
	else
	{
		spauzdinimasFaile(mokiniuV, mokiniuP, vidurkis, mediana)
	}

	return 0;
}
