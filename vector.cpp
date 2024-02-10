#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	int sk, test;
	string vardas, pav;
	vector<string> mokiniuV;
	vector<string> mokiniuP;
	vector<vector<int>> ndrez;
	vector<int>	egzrez;

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
		while (1)
		{
			cout << "Rasykite sekanti mokinio nd rezultata. Jeigu norite baigti, rasykite 0" << endl;
			cin >> sk;
			if (sk == 0)
			{
				break;
			}
			eile.push_back(sk);
		}
		ndrez.push_back(eile);
	}

	for (const auto& kas : mokiniuV)
	{
		cout << kas << " ";
	}
	for (const auto& kas : mokiniuP)
	{
		cout << kas << " ";
	}
	for (const auto& kiek : egzrez)
	{
		cout << kiek << " ";
	}
	for (const auto& eile : ndrez)
	{
		for (const auto& elem : eile)
		{
			cout << elem << " ";
		}
		cout << endl;
	}

	return 0;
}