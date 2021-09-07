#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Samochody {
public:
	int id;
	string marka;
	string model;
	int rocznik;
	char klasa;
	string kolor;
	int cena;
	int przebieg;
	bool deluxe;
	bool wyp;
	Samochody(int id = 0, string mar = "", string mod = "", int r = 0, char klasa = 0, string kolor = "", int cena = 0, int przebieg = 0, bool deluxe = 0, bool wyp = 0) {
		this->id = id;
		this->marka = mar;
		this->model = mod;
		this->rocznik = r;
		this->klasa = klasa;
		this->kolor = kolor;
		this->cena = cena;
		this->przebieg = przebieg;
		this->deluxe = deluxe;
		this->wyp = wyp;
	}
	virtual void tworz_A() {};
	virtual void tworz_B() {};
	virtual void tworz_C() {};
	virtual void tworz_D() {};
	void wypisz() {
		vector <Samochody*> obiekty;
		ifstream wej("baza_samochody.txt", std::ifstream::in);
		string deluxe;
		string wyp;
		string tab_nag[10] = { "ID","MARKA","MODEL","ROCZNIK","KLASA","KOLOR","CENA","PRZEBIEG","DELUXE","WYPOZYCZONY" };
		int tab_cyfr[10] = { 3, 13, 17, 7, 7, 10, 7, 8, 6, 6 };
		bool _deluxe;
		bool _wyp;
		while (!wej.eof()) {
			wej >> id >> marka >> model >> rocznik >> klasa >> kolor >> cena >> przebieg >> deluxe >> wyp;
			if (deluxe == "tak")
				_deluxe = 1;
			else
				_deluxe = 0;

			if (wyp == "tak")
				_wyp = 1;
			else
				_wyp = 0;

			obiekty.push_back(new Samochody(id, marka, model, rocznik, klasa, kolor, cena, przebieg, _deluxe, _wyp));
		}
		wej.close();
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		for (int i = 0; i < 10; i++) {
			cout << "| " << setfill(' ') << setw(++tab_cyfr[i]) << left << tab_nag[i];
		}
		cout << "|" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		for (int i = 0; i < obiekty.size(); i++) {
			cout << "| " << setfill(' ') << setw(3) << left << obiekty[i]->id << " | " << setfill(' ') << setw(13) << left << obiekty[i]->marka << " | " << setfill(' ') << setw(17) << left << obiekty[i]->model << " | " << setfill(' ') << setw(7) << left << obiekty[i]->rocznik << " | " << setfill(' ') << setw(7) << left << obiekty[i]->klasa << " | " << setfill(' ') << setw(10) << left << obiekty[i]->kolor << " | " << setfill(' ') << setw(7) << left << obiekty[i]->cena << " | " << setfill(' ') << setw(8) << left << obiekty[i]->przebieg << " | " << setfill(' ') << setw(6) << left << obiekty[i]->deluxe << " | " << setfill(' ') << setw(10) << left << obiekty[i]->wyp << " |" << endl;
			cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		}

	}

	int findCar(vector<string> tab)
	{
		string marka;
		string model;
		string rocznik;
		string klasa;
		string kolor;
		string cena;
		string przebieg;
		string delux;
		string wyp;
		int id;
		ifstream fs;
		fs.open("baza_samochody.txt", std::ifstream::in);
		while (!fs.eof())
		{
			fs >> id >> marka >> model >> rocznik >> klasa >> kolor >> cena >> przebieg >> delux >> wyp;
			if (tab[0] == marka && tab[1] == model && tab[2] == rocznik && tab[3] == klasa && tab[4] == kolor && tab[6] == przebieg)
			{
				fs.close();
				return id;
			}
		}
		fs.close();
		return 0;
	}
	void RemoveCarBase(int choice)
	{
		vector<vector<string> > tab;
		ifstream fs;

		string marka;
		string model;
		string rocznik;
		string klasa;
		string kolor;
		string cena;
		int id = 0;
		string przebieg;
		string delux;
		string wyp;
		vector<string> row;
		fs.open("baza_samochody.txt", ifstream::in);
		while (!fs.eof())
		{
			fs >> id >> marka >> model >> rocznik >> klasa >> kolor >> cena >> przebieg >> delux >> wyp;

			if (id != choice)
			{
				row.push_back(marka);
				row.push_back(model);
				row.push_back(rocznik);
				row.push_back(klasa);
				row.push_back(kolor);
				row.push_back(cena);
				row.push_back(przebieg);
				row.push_back(delux);
				row.push_back(wyp);
				tab.push_back(row);
			}
			row.clear();
		}
		fs.close();

		ofstream fss;
		fss.open("baza_samochody.txt", ofstream::out | ofstream::trunc);
		for (int i = 0; i < tab.size(); i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (j == 0)
					fss << i + 1 << " " << tab[i][j] << " ";
				else if (j != 8 && j != 0)
					fss << tab[i][j] << " ";
				else if (j == 8)
					fss << tab[i][j];
			}
			if (i != tab.size() - 1)
				fss << endl;
		}
		fss.close();

		tab.clear();
	}

	void AddCarBase(int choice, string currentUser)
	{
		int id;
		string marka;
		string model;
		string rocznik;
		string klasa;
		string kolor;
		string cena;
		string przebieg;
		string delux;
		string wyp;

		ifstream fs;
		fs.open("baza_samochody.txt", ios::out | ios::app);
		while (!fs.eof())
		{
			fs >> id >> marka >> model >> rocznik >> klasa >> kolor >> cena >> przebieg >> delux >> wyp;
		}
		fs.close();
		vector<string> tab;
		int counter = 0;

		ifstream wej("Users/" + currentUser + "/status.txt", std::ifstream::in);

		while (!wej.eof())
		{
			counter++;
			wej >> marka >> model >> rocznik >> klasa >> kolor >> cena >> przebieg >> delux;
			if (choice == counter)
			{
				tab.push_back(marka);
				tab.push_back(model);
				tab.push_back(rocznik);
				tab.push_back(klasa);
				tab.push_back(kolor);
				tab.push_back(cena);
				tab.push_back(przebieg);
				tab.push_back(delux);
				tab.push_back("nie");
			}
		}
		wej.close();

		ofstream wyj;
		wyj.open("baza_samochody.txt", ios::out | ios::app);

		wyj << endl;
		wyj << id + 1 << " ";
		for (int i = 0; i < 9; i++)
		{
			if (i != 8)
				wyj << tab[i] << " ";
			else
				wyj << tab[i];
		}

		wyj.close();
	}
	~Samochody() {};
};


class Class_A : public Samochody {
public:
	vector <Class_A*> obiekty_A;
	Class_A(int id = 0, string mar = "", string mod = "", int r = 0, char klasa = 0, string kolor = "", int cena = 0, int przebieg = 0, bool deluxe = 0, bool wyp = 0) : Samochody(id, mar, mod, r, klasa, kolor, cena, przebieg, deluxe, wyp) {};
	virtual void tworz_A() {
		ifstream wejscie("baza_samochody.txt", std::ifstream::in);
		ofstream wyjscie("baza_A.txt", std::ofstream::out | std::ofstream::trunc);
		int id = 1;
		string _id;
		string marka;
		string model;
		string rocznik;
		string klasa;
		string kolor;
		string cena;
		string przebieg;
		string deluxe;
		string wyp;
		//Tworzenie tablicy wskaznikow

		while (!wejscie.eof()) {
			wejscie >> _id >> marka >> model >> rocznik >> klasa >> kolor >> cena >> przebieg >> deluxe >> wyp;

			if (klasa == "A")
			{
				wyjscie << id << " " << marka << " " << model << " " << rocznik << " " << klasa << " " << kolor << " " << cena << " " << przebieg << " " << deluxe << " " << wyp << endl;
				id++;
			}

		}
		wejscie.close();
		wyjscie.close();


		ifstream wej("baza_A.txt", std::ifstream::in);
		string tab_nag[10] = { "ID","MARKA","MODEL","ROCZNIK","KLASA","KOLOR","CENA","PRZEBIEG","DELUXE","WYPOZYCZONY" };
		int tab_cyfr[10] = { 3, 13, 17, 7, 7, 10, 7, 8, 6, 6 };
		bool _deluxe;
		bool _wyp;
		char c_klasa;
		while (!wej.eof()) {
			wej >> id >> marka >> model >> rocznik >> klasa >> kolor >> cena >> przebieg >> deluxe >> wyp;
			if (deluxe == "tak")
				_deluxe = 1;
			else
				_deluxe = 0;

			if (wyp == "tak")
				_wyp = 1;
			else
				_wyp = 0;

			c_klasa = klasa[0];
			obiekty_A.push_back(new Class_A(id, marka, model, std::stoi(rocznik), c_klasa, kolor, std::stoi(cena), std::stoi(przebieg), _deluxe, _wyp));
		}
		wej.close();
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		for (int i = 0; i < 10; i++) {
			cout << "| " << setfill(' ') << setw(++tab_cyfr[i]) << left << tab_nag[i];
		}
		cout << "|" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		for (int i = 0; i < obiekty_A.size() - 1; i++) {
			cout << "| " << setfill(' ') << setw(3) << left << obiekty_A[i]->id << " | " << setfill(' ') << setw(13) << left << obiekty_A[i]->marka << " | " << setfill(' ') << setw(17) << left << obiekty_A[i]->model << " | " << setfill(' ') << setw(7) << left << obiekty_A[i]->rocznik << " | " << setfill(' ') << setw(7) << left << obiekty_A[i]->klasa << " | " << setfill(' ') << setw(10) << left << obiekty_A[i]->kolor << " | " << setfill(' ') << setw(7) << left << obiekty_A[i]->cena << " | " << setfill(' ') << setw(8) << left << obiekty_A[i]->przebieg << " | " << setfill(' ') << setw(6) << left << obiekty_A[i]->deluxe << " | " << setfill(' ') << setw(10) << left << obiekty_A[i]->wyp << " |" << endl;
			cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		}
	}

	virtual void wybierz_A(int m) {
		cout << obiekty_A[m - 1]->id << " " << obiekty_A[m - 1]->marka << " " << obiekty_A[m - 1]->model << " " << obiekty_A[m - 1]->rocznik << " " << obiekty_A[m - 1]->klasa << " " << obiekty_A[m - 1]->cena << " " << obiekty_A[m - 1]->przebieg << " " << obiekty_A[m - 1]->deluxe << " " << obiekty_A[m - 1]->wyp << endl;
	}

	string zwroc_marka(int m) {
		return obiekty_A[m - 1]->marka;
	}
	string zwroc_model(int m) {
		return obiekty_A[m - 1]->model;
	}
	string zwroc_rocznik(int m) {
		int rok = obiekty_A[m - 1]->rocznik;
		string rocznik = to_string(rok);
		return rocznik;
	}
	string zwroc_klase(int m) {
		char kl = obiekty_A[m - 1]->klasa;
		string klas;
		klas.append(1, kl);
		return klas;
	}
	string cena_deluxe(int m) {
		int cena = obiekty_A[m - 1]->cena;
		cena = (cena * 11);
		string cen = to_string(cena);
		return cen;
	}
	string cena_standard(int m) {
		int cena = obiekty_A[m - 1]->cena;
		string cen = to_string(cena);
		return cen;
	}
	string zwroc_przebieg(int m) {
		int przebieg = obiekty_A[m - 1]->przebieg;
		string przeb = to_string(przebieg);
		return przeb;
	}
	string zwroc_kolor(int m) {
		return obiekty_A[m - 1]->kolor;
	}
};

class Class_B : public Samochody {
public:
	vector <Class_B*> obiekty_B;
	Class_B(int id = 0, string mar = "", string mod = "", int r = 0, char klasa = 0, string kolor = "", int cena = 0, int przebieg = 0, bool deluxe = 0, bool wyp = 0) : Samochody(id, mar, mod, r, klasa, kolor, cena, przebieg, deluxe, wyp) {};
	virtual void tworz_B() {
		ifstream wejscie("baza_samochody.txt", std::ifstream::in);
		ofstream wyjscie("baza_B.txt", std::ofstream::out | std::ofstream::trunc);
		int id = 1;
		string _id;
		string marka;
		string model;
		string rocznik;
		string klasa;
		string kolor;
		string cena;
		string przebieg;
		string deluxe;
		string wyp;
		//Tworzenie tablicy wskaznikow
		while (!wejscie.eof()) {
			wejscie >> _id >> marka >> model >> rocznik >> klasa >> kolor >> cena >> przebieg >> deluxe >> wyp;

			if (klasa == "B")
			{
				wyjscie << id << " " << marka << " " << model << " " << rocznik << " " << klasa << " " << kolor << " " << cena << " " << przebieg << " " << deluxe << " " << wyp << endl;
				id++;
			}

		}
		wejscie.close();
		wyjscie.close();

		ifstream wej("baza_B.txt", std::ifstream::in);
		string tab_nag[10] = { "ID","MARKA","MODEL","ROCZNIK","KLASA","KOLOR","CENA","PRZEBIEG","DELUXE","WYPOZYCZONY" };
		int tab_cyfr[10] = { 3, 13, 17, 7, 7, 10, 7, 8, 6, 6 };
		bool _deluxe;
		bool _wyp;
		char c_klasa;
		while (!wej.eof()) {
			wej >> id >> marka >> model >> rocznik >> klasa >> kolor >> cena >> przebieg >> deluxe >> wyp;
			if (deluxe == "tak")
				_deluxe = 1;
			else
				_deluxe = 0;

			if (wyp == "tak")
				_wyp = 1;
			else
				_wyp = 0;

			c_klasa = klasa[0];
			obiekty_B.push_back(new Class_B(id, marka, model, std::stoi(rocznik), c_klasa, kolor, std::stoi(cena), std::stoi(przebieg), _deluxe, _wyp));
		}
		wej.close();
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		for (int i = 0; i < 10; i++) {
			cout << "| " << setfill(' ') << setw(++tab_cyfr[i]) << left << tab_nag[i];
		}
		cout << "|" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		for (int i = 0; i < obiekty_B.size() - 1; i++) {
			cout << "| " << setfill(' ') << setw(3) << left << obiekty_B[i]->id << " | " << setfill(' ') << setw(13) << left << obiekty_B[i]->marka << " | " << setfill(' ') << setw(17) << left << obiekty_B[i]->model << " | " << setfill(' ') << setw(7) << left << obiekty_B[i]->rocznik << " | " << setfill(' ') << setw(7) << left << obiekty_B[i]->klasa << " | " << setfill(' ') << setw(10) << left << obiekty_B[i]->kolor << " | " << setfill(' ') << setw(7) << left << obiekty_B[i]->cena << " | " << setfill(' ') << setw(8) << left << obiekty_B[i]->przebieg << " | " << setfill(' ') << setw(6) << left << obiekty_B[i]->deluxe << " | " << setfill(' ') << setw(10) << left << obiekty_B[i]->wyp << " |" << endl;
			cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		}
	}
	virtual void wybierz_B(int m) {
		cout << obiekty_B[m - 1]->id << " " << obiekty_B[m - 1]->marka << " " << obiekty_B[m - 1]->model << " " << obiekty_B[m - 1]->rocznik << " " << obiekty_B[m - 1]->klasa << " " << obiekty_B[m - 1]->cena << " " << obiekty_B[m - 1]->przebieg << " " << obiekty_B[m - 1]->deluxe << " " << obiekty_B[m - 1]->wyp << endl;
	}
	string zwroc_marka(int m) {
		return obiekty_B[m - 1]->marka;
	}
	string zwroc_model(int m) {
		return obiekty_B[m - 1]->model;
	}
	string zwroc_rocznik(int m) {
		int rok = obiekty_B[m - 1]->rocznik;
		string rocznik = to_string(rok);
		return rocznik;
	}
	string zwroc_klase(int m) {
		char kl = obiekty_B[m - 1]->klasa;
		string klas;
		klas.append(1, kl);
		return klas;
	}
	string cena_deluxe(int m) {
		int cena = obiekty_B[m - 1]->cena;
		cena = (cena * 11);
		string cen = to_string(cena);
		return cen;
	}
	string cena_standard(int m) {
		int cena = obiekty_B[m - 1]->cena;
		string cen = to_string(cena);
		return cen;
	}
	string zwroc_przebieg(int m) {
		int przebieg = obiekty_B[m - 1]->przebieg;
		string przeb = to_string(przebieg);
		return przeb;
	}
	string zwroc_kolor(int m) {
		return obiekty_B[m - 1]->kolor;
	}
};

class Class_C : public Samochody {
public:
	vector <Class_C*> obiekty_C;
	Class_C(int id = 0, string mar = "", string mod = "", int r = 0, char klasa = 0, string kolor = "", int cena = 0, int przebieg = 0, bool deluxe = 0, bool wyp = 0) : Samochody(id, mar, mod, r, klasa, kolor, cena, przebieg, deluxe, wyp) {};
	virtual void tworz_C() {
		ifstream wejscie("baza_samochody.txt", std::ifstream::in);
		ofstream wyjscie("baza_C.txt", std::ofstream::out | std::ofstream::trunc);
		int id = 1;
		string _id;
		string marka;
		string model;
		string rocznik;
		string klasa;
		string kolor;
		string cena;
		string przebieg;
		string deluxe;
		string wyp;
		//Tworzenie tablicy wskaznikow
		while (!wejscie.eof()) {
			wejscie >> _id >> marka >> model >> rocznik >> klasa >> kolor >> cena >> przebieg >> deluxe >> wyp;

			if (klasa == "C")
			{
				wyjscie << id << " " << marka << " " << model << " " << rocznik << " " << klasa << " " << kolor << " " << cena << " " << przebieg << " " << deluxe << " " << wyp << endl;
				id++;
			}

		}
		wejscie.close();
		wyjscie.close();

		ifstream wej("baza_C.txt", std::ifstream::in);
		string tab_nag[10] = { "ID","MARKA","MODEL","ROCZNIK","KLASA","KOLOR","CENA","PRZEBIEG","DELUXE","WYPOZYCZONY" };
		int tab_cyfr[10] = { 3, 13, 17, 7, 7, 10, 7, 8, 6, 6 };
		bool _deluxe;
		bool _wyp;
		char c_klasa;
		while (!wej.eof()) {
			wej >> id >> marka >> model >> rocznik >> klasa >> kolor >> cena >> przebieg >> deluxe >> wyp;
			if (deluxe == "tak")
				_deluxe = 1;
			else
				_deluxe = 0;

			if (wyp == "tak")
				_wyp = 1;
			else
				_wyp = 0;

			c_klasa = klasa[0];
			obiekty_C.push_back(new Class_C(id, marka, model, std::stoi(rocznik), c_klasa, kolor, std::stoi(cena), std::stoi(przebieg), _deluxe, _wyp));
		}
		wej.close();
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		for (int i = 0; i < 10; i++) {
			cout << "| " << setfill(' ') << setw(++tab_cyfr[i]) << left << tab_nag[i];
		}
		cout << "|" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		for (int i = 0; i < obiekty_C.size() - 1; i++) {
			cout << "| " << setfill(' ') << setw(3) << left << obiekty_C[i]->id << " | " << setfill(' ') << setw(13) << left << obiekty_C[i]->marka << " | " << setfill(' ') << setw(17) << left << obiekty_C[i]->model << " | " << setfill(' ') << setw(7) << left << obiekty_C[i]->rocznik << " | " << setfill(' ') << setw(7) << left << obiekty_C[i]->klasa << " | " << setfill(' ') << setw(10) << left << obiekty_C[i]->kolor << " | " << setfill(' ') << setw(7) << left << obiekty_C[i]->cena << " | " << setfill(' ') << setw(8) << left << obiekty_C[i]->przebieg << " | " << setfill(' ') << setw(6) << left << obiekty_C[i]->deluxe << " | " << setfill(' ') << setw(10) << left << obiekty_C[i]->wyp << " |" << endl;
			cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		}
	}
	virtual void wybierz_C(int m) {
		cout << obiekty_C[m - 1]->id << " " << obiekty_C[m - 1]->marka << " " << obiekty_C[m - 1]->model << " " << obiekty_C[m - 1]->rocznik << " " << obiekty_C[m - 1]->klasa << " " << obiekty_C[m - 1]->cena << " " << obiekty_C[m - 1]->przebieg << " " << obiekty_C[m - 1]->deluxe << " " << obiekty_C[m - 1]->wyp << endl;
	}
	string zwroc_marka(int m) {
		return obiekty_C[m - 1]->marka;
	}
	string zwroc_model(int m) {
		return obiekty_C[m - 1]->model;
	}
	string zwroc_rocznik(int m) {
		int rok = obiekty_C[m - 1]->rocznik;
		string rocznik = to_string(rok);
		return rocznik;
	}
	string zwroc_klase(int m) {
		char kl = obiekty_C[m - 1]->klasa;
		string klas;
		klas.append(1, kl);
		return klas;
	}
	string cena_deluxe(int m) {
		int cena = obiekty_C[m - 1]->cena;
		cena = (cena * 11);
		string cen = to_string(cena);
		return cen;
	}
	string cena_standard(int m) {
		int cena = obiekty_C[m - 1]->cena;
		string cen = to_string(cena);
		return cen;
	}

	string zwroc_przebieg(int m) {
		int przebieg = obiekty_C[m - 1]->przebieg;
		string przeb = to_string(przebieg);
		return przeb;
	}
	string zwroc_kolor(int m) {
		return obiekty_C[m - 1]->kolor;
	}
};

class Class_D : public Samochody {
public:
	vector <Class_D*> obiekty_D;
	Class_D(int id = 0, string mar = "", string mod = "", int r = 0, char klasa = 0, string kolor = "", int cena = 0, int przebieg = 0, bool deluxe = 0, bool wyp = 0) : Samochody(id, mar, mod, r, klasa, kolor, cena, przebieg, deluxe, wyp) {};
	virtual void tworz_D() {
		ifstream wejscie("baza_samochody.txt", std::ifstream::in);
		ofstream wyjscie("baza_D.txt", std::ofstream::out | std::ofstream::trunc);
		int id = 1;
		string _id;
		string marka;
		string model;
		string rocznik;
		string klasa;
		string kolor;
		string cena;
		string przebieg;
		string deluxe;
		string wyp;
		//Tworzenie tablicy wskaznikow
		obiekty_D.clear();
		while (!wejscie.eof()) {
			wejscie >> _id >> marka >> model >> rocznik >> klasa >> kolor >> cena >> przebieg >> deluxe >> wyp;

			if (klasa == "D")
			{
				wyjscie << id << " " << marka << " " << model << " " << rocznik << " " << klasa << " " << kolor << " " << cena << " " << przebieg << " " << deluxe << " " << wyp << endl;
				id++;
			}

		}
		wejscie.close();
		wyjscie.close();

		ifstream wej("baza_D.txt", std::ifstream::in);
		string tab_nag[10] = { "ID","MARKA","MODEL","ROCZNIK","KLASA","KOLOR","CENA","PRZEBIEG","DELUXE","WYPOZYCZONY" };
		int tab_cyfr[10] = { 3, 13, 17, 7, 7, 10, 7, 8, 6, 6 };
		bool _deluxe;
		bool _wyp;
		char c_klasa;
		while (!wej.eof()) {
			wej >> id >> marka >> model >> rocznik >> klasa >> kolor >> cena >> przebieg >> deluxe >> wyp;
			if (deluxe == "tak")
				_deluxe = 1;
			else
				_deluxe = 0;

			if (wyp == "tak")
				_wyp = 1;
			else
				_wyp = 0;

			c_klasa = klasa[0];
			obiekty_D.push_back(new Class_D(id, marka, model, std::stoi(rocznik), c_klasa, kolor, std::stoi(cena), std::stoi(przebieg), _deluxe, _wyp));
		}
		wej.close();
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		for (int i = 0; i < 10; i++) {
			cout << "| " << setfill(' ') << setw(++tab_cyfr[i]) << left << tab_nag[i];
		}
		cout << "|" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		for (int i = 0; i < obiekty_D.size() - 1; i++) {
			cout << "| " << setfill(' ') << setw(3) << left << obiekty_D[i]->id << " | " << setfill(' ') << setw(13) << left << obiekty_D[i]->marka << " | " << setfill(' ') << setw(17) << left << obiekty_D[i]->model << " | " << setfill(' ') << setw(7) << left << obiekty_D[i]->rocznik << " | " << setfill(' ') << setw(7) << left << obiekty_D[i]->klasa << " | " << setfill(' ') << setw(10) << left << obiekty_D[i]->kolor << " | " << setfill(' ') << setw(7) << left << obiekty_D[i]->cena << " | " << setfill(' ') << setw(8) << left << obiekty_D[i]->przebieg << " | " << setfill(' ') << setw(6) << left << obiekty_D[i]->deluxe << " | " << setfill(' ') << setw(10) << left << obiekty_D[i]->wyp << " |" << endl;
			cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		}
	}
	virtual void wybierz_D(int m) {
		cout << obiekty_D[m - 1]->id << " " << obiekty_D[m - 1]->marka << " " << obiekty_D[m - 1]->model << " " << obiekty_D[m - 1]->rocznik << " " << obiekty_D[m - 1]->klasa << " " << obiekty_D[m - 1]->cena << " " << obiekty_D[m - 1]->przebieg << " " << obiekty_D[m - 1]->deluxe << " " << obiekty_D[m - 1]->wyp << endl;
	}
	string zwroc_marka(int m) {
		return obiekty_D[m - 1]->marka;
	}
	string zwroc_model(int m) {
		return obiekty_D[m - 1]->model;
	}
	string zwroc_rocznik(int m) {
		int rok = obiekty_D[m - 1]->rocznik;
		string rocznik = to_string(rok);
		return rocznik;
	}
	string zwroc_klase(int m) {
		char kl = obiekty_D[m - 1]->klasa;
		string klas;
		klas.append(1, kl);
		return klas;
	}
	string cena_deluxe(int m) {
		int cena = obiekty_D[m - 1]->cena;
		cena = (cena * 11);
		string cen = to_string(cena);
		return cen;
	}
	string cena_standard(int m) {
		int cena = obiekty_D[m - 1]->cena;
		string cen = to_string(cena);
		return cen;
	}
	string zwroc_przebieg(int m) {
		int przebieg = obiekty_D[m - 1]->przebieg;
		string przeb = to_string(przebieg);
		return przeb;
	}
	string zwroc_kolor(int m) {
		return obiekty_D[m - 1]->kolor;
	}
};

class StatusZamowien {
private:
	string currentUser;
public:
	int ilosc_pojazdow{};

	StatusZamowien(string CURRENTUSER)
		:currentUser(CURRENTUSER) {};

	bool PrintLista()
	{
		bool empty{};
		OpenCreateFile();
		Text();
		Menu();
		empty = CheckIfEmpty();
		return PrintOrders(empty);
	}

	void PrintFullCarInfo(int choice)
	{
		CarArt();
		FullDataMenu();
		PrintData(choice);
	}

	void OpenCreateFile()
	{
		fstream fs;
		fs.open("Users/" + currentUser + "/status.txt", fstream::out | std::ios::app);

		if (fs.fail())
		{
			cerr << "Blad z otwarciem pliku" << endl;
			exit(1);
		}

		fs.close();

	}

	void Text()
	{
		cout << " _____ _        _                                                _            _       " << endl;
		cout << "/  ___| |      | |                                              (_)          (_)      " << endl;
		cout << "\\ `--.| |_ __ _| |_ _   _ ___   ______ _ _ __ ___   _____      ___  ___ _ __  _  __ _ " << endl;
		cout << " `--. \\ __/ _` | __| | | / __| |_  / _` | '_ ` _ \\ / _ \\ \\ /\\ / / |/ _ \\ '_ \\| |/ _` |" << endl;
		cout << "/\\__/ / || (_| | |_| |_| \\__ \\  / / (_| | | | | | | (_) \\ V  V /| |  __/ | | | | (_| |" << endl;
		cout << "\\____/ \\__\\__,_|\\__|\\__,_|___/ /___\\__,_|_| |_| |_|\\___/ \\_/\\_/ |_|\\___|_| |_|_|\\__,_|" << endl;
		cout << "\n\n";
	}

	void Menu()
	{
		cout << "[0] ZAKONCZ" << endl;
	}

	bool CheckIfEmpty()
	{
		fstream fs;
		string text;
		fs.open("Users/" + currentUser + "/status.txt");
		int counter = 0;
		while (fs >> text)
		{
			counter++;
			fs >> text;
			if (counter > 0 && text != "")
			{
				fs.close();
				return false;
			}
		}
		fs.close();
		return true;
	}

	bool PrintOrders(bool empty)
	{
		int number = 1;
		if (empty)
		{
			cout << "Brak zamowien" << endl;

			while (number != 0) {
				cout << "Podaj numer: ";
				cin >> number;
				if (number == 0)
				{
					system("cls");
					cout << "KONIEC" << endl; // Trzeba zrobic panel glowny
					return true;
					break;
				}
				else
				{
					cout << "Nie ma takiego numeru" << endl;
					system("pause");
					system("cls");
					Text();
					Menu();
				}
			}
		}
		else
			Table();
		cout << "W celu uzyskania wiekszej ilosci informacji o pojezdzie podaj nr ID: ";
		return false;
	}

	void Table()
	{
		int id = 0;
		string marka;
		string model;
		string klasa;
		string kolor;
		string przebieg;
		string rocznik;
		string cena;
		string delux;

		vector<vector<string> > tabela;
		vector<string> row;

		cout << "===================================" << endl;
		cout << "|| " << "ID || " << "MARKA || " << "MODEL || " << "KLASA ||" << endl;

		ifstream fs;
		fs.open("Users/" + currentUser + "/status.txt");

		while (!fs.eof())
		{
			id++;
			fs >> marka;
			fs >> model;
			fs >> rocznik;
			fs >> klasa;
			fs >> kolor;
			fs >> cena;
			fs >> przebieg;
			fs >> delux;

			row.push_back(to_string(id));
			row.push_back(marka);
			row.push_back(model);
			row.push_back(klasa);

			tabela.push_back(row);
			row.clear();
		}
		this->ilosc_pojazdow = id;
		for (int i = 0; i < id; i++)
		{
			cout << "===================================" << endl;
			cout << "|| " << tabela[i][0] << "  || " << tabela[i][1] + " || " << tabela[i][2] + " || " << tabela[i][3] + " ||" << endl;
		}

		fs.close();

		cout << "===================================" << endl;
	}

	bool CheckIfIdExists(int userschoice)
	{
		if (userschoice > ilosc_pojazdow || userschoice < 0)
			return false;
		else
			return true;
	}

	void FullDataMenu()
	{
		cout << "[0] Powrot" << endl;
		cout << "[1] Edytuj" << endl << endl;
	}

	void CarArt()
	{
		cout << "                             _.-=\"_-_" << endl;
		cout << "                          _.-=\"  _-           | ||\"\"\"\"\"\"\"---._______     __.." << endl;
		cout << "             ___.===\"\"\"\"-._ _____-,,,,,,,,,,,,`-''----\" \"\"\"\"\"       \"\"\"\"\"  __'" << endl;
		cout << "      __.--\"\"     __        ,'                   o \\           __        [__|" << endl;
		cout << " __-\"\"=======.--\"\"  \"\"--.=================================.--\"\"  \"\"--.=======:" << endl;
		cout << "]       [w] : /        \\ : |========================|    : /        \\ :  [w] :" << endl;
		cout << "V___________:|          |: |========================|    :|          |:   _-\"" << endl;
		cout << " V__________: \\        / :_|=======================/_____: \\        / :__-\"" << endl;
		cout << " -----------'  \"-____-\"  `-------------------------------'  \"-____-\"" << endl << endl;
	}

	void PrintData(int userschoice)
	{
		string marka;
		string model;
		string klasa;
		string kolor;
		string przebieg;
		string rocznik;
		string cena;
		string delux;
		int id = 0;
		ifstream fs;
		fs.open("Users/" + currentUser + "/status.txt");

		while (!fs.eof())
		{
			id++;

			fs >> marka;
			fs >> model;
			fs >> rocznik;
			fs >> klasa;
			fs >> kolor;
			fs >> cena;
			fs >> przebieg;
			fs >> delux;

			if (id == userschoice)
			{
				cout << "- Dane Samochodu - " << endl;
				cout << "Id: " << id << endl;
				cout << "Marka: " << marka << endl;
				cout << "Model: " << model << endl;
				cout << "Rocznik: " << rocznik << endl;
				cout << "Klasa: " << klasa << endl;
				cout << "Kolor: " << kolor << endl;
				cout << "Cena: " << cena << " zl" << endl;
				cout << "Przebieg: " << przebieg << " km" << endl;
				cout << "Czy Delux: " << delux << endl;
			}
		}

		cout << endl << "Podaj numer: ";
	}

	void EditMenu()
	{
		MenuText();
		MenuMenu();
	}

	void MenuText()
	{
		cout << "Edycja" << endl;
	}

	void MenuMenu()
	{
		cout << "[0] Powrot" << endl;
		cout << "[1] Zrezygnuj" << endl << endl;
		cout << "Podaj numer: ";
	}

	void ResignMenu()
	{
		cout << "Czy na pewno chcesz zrezygnowac ? :c" << endl;
		cout << "[TAK] Zrezygnuj" << endl;
		cout << "[NIE] Powrot" << endl << endl;
		cout << "Podaj tekst: ";
	}

	void RemoveCar(int choice)
	{
		vector<vector<string> > tab;
		ifstream fs;
		int counter = 1;

		string marka;
		string model;
		string rocznik;
		string klasa;
		string kolor;
		string cena;
		string przebieg;
		string delux;
		vector<string> row;
		fs.open("Users/" + currentUser + "/status.txt");
		while (!fs.eof())
		{
			fs >> marka >> model >> rocznik >> klasa >> kolor >> cena >> przebieg >> delux;

			if (counter != choice)
			{
				row.push_back(marka);
				row.push_back(model);
				row.push_back(rocznik);
				row.push_back(klasa);
				row.push_back(kolor);
				row.push_back(cena);
				row.push_back(przebieg);
				row.push_back(delux);
				tab.push_back(row);
			}
			counter++;
			row.clear();
		}
		fs.close();

		ofstream fss;
		fss.open("Users/" + currentUser + "/status.txt", std::ofstream::out | std::ofstream::trunc);

		for (int i = 0; i < tab.size(); i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (j != 7)
					fss << tab[i][j] << " ";
				else
					fss << tab[i][j];
			}
			if (i != tab.size() - 1)
				fss << endl;
		}
		fss.close();

		cout << "Zrezygnowano z pojazdu" << endl;
		system("pause");
	}
};



int main() {
	string currentUser = "admin";
	char n;
	int m;
	Class_A objA;
	Class_B objB;
	Class_C objC;
	Class_D objD;
	Samochody obj;
	vector<string>podsumowanie;
	string marka;
	string model;
	string rocznik;
	string klasa;
	string delux;
	string cena;
	string przebieg;
	string kolor;
	ofstream wyj("Users/" + currentUser + "/status.txt", ios::out | ios::app);

	StatusZamowien obj_Status(currentUser);
	int choice;
	int choice2;
	int choice3;
	string choice4;
	bool loop = true;
	bool loop2 = true;

	cout << "  _____                            _               _       " << endl;
	cout << " / ____|                          | |             | |      " << endl;
	cout << "| (___   __ _ _ __ ___   ___   ___| |__   ___   __| |_   _ " << endl;
	cout << " \\___ \\ / _` | '_ ` _ \\ / _ \\ / __| '_ \\ / _ \\ / _` | | | |" << endl;
	cout << " ____) | (_| | | | | | | (_) | (__| | | | (_) | (_| | |_| |" << endl;
	cout << "|_____/ \\__,_|_| |_| |_|\\___/ \\___|_| |_|\\___/ \\__,_|\\__, |" << endl;
	cout << "                                                      __/ |" << endl;
	cout << "                                                     |___/" << endl;
	obj.wypisz();
	cout << "Wybierz klase samochodu ktory chcesz wypozyczyc" << endl;
	cout << "Dostepne klasy samochodow  A  B  C  D " << endl;
	cin >> n;
	system("cls");
	switch (n) {
	case 'A':
	case 'a':
		podsumowanie.clear();
		cout << "Wybrales klase A " << endl;
		objA.tworz_A();
		cout << "Wybierz samochod " << endl;
		cin >> m;
		system("cls");
		objA.wybierz_A(m);
		marka = objA.zwroc_marka(m);
		model = objA.zwroc_model(m);
		rocznik = objA.zwroc_rocznik(m);
		klasa = objA.zwroc_klase(m);
		kolor = objA.zwroc_kolor(m);
		przebieg = objA.zwroc_przebieg(m);
		podsumowanie.push_back(marka);
		podsumowanie.push_back(model);
		podsumowanie.push_back(rocznik);
		podsumowanie.push_back(klasa);
		podsumowanie.push_back(kolor);
		cout << "Pakiet DELUXE: obejmuje wypozyczenie na rok przez co cena jest mniejsza niz miesieczny koszt wypozyczenia" << endl;
		cout << "Pakiet STANDARD: to pakiet wypozyczenia tylko na miesiac" << endl;
		cout << endl;
		cout << "Wybierz pakiet wypozyczenia DELUXE / STANDARD : ";
		do {
			cin >> delux;
			if (delux == "deluxe" || delux == "Deluxe" || delux == "DELUXE") {
				cout << "wybrales pakiet deluxe" << endl;
				cena = objA.cena_deluxe(m);
				podsumowanie.push_back(cena);
				podsumowanie.push_back(przebieg);
				podsumowanie.push_back("tak");
				obj.RemoveCarBase(obj.findCar(podsumowanie));

			}
			else if (delux == "standard" || delux == "Standard" || delux == "STANDARD") {
				cout << "wybrales pakiet standard " << endl;
				cena = objA.cena_standard(m);
				podsumowanie.push_back(cena);
				podsumowanie.push_back(przebieg);
				podsumowanie.push_back("nie");
				obj.RemoveCarBase(obj.findCar(podsumowanie));
			}
			else {
				delux = "blad";
			}
		} while (delux == "blad");

		if (!obj_Status.CheckIfEmpty())
			wyj << endl;
		for (int i = 0; i < podsumowanie.size(); i++) {
			cout << podsumowanie[i] << " ";
			if (i != podsumowanie.size() - 1)
				wyj << podsumowanie[i] << " ";
			else
				wyj << podsumowanie[i];
		}
		wyj.close();

		//cin>>;
		// wybor pakietu - bedzie pokazywalo samochody z tym pakietem

		// wybor samochodu - jesli samochod jest juz wypozyczony to wyswietla sie komunikat i przenosi do poczatku 

		// przeniesienie do podsumowania
		break;
	case 'B':
	case 'b':
		podsumowanie.clear();
		cout << "Wybrales klase B" << endl;
		objB.tworz_B();
		cout << "Wybierz samochod " << endl;
		cin >> m;
		system("cls");
		objB.wybierz_B(m);
		marka = objB.zwroc_marka(m);
		model = objB.zwroc_model(m);
		rocznik = objB.zwroc_rocznik(m);
		klasa = objB.zwroc_klase(m);
		kolor = objB.zwroc_kolor(m);
		przebieg = objB.zwroc_przebieg(m);
		podsumowanie.push_back(marka);
		podsumowanie.push_back(model);
		podsumowanie.push_back(rocznik);
		podsumowanie.push_back(klasa);
		podsumowanie.push_back(kolor);
		cout << "Pakiet DELUXE: obejmuje wypozyczenie na rok przez co cena jest mniejsza niz miesieczny koszt wypozyczenia" << endl;
		cout << "Pakiet STANDARD: to pakiet wypozyczenia tylko na miesiac" << endl;
		cout << endl;
		cout << "Wybierz pakiet wypozyczenia DELUXE / STANDARD : ";
		do {
			cin >> delux;
			if (delux == "deluxe" || delux == "Deluxe" || delux == "DELUXE") {
				cout << "wybrales pakiet deluxe" << endl;
				cena = objB.cena_deluxe(m);
				podsumowanie.push_back(cena);
				podsumowanie.push_back(przebieg);
				podsumowanie.push_back("tak");
				obj.RemoveCarBase(obj.findCar(podsumowanie));
			}
			else if (delux == "standard" || delux == "Standard" || delux == "STANDARD") {
				cout << "wybrales pakiet standard " << endl;
				cena = objB.cena_standard(m);
				podsumowanie.push_back(cena);
				podsumowanie.push_back(przebieg);
				podsumowanie.push_back("nie");
				obj.RemoveCarBase(obj.findCar(podsumowanie));
			}
			else {
				delux = "blad";
			}
		} while (delux == "blad");

		if (!obj_Status.CheckIfEmpty())
			wyj << endl;
		for (int i = 0; i < podsumowanie.size(); i++) {
			cout << podsumowanie[i] << " ";
			if (i != podsumowanie.size() - 1)
				wyj << podsumowanie[i] << " ";
			else
				wyj << podsumowanie[i];
		}
		wyj.close();

		break;
	case 'C':
	case 'c':
		podsumowanie.clear();
		cout << "Wybrales klase C " << endl;
		objC.tworz_C();
		cout << "Wybierz samochod " << endl;
		cin >> m;
		system("cls");
		objC.wybierz_C(m);
		marka = objC.zwroc_marka(m);
		model = objC.zwroc_model(m);
		rocznik = objC.zwroc_rocznik(m);
		klasa = objC.zwroc_klase(m);
		kolor = objC.zwroc_kolor(m);
		przebieg = objC.zwroc_przebieg(m);
		podsumowanie.push_back(marka);
		podsumowanie.push_back(model);
		podsumowanie.push_back(rocznik);
		podsumowanie.push_back(klasa);
		podsumowanie.push_back(kolor);
		cout << "Pakiet DELUXE: obejmuje wypozyczenie na rok przez co cena jest mniejsza niz miesieczny koszt wypozyczenia" << endl;
		cout << "Pakiet STANDARD: to pakiet wypozyczenia tylko na miesiac" << endl;
		cout << endl;
		cout << "Wybierz pakiet wypozyczenia DELUXE / STANDARD : ";
		do {
			cin >> delux;
			if (delux == "deluxe" || delux == "Deluxe" || delux == "DELUXE") {
				cout << "wybrales pakiet deluxe" << endl;
				cena = objC.cena_deluxe(m);
				podsumowanie.push_back(cena);
				podsumowanie.push_back(przebieg);
				podsumowanie.push_back("tak");
				obj.RemoveCarBase(obj.findCar(podsumowanie));
			}
			else if (delux == "standard" || delux == "Standard" || delux == "STANDARD") {
				cout << "wybrales pakiet standard " << endl;
				cena = objC.cena_standard(m);
				podsumowanie.push_back(cena);
				podsumowanie.push_back(przebieg);
				podsumowanie.push_back("nie");
				obj.RemoveCarBase(obj.findCar(podsumowanie));
			}
			else {
				delux = "blad";
			}
		} while (delux == "blad");

		if (!obj_Status.CheckIfEmpty())
			wyj << endl;
		for (int i = 0; i < podsumowanie.size(); i++) {
			cout << podsumowanie[i] << " ";
			if (i != podsumowanie.size() - 1)
				wyj << podsumowanie[i] << " ";
			else
				wyj << podsumowanie[i];
		}
		wyj.close();

		break;
	case 'D':
	case 'd':
		podsumowanie.clear();
		cout << "Wybrales klase D " << endl;
		objD.tworz_D();
		cout << "Wybierz samochod " << endl;
		cin >> m;
		system("cls");
		objD.wybierz_D(m);
		marka = objD.zwroc_marka(m);
		model = objD.zwroc_model(m);
		rocznik = objD.zwroc_rocznik(m);
		klasa = objD.zwroc_klase(m);
		kolor = objD.zwroc_kolor(m);
		przebieg = objD.zwroc_przebieg(m);
		podsumowanie.push_back(marka);
		podsumowanie.push_back(model);
		podsumowanie.push_back(rocznik);
		podsumowanie.push_back(klasa);
		podsumowanie.push_back(kolor);
		cout << "Pakiet DELUXE: obejmuje wypozyczenie na rok przez co cena jest mniejsza niz miesieczny koszt wypozyczenia" << endl;
		cout << "Pakiet STANDARD: to pakiet wypozyczenia tylko na miesiac" << endl;
		cout << endl;
		cout << "Wybierz pakiet wypozyczenia DELUXE / STANDARD : ";
		do {
			cin >> delux;
			if (delux == "deluxe" || delux == "Deluxe" || delux == "DELUXE") {
				cout << "wybrales pakiet deluxe" << endl;
				cena = objD.cena_deluxe(m);
				podsumowanie.push_back(cena);
				podsumowanie.push_back(przebieg);
				podsumowanie.push_back("tak");
				obj.RemoveCarBase(obj.findCar(podsumowanie));
			}
			else if (delux == "standard" || delux == "Standard" || delux == "STANDARD") {
				cout << "wybrales pakiet standard " << endl;
				cena = objD.cena_standard(m);
				podsumowanie.push_back(cena);
				podsumowanie.push_back(przebieg);
				podsumowanie.push_back("nie");
				obj.RemoveCarBase(obj.findCar(podsumowanie));
			}
			else {
				delux = "blad";
			}
		} while (delux == "blad");

		if (!obj_Status.CheckIfEmpty())
			wyj << endl;
		for (int i = 0; i < podsumowanie.size(); i++) {
			cout << podsumowanie[i] << " ";
			if (i != podsumowanie.size() - 1)
				wyj << podsumowanie[i] << " ";
			else
				wyj << podsumowanie[i];
		}
		wyj.close();

		break;
	default: cout << "Nie istnieje klasa o podanym symbolu" << endl;
	}
	system("pause");
	system("cls");
	// Status -------------------------------------------


	while (loop)
	{
		choice = 0;
		choice2 = 2;
		bool panel = false;
		while (choice == 0 || !obj_Status.CheckIfIdExists(choice)) // Podaj Id pojazdu
		{
			panel = obj_Status.PrintLista();
			if (panel)
			{
				loop = false;
				choice = 1;
				break;
			}

			cin >> choice;
			switch (choice)
			{
			case 0:
			{
				system("cls");
				loop = false;
				choice = 1;
				cout << "DZIEKUJEMY ZA SKORZYSTANIE Z NASZYCH USLUG"; //Przenosi do Panelu
				break;
			}
			default:
			{
				if (obj_Status.CheckIfIdExists(choice))
				{
					while (choice2 != 0 && choice2 != 1) // [1] Edytuj [0] Powrot
					{
						system("cls");
						obj_Status.PrintFullCarInfo(choice);

						cin >> choice2;

						switch (choice2)
						{
						case 0:
							system("cls");
							break;
						case 1:
							choice3 = 2;
							loop2 = true;
							while (choice3 != 0 && choice3 != 1 || loop2) // [1] zrezygnuj [0] powrot
							{
								system("cls");
								obj_Status.EditMenu();
								cin >> choice3;
								switch (choice3)
								{
								case 1:
									choice4 = "yesn't"; // <= celowo
									while (choice4 != "TAK" && choice4 != "NIE") // TAK/NIE
									{
										system("cls");
										obj_Status.ResignMenu();
										cin >> choice4;
										if (choice4 == "TAK")
										{
											obj.AddCarBase(choice, currentUser);
											obj_Status.RemoveCar(choice);
											loop2 = false;
											system("cls");
										}
										else if (choice4 == "NIE")
										{
											system("cls");
										}
										else
										{
											cout << "Wprowadz poprawne polecenie" << endl;
											system("pause");
										}
									}
									break;
								case 0:
									choice2 = 2;
									loop2 = false;
									break;
								default:
									cout << "Nie istnieje taki numer" << endl;
									system("pause");
									break;
								}
							}
							break;
						default:
							cout << "Nie istnieje taki numer" << endl;
							system("pause");
							break;
						};
					}
				}
				else
				{
					cout << "Nie istnieje takie Id" << endl;
					system("pause");
					system("cls");
				}
				break;
			}
			}
		}
	}
	return 0;
}