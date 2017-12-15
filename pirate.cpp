#include "pirate.h"

Pirate::Pirate()
{
    alive = true;
    coin = false;
    movementPoints = 1;

    setPixmap(QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/pirate.png"));
}

void Pirate::moveTo(QGraphicsItem *nextTile)
{
    setParentItem(nextTile);
}

void Pirate::pickUpCoin()
{

}

void Pirate::dropCoin()
{

}

bool Pirate::carriesCoin()
{
    return coin;
}

bool Pirate::isAlive()
{
    return alive;
}

void Pirate::die()
{
    alive = false;
    setVisible(false);
}

void Pirate::resurrect()
{
    alive = true;
    setVisible(true);
}

objectType Pirate::getType()
{
    return pirate;
}

