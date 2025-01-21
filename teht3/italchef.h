#ifndef ITALCHEF_H
#define ITALCHEF_H
#include <iostream>
#include "chef.h"
using namespace std;

class ItalianChef : public Chef
{
public:
	ItalianChef(string s) : Chef(s) { cout << "[DEBUG] ItalianChef::ItalianChef(): New ItalianChef created named " << s << "\n"; } ;
	~ItalianChef();
	bool askSecret(string, int, int); // check string ? makePizza | 5 / 5

private:
	string password = "pizza";
	int flour; 
	int water;
	int makePizza(int, int);
};
#endif // MYCLASS_H