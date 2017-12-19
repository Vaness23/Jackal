#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <QGraphicsItem>
#include <QString>

enum objectType{tile, pirate, ship, coin};

class GameObject: public QGraphicsPixmapItem
{
public:
    GameObject();
    virtual objectType getType() = 0;
    int coins;
};

#endif // GAMEOBJECT_H
