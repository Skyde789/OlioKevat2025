#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include <iostream>
#include "Pankkitili.h"
using namespace std;


class Luottotili : public Pankkitili
{
	public:
		Luottotili();
		Luottotili(string, double);
		double getBalance() override;
		bool deposit(double) override;
		bool withdraw(double) override;
	protected:
		double luottoRaja = 0;
};
#endif

