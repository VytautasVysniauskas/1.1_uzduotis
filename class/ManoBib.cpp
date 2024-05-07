/**
 * @file ManoBib.cpp
 * @brief Visos funkcijos darbui su studentu duomenim.
 *
 * Siame faile yra naudojamos funckijos skirtui darbui su studentu duomenimis,
 * kaip generavimas, rusiavimas, skaitymas, spauzdinimas ir t.t.
 */

#include "ManoBib.h"
#include "Bibliotekos.h"

using namespace std;
using namespace std::chrono;

/**
 * @brief Spauzdina studentu rezultatus 2 failuose, pazengusiuju ir bukuju.
 *
 * Sioje funkcijoje galima pasirinkti ar spauzdinti rezultatus pagal vidurki ar mediana.
 * Yra atskiriami studentai su vidurkiu mazesniu ar lygu 5 ir didesniu nei 5.
 *
 * @param M - vektorius kuris laiko studentu data, bus naudojamas kaip pazengusiuju vektorius.
 * @param B - tuscias vektorius, laikys bukiuju rezultatus.
 * @param dydis - laiko kiek studentu is viso yra.
 * @param laikas3 - Skaiciuoja kiek uztrunka duomenu skirtsymas i reikiamus konteinerius.
 */

void spauzdinimasFaile(vector<mokiniai>& M, vector<mokiniai>& B, int dydis, duration<double>& laikas3)
{
	char raide;
	cout << "Ar norite naudoti vidurki ar mediana?" << endl << "Vidurki (V) / Mediana (bet koks kitas zenklas)" << endl;
	cin >> raide;

	auto pradzia3 = steady_clock::now();
	if (raide == 'V' || raide == 'v')
	{
		std::copy_if(M.begin(), M.end(), std::back_inserter(B), [&](const mokiniai& m)
			{
				return m.getAverage() < 5.0 && m.getAverage() > 0.0;
			});

		M.erase(std::remove_if(M.begin(), M.end(), [](const mokiniai& m)
			{
				return m.getAverage() < 5.0;
			}), M.end());
	}
	else
	{
		std::copy_if(M.begin(), M.end(), std::back_inserter(B), [&](const mokiniai& m)
			{
				return m.getMed() < 5.0 && m.getMed() > 0.0;
			});

		M.erase(std::remove_if(M.begin(), M.end(), [](const mokiniai& m)
			{
				return m.getMed() < 5.0;
			}), M.end());
	}
	auto pabaiga3 = steady_clock::now();
	laikas3 = duration_cast<duration<double>>(pabaiga3 - pradzia3);

	FILE* pFile = fopen("pazenge.txt", "w");
	FILE* bFile = fopen("buki.txt", "w");

	if (raide == 'V' || raide == 'v')
	{
		fprintf(pFile, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Vid.)");
		fprintf(pFile, "-----------------------------------------------------------------\n");
		fprintf(bFile, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Vid.)");
		fprintf(bFile, "-----------------------------------------------------------------\n");

		for (const auto& m : M)
		{
			fprintf(pFile, "%-15s%-15s%-20.2f\n", m.getSurname().c_str(), m.getName().c_str(), m.getAverage());
		}
		for (const auto& b : B)
		{
			fprintf(bFile, "%-15s%-15s%-20.2f\n", b.getSurname().c_str(), b.getName().c_str(), b.getAverage());
		}
	}
	else
	{
		fprintf(pFile, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Med.)");
		fprintf(pFile, "-----------------------------------------------------------------\n");
		fprintf(bFile, "%-15s%-15s%-20s\n", "Pavarde", "Vardas", "Galutinis (Med.)");
		fprintf(bFile, "-----------------------------------------------------------------\n");

		for (const auto& m : M)
		{
			fprintf(pFile, "%-15s%-15s%-20.2f\n", m.getSurname().c_str(), m.getName().c_str(), m.getMed());
		}
		for (const auto& b : B)
		{
			fprintf(bFile, "%-15s%-15s%-20.2f\n", b.getSurname().c_str(), b.getName().c_str(), b.getMed());
		}
	}

	fclose(pFile);
	fclose(bFile);
}

/**
 * @brief Spausdina studentu duomenis ekrane.
 *
 * Si funkcija spausdina rezultatus i ekrana.
 * Kadandgi duomenu negalima aiskiai atskirti, ypac naudojant ju itin daug,
 * jie visi yra spauzdinami bendrai.
 *
 * @param M - Vektorius kuris saugo visus studentu duomenis.
 * @param dydis - Studentu duomenu kiekis.
 */

void spauzdinimasEkrane(vector<mokiniai>& M, int dydis)
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
			cout << M[i] << M[i].getAverage() << endl;
		}
	}
	else
	{
		cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)\n";
		cout << "-----------------------------------------------------------------" << endl;
		for (int i = 0; i < dydis; i++)
		{
			cout << M[i] << M[i].getMed() << endl;
		}
	}
}

/**
 * @brief Funkcija kuri suskaiciuoja mediana.
 *
 * Si funkcija randa viduri tarp studento namu darbu rezultatu ir
 * tuomet tokiu budu randa mediana.
 *
 * @param M - Vektorius kuris saugo visus studento duomenis.
 * @param dydis - Duomenu kiekis.
 */

void vidurys(vector<mokiniai>& M, int dydis)
{
	for (int i = 0; i < dydis; i++)
	{
		if (!M[i].getNdRez().empty())
		{
			vector<int> ndRezCopy = M[i].getNdRez();
			sort(ndRezCopy.begin(), ndRezCopy.end());

			size_t ndDydis = ndRezCopy.size();

			if (ndDydis % 2 == 0)
			{
				double vidurys1 = static_cast<double>(ndRezCopy[ndDydis / 2]);
				double vidurys2 = static_cast<double>(ndRezCopy[ndDydis / 2 - 1]);
				M[i].setMed(vidurys1, vidurys2);
			}
			else
			{
				double vidurys = static_cast<double>(ndRezCopy[ndDydis / 2]);
				M[i].setMed(vidurys);
			}
		}
	}
}

/**
 * @brief Skaito studenta data kuri yra irasyta ranka.
 *
 * Sioje funkcijoje yra prasomo naudotojo yrasyti duomenis ranka,
 * jie gali pasirinkti ar rasyti trumpesne versija (su mediana ir vidurkiu zinomu)
 * ar ilegense (su namu darbu rezultatais vieotoj vidurkio ir medianos)
 *
 * @param M - Vektorius kuris laiko visus studentu duomenis.
 * @param dydis - Studentu kiekis.
 * @return - Grazina irasytu studentu kieki tolimensiui darbui.
 */

int skaitymasRanka(vector<mokiniai>& M, int dydis)
{
	string vardas, pav;
	double sk, test;
	int i = 0;
	char raide;

	cout << "Ar zinote mokiniu vidurki bei mediana?\n(T) - taip / (bet koks kitas zenklas) - ne" << endl;
	cin >> raide;

	if (raide == 'T' || raide == 't')
	{
		while (1)
		{
			cin.ignore();
			mokiniai mokinys;
			cout << "Iveskite mokinio duomenys (pavarde, varda, vidurki, mediana)" << endl;
			cin >> mokinys;

			M[i] = mokinys;

			cout << "Ar norite baigti mokiniu rasyma?\n(T) - taip / (bet koks kitas zenklas) - ne" << endl;
			cin >> raide;
			if (raide == 'T' || raide == 't')
			{
				break;
			}
			i++;
		}
		i++;
	}
	else
	{
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

			M[i].setName(vardas);
			M[i].setSurname(pav);

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
				M[i].setNdRez(sk);
			}

			while (1)
			{
				try
				{
					cout << "Irasykite mokinio egzamino rezultata:" << endl;
					cin >> test;

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
			M[i].setEgzRez(test);


			if (M[i].getNdRez().size() > 0)
			{
				x = x / M[i].getNdRez().size();
				M[i].setAverage(x, test);
			}

			i++;
		}
	}

	dydis = i;
	return dydis;
}

/**
 * @brief Rikiuoja studentu duomenis.
 *
 * Sioje funkcijoje yra rikiuojami duomenis pagal naudotojo pasirinkima:
 * vardus, pavardes, vidurki, mediana.
 *
 * @param M - Vektorius laikantis visus studentu duomenis.
 * @param dydis - Studentu kiekis.
 * @param pasirinkimas - Vartotojo rikiavimo pasirinkimas.
 */

void rikiavimas(vector<mokiniai>& M, int dydis, char pasirinkimas)
{
	if (pasirinkimas == 'V' || pasirinkimas == 'v')
	{
		sort(M.begin(), M.begin() + dydis, [](const mokiniai& a, const mokiniai& b)
			{
				return a.getName() < b.getName();
			});
	}
	else if (pasirinkimas == 'P' || pasirinkimas == 'p')
	{
		sort(M.begin(), M.begin() + dydis, [](const mokiniai& a, const mokiniai& b)
			{
				return a.getSurname() < b.getSurname();
			});
	}
	else if (pasirinkimas == 'A' || pasirinkimas == 'a')
	{
		sort(M.begin(), M.begin() + dydis, [](const mokiniai& a, const mokiniai& b)
			{
				return a.getAverage() > b.getAverage();
			});
	}
	else
	{
		sort(M.begin(), M.begin() + dydis, [](const mokiniai& a, const mokiniai& b)
			{
				return a.getMed() > b.getMed();
			});
	}
}

/**
 * @brief Skaito studentu duomenis is failo.
 *
 * Sioje funkcijoje duomenys yra skaitomi is failo ir dedami i vektoriu tolimesniam naudojimui.
 *
 * @param M - Vektorius kuris laikys visus studentu duomenis.
 * @param dydis - Studentu kiekis.
 * @param laikas1 - Matuojamas laikas kiek uztrunka failo skaitymas.
 * @return - Grazinamas studentu kiekis tolimesniam darbui.
 */

int skaitymasFailo(vector<mokiniai>& M, int dydis, duration<double>& laikas1)
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
		M[i].setName(vardas);
		M[i].setSurname(pav);

		double x = 0.0;

		for (int j = 0; j < ndSk; j++)
		{
			fscanf(myFile, "%d", &sk);
			x = x + sk;
			M[i].setNdRez(sk);
		}
		fscanf(myFile, "%d", &test);
		M[i].setEgzRez(test);
		if (ndSk > 0)
		{
			x = x / ndSk;
			M[i].setAverage(x, test);
		}
		i++;
	}
	auto pabaiga1 = steady_clock::now();
	laikas1 = duration_cast<duration<double>>(pabaiga1 - pradzia1);

	fclose(myFile);

	dydis = i;
	return dydis;
}

/**
 * @brief Generuoja duomenis i faila.
 *
 * Si funkcija generuoja pasirinktina duomenu skaiciu ir juos iraso i faila.
 *
 * @param - Vartotojo pasirinkimas kiek duomenu norima generuoti.
 */

void duomenuGeneravimas(int kiek)
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

/**
 * @brief Prasomo vartotojo pateikti kiek duomenu norima generuoti.
 * 
 * Sioje funkcijoje vartotojas turi 5 pasirinkimus generuojant duomenis:
 * 1 000, 10 000, 100 000, 1 000 000 ir 10 000 000.
 * 
 */

void kiekGeneruoti()
{
	char raide;

	cout << "Pasirinkite kiek mokiniu duomenu norite generuoti." << endl << "(1) - 1 000 / (2) - 10 000 / (3) - 100 000 / (4) - 1 000 000 / (bet koks kitas simbolis) - 10 000 000" << endl;
	cin >> raide;
	if (raide == '1')
	{
		duomenuGeneravimas(1);
	}
	else if (raide == '2')
	{
		duomenuGeneravimas(2);
	}
	else if (raide == '3')
	{
		duomenuGeneravimas(3);
	}
	else if (raide == '4')
	{
		duomenuGeneravimas(4);
	}
	else
	{
		duomenuGeneravimas(5);
	}
}