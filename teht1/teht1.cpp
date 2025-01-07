#include <iostream>
#include <cstdlib>
int game(int);

int main() {
    
    std::cout << game(40);

    return 0;
}

int game(int maxNum) {
    srand(0);

    int random = (rand() % maxNum) + 1;

    int guess = 0;
    int guessAmount = 0;

    while (guess != random)
    {
        std::cout << "Arvaa luku valilta 1-" <<maxNum << "\n";
        std::cin >> guess;
        guessAmount++;
        if (guess > random)
            std::cout << "Luku on pienempi";
        else if (guess < random)
            std::cout << "Luku on suurempi";
        else
            std::cout << "Oikea vastaus!";

        std::cout << "\n";
    }
    return guessAmount;
}