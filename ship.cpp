#include "ship.h"

Ship::Ship()
{

}

objectType Ship::getType()
{
    return ship;
}

void Ship::moveTo(QGraphicsItem *nextTile)
{
    setParentItem(nextTile);
}
