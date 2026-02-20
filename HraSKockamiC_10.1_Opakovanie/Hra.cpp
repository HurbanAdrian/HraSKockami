#include "Hra.h"

Hra::Hra()
{
    this->kocky = new Kocka[4];
    this->hraci = new Hrac[4];

    this->kocky[0] = Kocka("BIELA", 1);
    this->kocky[1] = Kocka("MODRA", 2);
    this->kocky[2] = Kocka("HNEDA", 3);
    this->kocky[3] = Kocka("ZLATA", 4);

    this->hraci[0] = Hrac("Peter");
    this->hraci[1] = Hrac("Pavol");
    this->hraci[2] = Hrac("Jozef");
    this->hraci[3] = Hrac("Milan");

    this->kompletVypis();
}

Hra::~Hra()
{
    delete[] this->kocky;
    delete[] this->hraci;
}

void Hra::pridelHracomRandomKocky()
{
    this->zamiesajKocky();
    for (int i = 0; i < 4; i++)
    {
        this->hraci[i].nastavKocku(this->kocky[i]);
    }
}

string Hra::porovnaj()
{
    string menoVitaza = "";
    int hodnotaVitaza = 0;
    int prioritaVitaza = 0;
    string farbaVitaza = "";

    for (int i = 0; i < 4; i++)
    {
        string menoHraca = this->hraci[i].getMeno();
        int hodnotaHraca = this->hraci[i].getCisloPadnuteNaKocke();
        int prioritaHraca = this->hraci[i].getKocka().getPriorita();
        string farbaHraca = this->hraci[i].getKocka().getFarba();

        if (hodnotaHraca > hodnotaVitaza)
        {
            menoVitaza = menoHraca;                     // !!! nezabudni dat prec string do rici           string menoVitaza = menoHraca;    
            hodnotaVitaza = hodnotaHraca;
            prioritaVitaza = prioritaHraca;
            farbaVitaza = farbaHraca;
        }
        else if (hodnotaHraca == hodnotaVitaza && prioritaHraca < prioritaVitaza)
        {
            menoVitaza = menoHraca;
            hodnotaVitaza = hodnotaHraca;
            prioritaVitaza = prioritaHraca;
            farbaVitaza = farbaHraca;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        string menoHraca = this->hraci[i].getMeno();
        int hodnotaHraca = this->hraci[i].getCisloPadnuteNaKocke();
        int prioritaHraca = this->hraci[i].getKocka().getPriorita();
        string farbaHraca = this->hraci[i].getKocka().getFarba();

        if (hodnotaHraca == hodnotaVitaza && prioritaHraca == prioritaVitaza)
        {
            this->hraci[i].zvysPocetVyhier();
        }
    }
    string premenna = menoVitaza + "-" + to_string(hodnotaVitaza) + " " + farbaVitaza;
    return premenna;
}

void Hra::vypis()
{
    this->zamiesajKocky();
    this->pridelHracomRandomKocky();
    this->hodKocky();

    for (int i = 0; i < 4; i++)
    {
        cout << this->hraci[i].getCisloPadnuteNaKocke() << " " << this->hraci[i].getKocka().getFarba() << ",    ";
    }
    cout << this->porovnaj() << endl;


}

void Hra::zamiesajKocky()
{
    //srand(time(0));
    //int seed = rand();

    random_device rd;
    mt19937 mersenneTwister(rd());              //moze byt aj nahrada za default random engine

    shuffle(&this->kocky[0], &this->kocky[4], mersenneTwister);
}

void Hra::hodKocky()
{
    for (int i = 0; i < 4; i++)
    {
        this->hraci[i].hodKockou();
    }
}

void Hra::kompletVypis()
{
    for (int i = 0; i < 4; i++)
    {
        cout << this->hraci[i].getMeno() << "       ";
    }
    cout << endl;

    for (int i = 0; i < POCET_KOL; i++)
    {

        this->vypis();
    }

    cout << "Vysledok:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << this->hraci[i].getMeno() << ": " << this->hraci[i].getPocetVyhier() << endl;
    }
}
