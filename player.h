#include <pirate.h>
#include <ship.h>

class Player
{
public:
    Player();
    Player(QString color);
    Ship ship;
    Pirate pirates[4];
    void addCoin();
    int getCoins();
private:
    int numberOfCoins;
};
