#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H
#include <iostream>
using namespace std;
#include "Seuraaja.h"

class Notifikaattori
{
public:
	Notifikaattori();
	void lisaa(Seuraaja*);
	void poista(Seuraaja*);
	void tulosta();
	void postita(string);
	void ReverseList();
private:
	Seuraaja* seuraajat = nullptr;
};

#endif // MYCLASS_H
