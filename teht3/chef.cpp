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