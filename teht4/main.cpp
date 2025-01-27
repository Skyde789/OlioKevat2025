#include <iostream>
#include "asiakas.h"

int main() {
    
    Asiakas x = Asiakas("Pekka", 1000);
   

    cout << endl << x.getNimi() << endl;

    x.showSaldo();
    x.talletus(250);
    x.luotonNosto(150);
    x.showSaldo();

    cout << endl;

    Asiakas y("Marja", 500);
    y.showSaldo();

    cout << endl << x.getNimi() << endl;
    x.tiliSiirto(250, y);

    cout << endl << x.getNimi() << endl;
    x.showSaldo();
    cout << endl << y.getNimi() << endl;
    y.showSaldo();
    return 0;
}