#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void spauzdinimas(const vector<string>& mokiniuV, const vector<string>& mokiniuP, const vector<double>& vidurkis)
{
	char raide;
	cout << "Ar norite naudoti vidurki ar mediana? (Iveskite V arva M)" << endl;
	cin >> raide;

	int dydis = min(mokiniuV.size(), mokiniuP.size());

	std::cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.) / Galutinis (Med.)\n";
	cout << "---------------------------------------------------------------------" << endl;

	if (raide == 'V' || raide == 'v')
	{
		for (int i = 0; i < dydis; i++)
		{
			cout << setw(15) << left << mokiniuP[i] << setw(15) << left << mokiniuV[i] << setw(20) << left << fixed << std::setprecision(2) << vidurkis[i] << endl;
			;
		}
	}
	else
	{
		for (int i = 0; i < dydis; i++)
		{
			cout << setw(15) << left << mokiniuP[i] << setw(15) << left << mokiniuV[i] << endl;
		}
	}
}

int main()
{
	int sk, test;
	string vardas, pav;
	vector<string> mokiniuV;
	vector<string> mokiniuP;
	vector<vector<int>> ndrez;
	vector<int>	egzrez;
	vector<double> vidurkis;

	while (1)
	{
		cout << "Rasykite 3 dalykus: mokinio varda, pavarde ir egzamino rezultata. Jei norite daugiau neberasyti, rasykite 0 kaip viena is rezultatu" << endl;
		cin >> vardas >> pav >> test;
		if (vardas == "0" || pav == "0" || test == 0)
		{
			break;
		}
		mokiniuV.push_back(vardas);
		mokiniuP.push_back(pav);
		egzrez.push_back(test);
		vector <int> eile;
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
		if (!eile.empty())
		{
			x = x / eile.size();
			vidurkis.push_back(0.4 * x + 0.6 * test);
		}
		ndrez.push_back(eile);
	}

	for (auto& eile : ndrez)
	{
		sort(eile.begin(), eile.end());
	}

	spauzdinimas(mokiniuV, mokiniuP, vidurkis);

	return 0;
}
