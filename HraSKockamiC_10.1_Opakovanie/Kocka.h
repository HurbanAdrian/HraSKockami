#pragma once
#include <string>
#include <random>
#include <time.h>

using namespace std;
class Kocka
{
private:
	string farba;
	int priorita;
public:
	Kocka(string paFarba, int paPriorita);
	~Kocka();
	Kocka();

	string getFarba();
	int getPriorita();

	int hodKockou();
};

