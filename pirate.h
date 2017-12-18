#ifndef PIRATE_H
#define PIRATE_H

#include <gameobject.h>
#include <coin.h>

class Pirate: public GameObject
{
public:
    Pirate();
    void moveTo(GameObject *nextTile); // сделать ход
    void pickUpCoin(Coin* collectedCoin); // поднять монеты
    void dropCoin(); // бросить монету
    bool carriesCoin(); //getter
    bool isAlive(); // getter
    void die(); // убить пирата
    void resurrect(); // воскресить пирата
    objectType getType();
    int movementPoints;
private:
    bool alive;
    Coin* myCoin;
};
#endif
