#include "Asiakas.h"

Asiakas::Asiakas(string nimi, double raja)
{
    this->nimi = nimi;
    kayttotili = Pankkitili(nimi);
    luottotili = Luottotili(nimi, raja);
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout << "Pankkitili saldo : " << kayttotili.getBalance() << 
            "\nLuottotili saldo: " << luottotili.getBalance() << endl;
}

bool Asiakas::talletus(double amount)
{
    return kayttotili.deposit(amount);
}

bool Asiakas::nosto(double amount)
{
    return kayttotili.withdraw(amount);
}

bool Asiakas::luotonMaksu(double amount)
{
    return luottotili.deposit(amount);
}

bool Asiakas::luotonNosto(double amount)
{
    return luottotili.withdraw(amount);
}

bool Asiakas::tiliSiirto(double amount, Asiakas& target)
{
   
    cout << "Pankkitili: Yritetaan siirtaa " << amount << " " << target.getNimi() << ":lle" << endl;
    bool x = nosto(amount) && target.talletus(amount);
    
    cout << (x ? "Tilisiirto onnistui" : "Tilisiirto epaonnistui") << endl;
    return x;
}
