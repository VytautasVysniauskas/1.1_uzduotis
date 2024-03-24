#include "ManoBib4.h"
#include "Bibliotekos4.h"
using namespace std;
using namespace std::chrono;

void spauzdinimasFaile(vector<mokiniai>& M, vector<pazenge>& P, vector<buki>& B, int dydis, duration<double>& cin5, duration<double>& laikas2, duration<double>& laikas3)
{
	int pDydis = 0, bDydis = 0;
	char raide;

	cout << "Ar norite naudoti vidurki ar mediana?" << endl << "Vidurki (V) / Mediana (bet koks kitas zenklas)" << endl;
	auto pradzia1 = steady_clock::now();
	cin >> raide;
	auto pabaiga1 = steady_clock::now();
	cin5 = duration_cast<duration<double>>(pabaiga1 - pradzia1);

	auto pradzia2 = steady_clock::now();

	if (raide == 'V' || raide == 'v')
	{
		for (int i = 0; i < dydis; i++)
		{
			if (M[i].average >= 5.0)
			{
				pazenge paz = { M[i].name, M[i].surname, M[i].ndRez, M[i].egzRez, M[i].average, M[i].med };
				P.push_back(paz);
				pDydis++;
			}
			else if (M[i].average < 5.0)
			{
				buki buk = { M[i].name, M[i].surname, M[i].ndRez, M[i].egzRez, M[i].average, M[i].med };
				B.push_back(buk);
				bDydis++;
			}
		}
	}
	else
	{
		for (int i = 0; i < dydis; i++)
		{
			if (M[i].med >= 5.0)
			{
				pazenge paz = { M[i].name, M[i].surname, M[i].ndRez, M[i].egzRez, M[i].average, M[i].med };
				P.push_back(paz);
				pDydis++;
			}
			else if (M[i].med < 5.0)
			{
				buki buk = { M[i].name, M[i].surname, M[i].ndRez, M[i].egzRez, M[i].average, M[i].med };
				B.push_back(buk);
				bDydis++;
			}
		}
	}
	auto pabaiga2 = steady_clock::now();
	laikas2 = duration_cast<duration<double>>(pabaiga2 - pradzia2);

	auto pradzia3 = steady_clock::now();

	FILE* pFile = fopen("pazenge.txt", "w");
	FILE* bFile = fopen("buki.txt", "w");

	if (raide == 'V' || raide == 'v')
	{
		fprintf(pFile, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Vid.)");
		fprintf(pFile, "-----------------------------------------------------------------\n");
		fprintf(bFile, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Vid.)");
		fprintf(bFile, "-----------------------------------------------------------------\n");

		for (int i = 0; i < pDydis; i++)
		{
			fprintf(pFile, "%-15s%-15s%-20.2f\n", P[i].surname.c_str(), P[i].name.c_str(), P[i].average);
		}
		for (int i = 0; i < bDydis; i++)
		{
			fprintf(bFile, "%-15s%-15s%-20.2f\n", B[i].surname.c_str(), B[i].name.c_str(), B[i].average);
		}
	}
	else
	{
		fprintf(pFile, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Vid.)");
		fprintf(pFile, "-----------------------------------------------------------------\n");
		fprintf(bFile, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Vid.)");
		fprintf(bFile, "-----------------------------------------------------------------\n");

		for (int i = 0; i < pDydis; i++)
		{
			fprintf(pFile, "%-15s%-15s%-20.2f\n", P[i].surname.c_str(), P[i].name.c_str(), P[i].med);
		}
		for (int i = 0; i < bDydis; i++)
		{
			fprintf(bFile, "%-15s%-15s%-20.2f\n", B[i].surname.c_str(), B[i].name.c_str(), B[i].med);
		}
	}

	fclose(pFile);
	fclose(bFile);

	auto pabaiga3 = steady_clock::now();
	laikas3 = duration_cast<duration<double>>(pabaiga3 - pradzia3);
}

void spauzdinimasEkrane(vector<mokiniai>& M, int dydis, duration<double>& cin5)
{
	char raide;
	cout << "Ar norite naudoti vidurki ar mediana?" << endl << "Vidurki (V) / Mediana (bet koks kitas zenklas)";
	auto pradzia = steady_clock::now();
	cin >> raide;
	auto pabaiga = steady_clock::now();
	cin5 = duration_cast<duration<double>>(pabaiga - pradzia);

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

void vidurys(vector<mokiniai>& M, int dydis)
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

int skaitymasRanka(vector<mokiniai>& M, int dydis)
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

int skaitymasFailo(vector<mokiniai>& M, int dydis, duration<double>& laikas1, duration<double>& cin4)
{
	string fileV;
	char vardas[100], pav[100], trash[100];
	int sk, test, ndSk = 0;
	int i = 0;

	cout << "Iveskite failo pavadinima, is kurio bus nuskaityti duomenys:" << endl;
	auto pradzia = steady_clock::now();
	cin >> fileV;
	auto pabaiga = steady_clock::now();
	cin4 = duration_cast<duration<double>>(pabaiga - pradzia);

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

void rikiavimas (vector<mokiniai>& M, int dydis, char pasirinkimas)
{
	if (pasirinkimas == 'V' || pasirinkimas == 'v') 
	{
		sort(M.begin(), M.begin() + dydis, [](const mokiniai& a, const mokiniai& b)
			{
				return a.name < b.name;
			});
	}
	else if (pasirinkimas == 'P' || pasirinkimas == 'p') 
	{
		sort(M.begin(), M.begin() + dydis, [](const mokiniai& a, const mokiniai& b)
			{
				return a.surname < b.surname;
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

void duomenuGeneravimas(int kiek, duration<double>& cin2)
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
	auto pradzia = steady_clock::now();
	cin >> fileV;
	auto pabaiga = steady_clock::now();
	cin2 = duration_cast<duration<double>>(pabaiga - pradzia);

	FILE* myFile = fopen(fileV.c_str(), "w");

	fprintf(myFile, "%-26s%-26s", "Vardas", "Pavarde");
	for (int i = 1; i <= ndSkaicius; i++)
	{
		fprintf(myFile, "%s%-8d", "ND", i);
	}
	fprintf(myFile, "%s\n", "Egz.");

	for (int x = 1; x <= DK; x++)
	{
		string name = "Vardas" + to_string(x);
		string surname = "Pavarde" + to_string(x);
		fprintf(myFile, "%-26s%-26s", name.c_str(), surname.c_str());

		for (int j = 1; j <= ndSkaicius; j++)
		{
			uniform_int_distribution<int> pazGen(1, 10);
			int paz = pazGen(gen);
			fprintf(myFile, "%-10d", paz);
		}

		uniform_int_distribution<int> egzGen(1, 10);
		int egz = egzGen(gen);

		fprintf(myFile, "%d\n", egz);
	}

	fclose(myFile);
}

void kiekGeneruoti(duration<double>& cin1, duration<double>& cin2)
{
	char raide;

	cout << "Pasirinkite kiek mokiniu duomenu norite generuoti." << endl << "(1) - 1 000 / (2) - 10 000 / (3) - 100 000 / (4) - 1 000 000 / (bet koks kitas simbolis) - 10 000 000" << endl;
	auto pradzia = steady_clock::now();
	cin >> raide;
	auto pabaiga = steady_clock::now();
	cin1 = duration_cast<duration<double>>(pabaiga - pradzia);
	if (raide == '1')
	{
		duomenuGeneravimas(1, cin2);
	}
	else if (raide == '2')
	{
		duomenuGeneravimas(2, cin2);
	}
	else if (raide == '3')
	{
		duomenuGeneravimas(3, cin2);
	}
	else if (raide == '4')
	{
		duomenuGeneravimas(4, cin2);
	}
	else
	{
		duomenuGeneravimas(5, cin2);
	}
}
