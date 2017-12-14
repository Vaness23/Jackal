#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <QGraphicsItem>

enum objectType{tile, pirate, ship};

class GameObject: public QGraphicsPixmapItem
{
public:
    GameObject();
    virtual objectType getType() = 0;
};

#endif // GAMEOBJECT_H
