#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void spauzdinimas(const vector<string>& mokiniuV, const vector<string>& mokiniuP, const vector<double>& vidurkis, const vector<double>& mediana)
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

int main()
{
	int sk, test, size;
	string vardas, pav;
	vector<string> mokiniuV;
	vector<string> mokiniuP;
	vector<vector<int>> ndrez;
	vector<int>	egzrez;
	vector<double> vidurkis;
	vector<double> mediana;

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

	vidurys(ndrez, mediana);
	spauzdinimas(mokiniuV, mokiniuP, vidurkis, mediana);

	return 0;
}