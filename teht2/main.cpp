#include <iostream>
#include <game.h>
#include <ctime>

int main(){
    
    srand(time(0));
    Game g(30);

    g.play();
    return 0;
}