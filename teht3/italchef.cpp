#include <iostream>
#include "italchef.h";

ItalianChef::~ItalianChef(){ 
	cout << "[DEBUG] ItalianChef::~ItalianChef(): ItalianChef " << chefName << " destroyed\n"; 
}

bool ItalianChef::askSecret(string pas, int fl, int wa) {
	if (pas == password) {
		cout << "[DEBUG] ItalianChef::askSecret(): Password OK!\n";
		makePizza(fl, wa);
	}
	return pas == password;
}

int ItalianChef::makePizza(int fl, int wa) {
	cout << "[DEBUG] Chef::makeSalad(): Chef " << chefName << " can make " << min(fl / 5, wa / 5) << " pizzas with " << wa << " water and " << fl << " flour\n";
	return min(fl / 5, wa / 5);
}

