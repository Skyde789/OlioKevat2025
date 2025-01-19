#include <game.h>
#include <iostream>

Game::Game(int x) {

    maxNumber = x;

    numOfGuesses = 0;
    playerGuess = -1;
    randomNumber = -1;

    std::cout << "DEBUG Game::Game(): Object initialized with " << maxNumber << " as the max value\n";
}
Game::~Game() {
    std::cout << "DEBUG Game::~Game(): Object cleared from memory\n";
}

void Game::play(){
    randomNumber = (std::rand() % maxNumber) + 1;

    while (playerGuess != randomNumber)
    {
        std::cout << "Arvaa luku valilta 1-" <<maxNumber << "\n";
        std::cin >> playerGuess;
        numOfGuesses++;
        if (playerGuess > randomNumber)
            std::cout << "Luku on pienempi";
        else if (playerGuess < randomNumber)
            std::cout << "Luku on suurempi";
        else
            std::cout << "Oikea vastaus!";

        std::cout << "\n";
    }

    printGameResult();
}

void Game::printGameResult(){
    std::cout << "Arvasit " << numOfGuesses << " kertaa!\n";
}