#include "Luottotili.h"

Luottotili::Luottotili() {}

Luottotili::Luottotili(string nimi, double raja) : Pankkitili(nimi)
{
    luottoRaja = -raja;

    cout << "Luottotili luotu " << omistaja << ":lle, luottoraja " << raja << endl;
}

double Luottotili::getBalance()
{
    return abs(luottoRaja - saldo);
}

bool Luottotili::deposit(double amount)
{
    // Jos negatiivinen tai mentäisiin yli 0
    if (amount < 0 || saldo + amount > 0)
        return false;

    saldo += amount;

    cout << "Luottotili: talletus " << amount << " tehty, luottoa jaljella " << getBalance() << endl;
    return true;
}

bool Luottotili::withdraw(double amount)
{
    // Jos negatiivinen tai mentäisiin yli rajan
    if (amount < 0 || saldo - amount < luottoRaja)
        return false;

    saldo -= amount;
    cout << "Luottotili: nosto " << amount << " tehty, luottoa jaljella " << getBalance() << endl;
    return true;
}
