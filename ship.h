#ifndef SHIP_H
#define SHIP_H
#include <gameobject.h>

class Ship: public GameObject
{
public:
    Ship();
    objectType getType();
    void moveTo(QGraphicsItem *nextTile); // сделать ход
};
#endif
