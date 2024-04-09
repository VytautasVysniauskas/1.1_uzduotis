#include "ManoBibD.h"
#include "BibliotekosD.h"
using namespace std;
using namespace std::chrono;

void spauzdinimasFaile(deque<mokiniai>& M, deque<mokiniai>& B, int dydis)
{
	int bDydis = 0;

	for (int i = 0; i < dydis; i++)
	{
		if (M[i].average < 5.0)
		{
			B.push_front(M[i]);
			bDydis++;
		}
	}

	FILE* pFile = fopen("pazenge.txt", "w");
	FILE* bFile = fopen("buki.txt", "w");

	char raide;
	cout << "Ar norite naudoti vidurki ar mediana?" << endl << "Vidurki (V) / Mediana (bet koks kitas zenklas)" << endl;
	cin >> raide;

	if (raide == 'V' || raide == 'v')
	{
		fprintf(pFile, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Vid.)");
		fprintf(pFile, "-----------------------------------------------------------------\n");
		fprintf(bFile, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Vid.)");
		fprintf(bFile, "-----------------------------------------------------------------\n");

		for (int i = 0; i < dydis; i++)
		{
			if (M[i].average >= 5.0)
			{
				fprintf(pFile, "%-15s%-15s%-20.2f\n", M[i].surname.c_str(), M[i].name.c_str(), M[i].average);
			}
		}
		for (int i = bDydis - 1; i > 0; i--)
		{
			fprintf(bFile, "%-15s%-15s%-20.2f\n", B[i].surname.c_str(), B[i].name.c_str(), B[i].average);
		}
	}
	else
	{
		fprintf(pFile, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Med.)");
		fprintf(pFile, "-----------------------------------------------------------------\n");
		fprintf(bFile, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Med.)");
		fprintf(bFile, "-----------------------------------------------------------------\n");

		for (int i = 0; i < dydis; i++)
		{
			if (M[i].average >= 5.0)
			{
				fprintf(pFile, "%-15s%-15s%-20.2f\n", M[i].surname.c_str(), M[i].name.c_str(), M[i].med);
			}
		}
		for (int i = bDydis - 1; i > 0; i--)
		{
			fprintf(bFile, "%-15s%-15s%-20.2f\n", B[i].surname.c_str(), B[i].name.c_str(), B[i].med);
		}
	}

	cout << "Sukurti 2 atskiri failai:\npazenge.txt ir buki.txt" << endl << endl;
	fclose(pFile);
	fclose(bFile);
}

void spauzdinimasEkrane(deque<mokiniai>& M, int dydis)
{
	char raide;
	cout << "Ar norite naudoti vidurki ar mediana?" << endl << "Vidurki (V) / Mediana (bet koks kitas zenklas)";
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

void vidurys(deque<mokiniai>& M, int dydis)
{
	for (int i = 0; i < dydis; i++)
	{
		sort(M[i].ndRez.begin(), M[i].ndRez.end());
		size_t ndDydis = M[i].ndRez.size();

		if (ndDydis % 2 == 0)
		{
			double vidurys1 = static_cast<double>(M[i].ndRez[ndDydis / 2]);
			double vidurys2 = static_cast<double>(M[i].ndRez[ndDydis / 2 - 1]);
			M[i].med = (vidurys1 + vidurys2) / 2;
		}
		else
		{
			double vidurys = static_cast<double>(M[i].ndRez[ndDydis / 2]);
			M[i].med = vidurys;
		}
	}
}

int skaitymasRanka(deque<mokiniai>& M, int dydis)
{
	string vardas, pav;
	int sk, test;
	int i = 0;

	while (1)
	{
		int breakas = 0;

		while (1)
		{
			try
			{
				cout << "Iveskite mokinio varda. Jei nebenorite rasyti, iveskite 0:" << endl;
				cin >> vardas;

				if (vardas.find_first_of("0") != string::npos)
				{
					breakas = 1;
					break;
				}
				if (vardas.find_first_of("123456789") != string::npos)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw runtime_error("Bloga ivestis, iveskite mokinio varda be skaiciu arba 0 jeigu nebenorite rasyti.");
				}
				else
				{
					break;
				}
			}
			catch (const exception& e)
			{
				cerr << "Klaida: " << e.what() << endl;
			}
		}

		if (breakas) break;

		while (1)
		{
			try
			{
				cout << "Iveskite mokinio pavarde:" << endl;
				cin >> pav;

				if (pav.find_first_of("0123456789") == string::npos)
				{
					break;
				}
				else
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw runtime_error("Bloga ivestis, iveskite mokinio pavarde be skaiciu.");
				}
			}
			catch (const exception& e)
			{
				cerr << "Klaida: " << e.what() << endl;
			}
		}

		M[i].name = vardas;
		M[i].surname = pav;

		double x = 0.0;
		breakas = 0;

		while (1)
		{
			while (1)
			{
				try
				{
					cout << "Iveskite sekanti nd rezultata. Jei ju nebera, iveskite 0. " << endl;
					cin >> sk;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						throw runtime_error("Neteisinga ivestis. Iveskite sveika skaiciu.");
					}
					else if (sk == 0 && x == 0)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						throw runtime_error("Turi buti iraasytas bent vienas ND rezultatas.");
					}
					else if (sk == 0 && x != 0)
					{
						breakas = 1;
						break;
					}
					else
					{
						break;
					}
				}
				catch (const exception& e) {
					cerr << "Klaida: " << e.what() << endl;
				}
			}
			if (breakas) break;

			x = x + sk;
			M[i].ndRez.push_back(sk);
		}

		while (1)
		{
			try
			{
				cout << "Irasykite mokinio egzamino rezultata:" << endl;
				cin >> sk;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw runtime_error("Neteisinga ivestis. Irasykite sveika skaiciu");
				}
				else
				{
					break;
				}
			}
			catch (const exception& e)
			{
				cerr << "Klaida: " << e.what() << endl;
			}
		}
		M[i].egzRez = sk;

		if (M[i].ndRez.size() > 0)
		{
			x = x / M[i].ndRez.size();
			M[i].average = 0.4 * x + 0.6 * test;
		}

		i++;
	}

	dydis = i;
	return dydis;
}

int skaitymasFailo(deque<mokiniai>& M, int dydis, duration<double>& laikas1)
{
	string fileV;
	char vardas[100], pav[100], trash[100];
	int sk, test, ndSk = 0;
	int i = 0;

	cout << "Iveskite failo pavadinima, is kurio bus nuskaityti duomenys:" << endl;
	cin >> fileV;

	FILE* myFile = fopen(fileV.c_str(), "r");
	if (!myFile)
	{
		cerr << "Problema bandant atidaryti faila. Programa bus uzdaroma." << endl;
		return 0;
	}

	auto pradzia1 = steady_clock::now();

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
		M[i].name = vardas;
		M[i].surname = pav;

		double x = 0.0;

		for (int j = 0; j < ndSk; j++)
		{
			fscanf(myFile, "%d", &sk);
			x = x + sk;
			M[i].ndRez.push_back(sk);
		}
		fscanf(myFile, "%d", &test);
		M[i].egzRez = test;
		if (ndSk > 0)
		{
			x = x / ndSk;
			M[i].average = 0.4 * x + 0.6 * test;
		}
		i++;
	}
	auto pabaiga1 = steady_clock::now();
	laikas1 = duration_cast<duration<double>>(pabaiga1 - pradzia1);

	fclose(myFile);

	dydis = i;
	return dydis;
}

void rikiavimas(deque<mokiniai>& M, int dydis, char pasirinkimas)
{ 
	if (pasirinkimas == 'V' || pasirinkimas == 'v')
	{
		sort(M.begin(), M.begin() + dydis, [](const mokiniai& a, const mokiniai& b)
			{
				return a.name > b.name;
			});
	}
	else if (pasirinkimas == 'P' || pasirinkimas == 'p')
	{
		sort(M.begin(), M.begin() + dydis, [](const mokiniai& a, const mokiniai& b)
			{
				return a.surname > b.surname;
			});
	}
	else if (pasirinkimas == 'A' || pasirinkimas == 'a')
	{
		sort(M.begin(), M.begin() + dydis, [](const mokiniai& a, const mokiniai& b)
			{
				return a.average > b.average;
			});
	}
	else
	{
		sort(M.begin(), M.begin() + dydis, [](const mokiniai& a, const mokiniai& b)
			{
				return a.med > b.med;
			});
	}
}

int duomenuGeneravimas(deque<mokiniai>& M, int kiek)
{
	int DK = 100 * pow(10, kiek);
	if (DK % 10 != 0)
	{
		DK++;
	}

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> intervalas(10, 20);
	int ndSkaicius = intervalas(gen);

	string fileV;
	cout << "Iveskite failo pavadinima, kuriame norite sugeneruoti savo duomenis." << endl;
	cin >> fileV;

	FILE* myFile = fopen(fileV.c_str(), "w");

	fprintf(myFile, "%-26s%-26s", "Vardas", "Pavarde");
	for (int i = 1; i <= ndSkaicius; i++)
	{
		fprintf(myFile, "%s%-8d", "ND", i);
	}
	fprintf(myFile, "%s\n", "Egz.");

	for (int x = 1; x <= DK; x++)
	{
		mt19937 gen(rd());

		mokiniai mok;
		mok.name = "Vardas" + to_string(x);
		mok.surname = "Pavarde" + to_string(x);
		fprintf(myFile, "%-26s%-26s", mok.name.c_str(), mok.surname.c_str());
		for (int j = 1; j <= ndSkaicius; j++)
		{
			uniform_int_distribution<int> pazGen(1, 10);
			mok.ndRez.push_back(pazGen(gen));
			fprintf(myFile, "%-10d", mok.ndRez[j - 1]);
		}
		uniform_int_distribution<int> egzGen(1, 10);
		mok.egzRez = egzGen(gen);
		fprintf(myFile, "%d\n", mok.egzRez);
		int sk = accumulate(mok.ndRez.begin(), mok.ndRez.end(), 0);
		mok.average = (0.4 * sk / ndSkaicius) + (0.6 * mok.egzRez);
		M.push_front(mok);
	}

	fclose(myFile);
	return DK;
}

int kiekGeneruoti(deque<mokiniai>& M, int dydis)
{
	char raide;
	cout << "Pasirinkite kiek mokiniu duomenu norite generuoti." << endl << "(1) - 1 000 / (2) - 10 000 / (3) - 100 000 / (bet koks kitas simbolis) - 1 000 000" << endl;
	cin >> raide;
	if (raide == '1')
	{
		dydis = duomenuGeneravimas(M, 1);
	}
	else if (raide == '2')
	{
		dydis = duomenuGeneravimas(M, 2);
	}
	else if (raide == '3')
	{
		dydis = duomenuGeneravimas(M, 3);
	}
	else
	{
		dydis = duomenuGeneravimas(M, 4);
	}
	return dydis;
}
