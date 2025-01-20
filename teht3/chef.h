#ifndef CHEF_H
#define CHEF_H
#include <iostream>
using namespace std;

class Chef
{
	public:
		Chef(string); // set name DEBUG
		~Chef(); // DEBUG
		string getName(); 
		int makeSalad(int); // ingredient amount / 5
		int makeSoup(int); // ingredient amount / 3
   
	protected:
		string chefName;
};  

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