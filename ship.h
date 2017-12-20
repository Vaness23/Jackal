#ifndef SHIP_H
#define SHIP_H
#include <gameobject.h>
#include <pirate.h>

class Ship: public GameObject
{
public:
    Ship();
    objectType getType();
    void moveTo(QGraphicsItem *nextTile); // сделать ход
    bool isEmpty();
};
#endif
