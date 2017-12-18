#ifndef COIN_H
#define COIN_H

#include <gameobject.h>

class Coin: public GameObject
{
public:
    Coin();
    objectType getType();
protected:
    QPixmap frontSide;
};

#endif
