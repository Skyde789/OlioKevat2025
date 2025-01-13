#ifndef GAME_H
#define GAME_H
class Game
{
public:
   Game(int x);
   ~Game();
   void play();
   void printGameResult();
private:
   int maxNumber;
   int playerGuess;
   int randomNumber;
   int numOfGuesses;
};  
#endif // MYCLASS_H