#include <iostream>
#include <iomanip>
using namespace std;

struct duom
{
	string vard;
	string pav;
	int ndsk;
	int ndrez[10];
	int egz;
};

void rikiavimas(duom M[], int i)
{
	for (int j = 0; j < M[i].ndsk - 1; j++)
	{
		for (int z = j; z < M[i].ndsk; z++)
		{
			if (M[i].ndrez[j] > M[i].ndrez[z])
			{
				swap(M[i].ndrez[j], M[i].ndrez[z]);
			}
		}
	}
}

void printinimas(duom M[], double rezm[], double rezv[], int sk)
{
	char raide;
	cout << "Ar norite naudoti vidurki ar mediana? (Iveskite V arva M)" << endl;
	cin >> raide;

	std::cout << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::left << "Vardas" << std::setw(20) << std::left << "Galutinis (Vid.) / Galutinis (Med.)\n";
	cout << "---------------------------------------------------------------------" << endl;

	if (raide == 'V' || raide == 'v')
	{
		for (int i = 0; i < sk; i++)
		{
			std::cout << std::setw(15) << std::left << M[i].pav << std::setw(15) << std::left << M[i].vard << std::setw(20) << std::left << std::fixed << std::setprecision(2) << rezv[i] << endl;

		}
	}

	else
	{
		for (int i = 0; i < sk; i++)
		{
			std::cout << std::setw(15) << std::left << M[i].pav << std::setw(15) << std::left << M[i].vard << std::setw(20) << std::left << std::fixed << std::setprecision(2) << rezm[i] << endl;

		}
	}
}

void rankinisBudas(duom M[], double rezm[], double rezv[])
{
	int sk;
	cout << "Iveskite studentu kieki: " << endl;
	cin >> sk;

	for (int i = 0; i < sk; i++)
	{
		double vid = 0;
		cout << "Iveskite savo duomenys (vardas, pav, nd sk ir egz rez:)\n";
		cin >> M[i].vard >> M[i].pav >> M[i].ndsk >> M[i].egz;

		for (int j = 0; j < M[i].ndsk; j++)
		{
			cout << "Iveskite sekanti nd tarpini rezultata:\n";
			cin >> M[i].ndrez[j];
			vid = vid + M[i].ndrez[j];
		}
		vid = vid / M[i].ndsk;
		rezv[i] = 0.4 * vid + 0.6 * M[i].egz;

		rikiavimas(M, i);

		if (M[i].ndsk % 2 == 0)
		{
			int v = M[i].ndsk / 2;
			rezm[i] = (M[i].ndrez[v - 1] + M[i].ndrez[v]) / 2.0;
		}
		else
		{
			int v = (M[i].ndsk - 1) / 2;
			rezm[i] = M[i].ndrez[v];
		}
	}

	printinimas(M, rezm, rezv, sk);
}

int main()
{
	double rezv[25], rezm[25];
	struct duom M[25];
	char raide;

	rankinisBudas(M, rezm, rezv);

	return 0;
}
