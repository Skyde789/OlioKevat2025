#include <iostream>
#include "chef.h"

int main() {
    
    Chef cook("Gordon");
    cout << "\n";
    cook.makeSalad(13);
    cook.makeSoup(12);
    cout << "\n";
    ItalianChef cook2("Mario");
    cout << "\n";
    cook2.askSecret("pizza", 12, 23);
    cout << "\n";
    return 0;
}