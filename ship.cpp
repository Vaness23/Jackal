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

bool Ship::isEmpty()
{
    QList<QGraphicsItem*> objectsOnShip;
    objectsOnShip = childItems();
    for (auto obj = objectsOnShip.begin();
            obj < objectsOnShip.end(); obj++)
    {
        GameObject *item = static_cast<GameObject*>(*obj);
        if (item && item->getType() == pirate)
            return false;
    }
    return true;
}
