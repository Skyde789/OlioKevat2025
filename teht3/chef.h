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
#endif // MYCLASS_H