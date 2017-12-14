#ifndef PIRATE_H
#define PIRATE_H
#include <gameobject.h>

class Pirate: public GameObject
{
public:
    Pirate();
    void moveTo(QGraphicsItem *nextTile); // сделать ход
    void pickUpCoin(); // поднять монеты
    void dropCoin(); // бросить монету
    bool carriesCoin(); //getter
    bool isAlive(); // getter
    void die(); // убить пирата
    void resurrect(); // воскресить пирата
    objectType getType();
    int movementPoints;
private:
    bool alive;
    bool coin;
};
#endif
