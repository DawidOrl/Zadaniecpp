#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
string line;
vector<string> statusy;
int linia = 0;

bool isMaking() {								// funkcja sprawdzaj¹ca czy baza jest w trakcie tworzenia jednostki
	string sprawdzenie;
	char flaga;
	for (int i = 1; i < linia; i++) {
		sprawdzenie = statusy[i];
		if (sprawdzenie[0] == 'P' && sprawdzenie[2] == 'B') {
			flaga = sprawdzenie[sprawdzenie.length() - 1];
			if (flaga == '0') {
				return false;
			}
			else if (flaga != '0') {
				return true;
			}
		}
	}
}

void makeW(int id) {							// funkcja wprowadzaj¹ca rozkaz tworzenia robotnika
	ofstream rozkaz;
	rozkaz.open("rozkazy.txt");
	rozkaz << id << " B W" << endl;
	rozkaz.close();
	}

void makeK(int id) {							// funkcja wprowadzaj¹ca rozkaz tworzenia rycerza
	ofstream rozkaz;
	rozkaz.open("rozkazy.txt");
	rozkaz << id << " B K" << endl;
	rozkaz.close();
}

void makeA(int id) {							// funkcja wprowadzaj¹ca rozkaz tworzenia lucznika
	ofstream rozkaz;
	rozkaz.open("rozkazy.txt");
	rozkaz << id << " B A" << endl;
	rozkaz.close();
}

void makeS(int id) {							// funkcja wprowadzaj¹ca rozkaz tworzenia miecznika
	ofstream rozkaz;
	rozkaz.open("rozkazy.txt");
	rozkaz << id << " B S" << endl;
	rozkaz.close();
}

void makeP(int id) {							// funkcja wprowadzaj¹ca rozkaz tworzenia pikiniera
	ofstream rozkaz;
	rozkaz.open("rozkazy.txt");
	rozkaz << id << " B P" << endl;
	rozkaz.close();
}

void makeR(int id) {							// funkcja wprowadzaj¹ca rozkaz tworzenia tarana
	ofstream rozkaz;
	rozkaz.open("rozkazy.txt");
	rozkaz << id << " B R" << endl;
	rozkaz.close();
}

void makeC(int id) {							// funkcja wprowadzaj¹ca rozkaz tworzenia katapulty
	ofstream rozkaz;
	rozkaz.open("rozkazy.txt");
	rozkaz << id << " B C" << endl;
	rozkaz.close();
}

int maxID() {									// funkcja wyszukuj¹ca maksymalne id jednostki (do produkcji jednostek)
	ifstream staty;
	vector<string> stat;
	vector<string> konwersja;
	int ileLinijek = 0;
	string sprawdzam;
	int id = 0;
	int najwyzszeID = 0;
	staty.open("status.txt");
	if (staty.is_open()) {
		
		while (getline(staty, line)) {
			stat.push_back(line);
			ileLinijek++;
		}

		for (int i = 1; i < ileLinijek; i++) {
			sprawdzam = stat[i];
			if (sprawdzam[7] == ' ') {
				sprawdzam = sprawdzam.substr(3, 4);
				istringstream iss(sprawdzam);
				iss >> id;
			}
			else {
				sprawdzam = sprawdzam.substr(3, 3);
				istringstream iss(sprawdzam);
				iss >> id;
			}
			if (id > najwyzszeID) {
				najwyzszeID = id;
			}
		}
	}
	staty.close();
	return najwyzszeID;
}
int goldCheck() {								// funkcja sprawdzaj¹ca i zwracaj¹ca iloœæ posiadanego z³ota
	ifstream staty;
	int gold = 0;
	staty.open("status.txt");
	if (staty.is_open()) {
		while (getline(staty, line)) {

			istringstream iss(line);
			iss >> gold;
			break;
		}
	}
	staty.close();
	return gold;
}

int ileWorker() {								// funkcja sprawdzaj¹ca i zwracaj¹ca iloœæ posiadanych robotnikow
	int worker = 0;
	string sprawdzenie;
	for (int i = 0; i < linia; i++) {
		sprawdzenie = statusy[i];
		if (sprawdzenie[0] == 'P' && sprawdzenie[2] == 'W') {
			worker++;
		}
	}
	return worker;
}

int ileKnight() {								// funkcja sprawdzaj¹ca i zwracaj¹ca iloœæ posiadanych rycerzy
	int knight = 0;	
	string sprawdzenie;
	for (int i = 0; i < linia; i++) {
		sprawdzenie = statusy[i];
		if (sprawdzenie[0] == 'P' && sprawdzenie[2] == 'K') {
			knight++;
		}
	}
	return knight;
}

int ileArcher() {								// funkcja sprawdzaj¹ca i zwracaj¹ca iloœæ posiadanych lucznikow
	int archer = 0;
	string sprawdzenie;
	for (int i = 0; i < linia; i++) {
		sprawdzenie = statusy[i];
		if (sprawdzenie[0] == 'P' && sprawdzenie[2] == 'A') {
			archer++;
		}
	}
	return archer;
}

int ileSwordsman() {								// funkcja sprawdzaj¹ca i zwracaj¹ca iloœæ posiadanych miecznikow
	int swordsman = 0;
	string sprawdzenie;
	for (int i = 0; i < linia; i++) {
		sprawdzenie = statusy[i];
		if (sprawdzenie[0] == 'P' && sprawdzenie[2] == 'S') {
			swordsman++;
		}
	}
	return swordsman;
}

int ilePikeman() {								// funkcja sprawdzaj¹ca i zwracaj¹ca iloœæ posiadanych wlocznikow
	int pikeman = 0;
	string sprawdzenie;
	for (int i = 0; i < linia; i++) {
		sprawdzenie = statusy[i];
		if (sprawdzenie[0] == 'P' && sprawdzenie[2] == 'P') {
			pikeman++;
		}
	}
	return pikeman;
}

int ileRam() {								// funkcja sprawdzaj¹ca i zwracaj¹ca iloœæ posiadanych taranow
	int ram = 0;
	string sprawdzenie;
	for (int i = 0; i < linia; i++) {
		sprawdzenie = statusy[i];
		if (sprawdzenie[0] == 'P' && sprawdzenie[2] == 'R') {
			ram++;
		}
	}
	return ram;
}
int ileCatapult() {								// funkcja sprawdzaj¹ca i zwracaj¹ca iloœæ posiadanych katapult
	int catapult = 0;
	string sprawdzenie;
	for (int i = 0; i < linia; i++) {
		sprawdzenie = statusy[i];
		if (sprawdzenie[0] == 'P' && sprawdzenie[2] == 'C') {
			catapult++;
		}
	}
	return catapult;
}
int idBazy() {									// funkcja sprawdza id bazy gracza
	int baza = 0;
	string sprawdzenie;
	for (int i = 0; i < linia; i++) {
		sprawdzenie = statusy[i];
		if (sprawdzenie[0] == 'P' && sprawdzenie[2] == 'B' && sprawdzenie[7] == ' ') {
			sprawdzenie = sprawdzenie.substr(3, 4);
			istringstream iss(sprawdzenie);
			iss >> baza;
		}
		else if (sprawdzenie[0] == 'P' && sprawdzenie[2] == 'B') {
			sprawdzenie = sprawdzenie.substr(3, 3);
			istringstream iss(sprawdzenie);
			iss >> baza;
		}
	}
	return baza;
}

void znajdzKopalnie() {							// funkcja znajdujaca wspolzedne wszystkich kopalni
	ifstream map;
	map.open("mapa.txt");
	vector <string> linia;
	string sprawdzenie;
	char szukany = '6';
	int yKopalni;
	int linijka = -1;
	vector <int> kordy;

	if (map.is_open()) {
		while (getline(map, line)) {
			linia.push_back(line);
			linijka++;
		}
		for (int i = 0; i < linijka; i++) {
			sprawdzenie = linia[i];
			if (sprawdzenie.find(szukany) != -1) {
				yKopalni = sprawdzenie.find(szukany);
				kordy.push_back(i);
				kordy.push_back(yKopalni);
			}
		}

		for (int i = 0; i < kordy.size(); i += 2) {
			int znacznik1 = i;
			int znacznik2 = i + 1;
			cout << kordy[znacznik1] << ' ' << kordy[znacznik2] << endl;
		}


		map.close();
	}
}

int odleglosc(int x1, int y1, int x2, int y2) {
	int odleglosc = abs(x1 - x2) + abs(y1 - y2);
	return odleglosc;
}

int main() {

	ifstream staty;
	staty.open("status.txt");

	if (staty.is_open()) {
		while (getline(staty, line)) {			// zapisanie statusu w wektorze
			statusy.push_back(line);
			linia++;
		}
		staty.close();
	}




	/*
	if (isMaking() == false) {
		if (ileWorker() < 3 && goldCheck() >= 100) {
			makeW(idBazy());
		}
		else if (ileKnight() < 2 && goldCheck() >= 400) {
			makeK(idBazy());
		}
		else if (ileArcher() < 5 && goldCheck() >= 250) {
			makeA(idBazy());
		}
	}
	*/





	
}