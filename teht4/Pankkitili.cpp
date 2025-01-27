#include "Pankkitili.h"

Pankkitili::Pankkitili(){}

Pankkitili::Pankkitili(string nimi)
{
	omistaja = nimi;
	cout << "Pankkitili luotu " << omistaja << ":lle\n";
}

double Pankkitili::getBalance()
{
	return saldo;
}

bool Pankkitili::deposit(double amount)
{
	if(amount < 0)
		return false;

	saldo += amount;
	cout << "Kayttotili: talletus " << amount << " tehty, uusi saldo " << getBalance() << endl;
	return true;
}

bool Pankkitili::withdraw(double amount)
{
	if (amount < 0 || saldo - amount < 0)
		return false;

	saldo -= amount;
	cout << "Kayttotili: nosto " << amount << " tehty, uusi saldo " << getBalance() << endl;
	return true;
}
