#include "Seuraaja.h"

Seuraaja::Seuraaja(string n)
{
    nimi = n;
}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string text)
{
    cout << text << endl;
}
