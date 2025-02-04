#include <iostream>
#include "Notifikaattori.h"
using namespace std;

int main() {
    
    Notifikaattori n;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);

    /*
    n.tulosta();
    cout << endl;

    n.postita("Yo yo 1");

    cout << endl;
    n.ReverseList();

    n.poista(&b);
    cout << endl;
    n.tulosta();
    cout << endl;
    n.postita("Yo yo 2");

    */
    return 0;
}