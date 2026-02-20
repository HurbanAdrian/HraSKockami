#include "Hrac.h"

Hrac::Hrac(string paMeno)
{
    this->meno = paMeno;
    this->kocka = Kocka();
    this->pocetVyhier = 0;
    this->cisloPadnuteNaKocke = 0;
}

Hrac::~Hrac()
{

}

Hrac::Hrac()
{
    this->meno = "";
    this->kocka = Kocka();
    this->pocetVyhier = 0;
    this->cisloPadnuteNaKocke = 0;
}

string Hrac::getMeno()
{
    return this->meno;
}

Kocka Hrac::getKocka()
{
    return this->kocka;
}

void Hrac::nastavKocku(Kocka novaKocka)
{
    this->kocka = novaKocka;
}

int Hrac::getPocetVyhier()
{
    return this->pocetVyhier;
}

void Hrac::zvysPocetVyhier()
{
    this->pocetVyhier++;
}

void Hrac::hodKockou()
{
    this->cisloPadnuteNaKocke = this->kocka.hodKockou();
}

int Hrac::getCisloPadnuteNaKocke()
{
    return this->cisloPadnuteNaKocke;
}
