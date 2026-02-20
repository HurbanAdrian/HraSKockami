#pragma once
#include "Kocka.h"

using namespace std;
class Hrac
{
private:
	string meno;

	Kocka kocka;
	int pocetVyhier;
	int cisloPadnuteNaKocke;
public:
	Hrac(string paMeno);
	~Hrac();
	Hrac();

	string getMeno();
	Kocka getKocka();

	void nastavKocku(Kocka novaKocka);

	int getPocetVyhier();
	void zvysPocetVyhier();

	void hodKockou();
	int getCisloPadnuteNaKocke();
};

