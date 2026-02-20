#pragma once
#include "Kocka.h"
#include "Hrac.h"
#include <iostream>
//#include <algorithm>		//pre mersenetwister algorithm

const int POCET_KOL = 10;
using namespace std;
class Hra
{
private:
	Kocka* kocky;
	Hrac* hraci;

public:
	Hra();
	~Hra();

	void pridelHracomRandomKocky();
	string porovnaj();
	void vypis();
	void zamiesajKocky();
	void hodKocky();

	void kompletVypis();
};

