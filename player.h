#include <pirate.h>
#include <ship.h>

class Player
{
public:
    Player();
    Player(QString color);
    Ship ship;
    Pirate pirates[4];
    int coins;
    bool shipPlayed; //игрок ходил кораблем
    bool piratePlayed; //игрок ходил пиратом
};
