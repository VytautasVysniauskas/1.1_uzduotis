#include "ManoBibL.h"
#include "BibliotekosL.h"
using namespace std;
using namespace std::chrono;

void spauzdinimasFaile(list<mokiniai>& M, int dydis)
{
	string rFailasPav;
	cout << "Iveskite failo pavadinima, kuriame bus isvedami rezultatai." << endl;
	cin >> rFailasPav;

	FILE* rFailas = fopen(rFailasPav.c_str(), "w");

	char raide;
	cout << "Ar norite naudoti vidurki ar mediana?" << endl << "Vidurki (V) / Mediana (bet koks kitas zenklas)" << endl;
	cin >> raide;

	if (raide == 'V' || raide == 'v')
	{
		fprintf(rFailas, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Vid.)");
		fprintf(rFailas, "-----------------------------------------------------------------\n");

		for (auto it = M.begin(); it != M.end() && dydis > 0; ++it)
		{
			auto& mok = *it;
			if (!mok.ndRez.empty())
			{
				fprintf(rFailas, "%-15s%-15s%-20.2f\n", mok.surname.c_str(), mok.name.c_str(), mok.average);
				dydis--; 
			}
		}
	}
	else
	{
		fprintf(rFailas, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Med.)");
		fprintf(rFailas, "-----------------------------------------------------------------\n");

		for (auto it = M.begin(); it != M.end() && dydis > 0; ++it)
		{
			auto& mok = *it;
			if (!mok.ndRez.empty()) 
			{
				fprintf(rFailas, "%-15s%-15s%-20.2f\n", mok.surname.c_str(), mok.name.c_str(), mok.med);
				dydis--;
			}
		}
	}

	cout << "Rezultatai isvesti faile: " << rFailasPav << endl;
	fclose(rFailas);
}

void spauzdinimasEkrane(list<mokiniai>& M, int dydis)
{
	char raide;
	cout << "Ar norite naudoti vidurki ar mediana?" << endl << "Vidurki (V) / Mediana (bet koks kitas zenklas)";
	cin >> raide;

	if (raide == 'V' || raide == 'v')
	{
		cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)\n";
		cout << "-----------------------------------------------------------------" << endl;
		for(auto& mok : M)
		{
			cout << setw(15) << left << mok.surname << setw(15) << left << mok.name << setw(20) << left << fixed << std::setprecision(2) << mok.average << endl;
		}
	}
	else
	{
		cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)\n";
		cout << "-----------------------------------------------------------------" << endl;
		for(auto& mok : M)
		{
			cout << setw(15) << left << mok.surname << setw(15) << left << mok.name << setw(20) << left << fixed << std::setprecision(2) << mok.med << endl;
		}
	}
}

void vidurys(list<mokiniai>& M, int dydis)
{
	for (auto& mok : M)
	{
		mok.ndRez.sort();

		size_t ndDydis = mok.ndRez.size();
		auto it = mok.ndRez.begin();
		advance(it, ndDydis / 2);

		if (ndDydis % 2 == 0)
		{
			double vidurys1 = static_cast<double>(*it);
			double vidurys2 = static_cast<double>(*prev(it));
			mok.med = (vidurys1 + vidurys2) / 2;
		}
		else
		{
			mok.med = static_cast<double>(*it);
		}
	}
}

int skaitymasRanka(list<mokiniai>& M, int dydis)
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

		M.push_back({ vardas, pav, {}, 0, 0.0, 0.0 });

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
			M.back().ndRez.push_back(sk);
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
		M.back().egzRez = sk;

		if (!M.back().ndRez.empty())
		{
			x = x / M.back().ndRez.size();
			M.back().average = 0.4 * x + 0.6 * test;
		}

		i++;
	}

	dydis = i;
	return dydis;
}

int skaitymasFailo(list<mokiniai>& M, int dydis, duration<double>& laikas1)
{
	string fileV;
	char vardas[100], pav[100], trash[100];
	int sk, test, ndSk = 0, i = 0;

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

		mokiniai temp;
		temp.name = vardas;
		temp.surname = pav;

		double x = 0.0;

		for (int j = 0; j < ndSk; j++)
		{
			fscanf(myFile, "%d", &sk);
			x = x + sk;
			temp.ndRez.push_back(sk);
		}
		fscanf(myFile, "%d", &test);
		temp.egzRez = test;
		if (ndSk > 0)
		{
			x = x / ndSk;
			temp.average = 0.4 * x + 0.6 * test;
		}
		M.push_back(temp);
		i++;
	}
	auto pabaiga1 = steady_clock::now();
	laikas1 = duration_cast<duration<double>>(pabaiga1 - pradzia1);

	fclose(myFile);

	dydis = i;
	return dydis;
}

void rikiavimas(list<mokiniai>& M, int dydis, char pasirinkimas)
{
	if (pasirinkimas == 'V' || pasirinkimas == 'v')
	{
		M.sort([](const mokiniai&a, const mokiniai& b)
			{
				return a.name < b.name;
			});
	}
	else if (pasirinkimas == 'P' || pasirinkimas == 'p')
	{
		M.sort([](const mokiniai & a, const mokiniai & b)
			{
				return a.surname < b.surname;
			});
	}
	else if (pasirinkimas == 'A' || pasirinkimas == 'a')
	{
		M.sort([](const mokiniai & a, const mokiniai & b)
			{
				return a.average > b.average;
			});
	}
	else
	{
		M.sort([](const mokiniai & a, const mokiniai & b)
			{
				return a.med > b.med;
			});
	}
}

void pazangusIrBuki (list<mokiniai>& M, list<mokiniai>& B, int dydis, duration<double>& laikas2, duration<double>& laikas3)
{
	char raide;
	cout << "Pasirinkite pagal ka norite surusiuoti pazengusiuju ir buku rezultatus (Mazejimo tvarka arba abaceles didejimo)" << endl << "Vardus (V) / Pavardes (P) / Gal. Vidurki (A) / Gal. Mediana (bet koks kitas zenklas)" << endl;
	cin >> raide;

	auto pradzia2 = steady_clock::now();
	rikiavimas(M, dydis, raide);
	auto pabaiga2 = steady_clock::now();
	laikas2 = duration_cast<duration<double>>(pabaiga2 - pradzia2);

	auto pradzia3 = steady_clock::now();
	std::copy_if(M.begin(), M.end(), std::back_inserter(B), [&](const mokiniai& m) 
	{
		return m.average < 5.0 && m.average > 0.0;
	});

	M.remove_if([](const mokiniai& m) 
	{
		return m.average < 5.0;
	});
	auto pabaiga3 = steady_clock::now();
	laikas3 = duration_cast<duration<double>>(pabaiga3 - pradzia3);

	FILE* pFile = fopen("pazenge.txt", "w");
	FILE* bFile = fopen("buki.txt", "w");

	fprintf(pFile, "%-26s%-26s", "Vardas", "Pavarde");
	int ndSize = 0;
	for (const auto& student : B) 
	{
		int currentSize = student.ndRez.size();
		if (currentSize > ndSize) {
			ndSize = currentSize;
		}
	}
	for (int i = 1; i <= ndSize; i++)
	{
		fprintf(pFile, "%s%-8d", "ND", i);
	}
	fprintf(pFile, "%s\n", "Egz.");

	fprintf(bFile, "%-26s%-26s", "Vardas", "Pavarde");
	for (int i = 1; i <= ndSize; i++)
	{
		fprintf(bFile, "%s%-8d", "ND", i);
	}
	fprintf(bFile, "%s\n", "Egz.");

	for (auto& paz : M)
	{
		if (!paz.ndRez.empty() && paz.average >= 5.0)
		{
			fprintf(pFile, "%-26s%-26s", paz.name.c_str(), paz.surname.c_str());

			for (int rez : paz.ndRez)
			{
				fprintf(pFile, "%-10d", rez);
			}
			fprintf(pFile, "%d\n", paz.egzRez);
		}
	}

	for (auto& buk : B)
	{
		if (!buk.ndRez.empty())
		{
			fprintf(bFile, "%-26s%-26s", buk.name.c_str(), buk.surname.c_str());

			for (int rez : buk.ndRez)
			{
				fprintf(bFile, "%-10d", rez);
			}
			fprintf(bFile, "%d\n", buk.egzRez);
		}
	}

	fclose(pFile);
	fclose(bFile);
}

int duomenuGeneravimas(list<mokiniai>& M, int kiek)
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

	int x = 1;
	for (auto it = M.begin(); x <= DK; ++x, ++it)
	{
		mt19937 gen(rd());
		int sk = 0;

		it->name = "Vardas" + to_string(x);
		it->surname = "Pavarde" + to_string(x);
		fprintf(myFile, "%-26s%-26s", it->name.c_str(), it->surname.c_str());
		for (int j = 1; j <= ndSkaicius; j++)
		{
			uniform_int_distribution<int> pazGen(1, 10);
			it->ndRez.push_back(pazGen(gen));
			fprintf(myFile, "%-10d",it->ndRez.back());

			sk = sk +it->ndRez.back();
		}
		uniform_int_distribution<int> egzGen(1, 10);
		it->egzRez = egzGen(gen);
		fprintf(myFile, "%d\n", it->egzRez);
		int testT = it->egzRez;

		it->average = (0.4 * sk / ndSkaicius) + (0.6 * testT);
	}

	fclose(myFile);
	return DK;
}

int kiekGeneruoti(list<mokiniai>& M, int dydis)
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
