#include <iostream>
#include "chef.h";


Chef::Chef(string x) { 
	chefName = x; 
	cout << "[DEBUG] Chef::Chef(): New chef created named " << x << "\n";
}
Chef::~Chef() {
	cout << "[DEBUG] Chef::~Chef(): Chef " << chefName << " destroyed\n";
}
int Chef::makeSalad(int ingr) {
	cout << "[DEBUG] Chef::makeSalad(): Chef " << chefName << " can make " << ingr / 5 << " salads with " << ingr << " ingredients\n";
	return ingr / 5;
}
int Chef::makeSoup(int ingr) {
	cout << "[DEBUG] Chef::makeSalad(): Chef " << chefName << " can make " << ingr / 3 << " soups with " << ingr << " ingredients\n";
	return ingr / 3;
}
string Chef::getName() { return chefName;  }

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

