#include "Kocka.h"

Kocka::Kocka(string paFarba, int paPriorita)
{
    this->farba = paFarba;
    this->priorita = paPriorita;
}

Kocka::~Kocka()
{
}

Kocka::Kocka()
{
    this->farba = "";
    this->priorita = 0;
}

string Kocka::getFarba()
{
    return this->farba;
}

int Kocka::getPriorita()
{
    return this->priorita;
}

int Kocka::hodKockou()
{
    /*srand(time(0));
    int premenna = (rand() % 6) + 1;
    return premenna;*/
                                                    //Ked chcem random ale vykonava sa to za sebou a tak
    random_device rd;
    mt19937 generator(rd());                           // namiesto rd moze byt aj cas napr atd.
    uniform_int_distribution<> dist(1, 6);          //pre hodnoty od 1 do 6
    int premenna = dist(generator);
    return premenna;
}
