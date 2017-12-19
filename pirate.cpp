#include "pirate.h"

Pirate::Pirate()
{
    alive = true;
    movementPoints = 1;
    myCoin = NULL;

    setPixmap(QPixmap(":/pirate.png"));
}

void Pirate::moveTo(GameObject *nextTile)
{
    setParentItem(nextTile);

//    if (myCoin)
//    {
//        myCoin->setParentItem(nextTile);
//    }

}

void Pirate::pickUpCoin(Coin *collectedCoin)
{
    GameObject* parentTile = static_cast<GameObject*>(this->parentItem());

    collectedCoin->setParentItem(this);
    collectedCoin->moveBy(25, 25);
    myCoin = collectedCoin;
    parentTile->coins--;
}

Coin *Pirate::dropCoin()
{
    GameObject* parentTile = static_cast<GameObject*>(this->parentItem());

    myCoin->moveBy(-25, -25);
    myCoin->setParentItem(parentTile);
    parentTile->coins++;

    Coin *droppedCoin = myCoin;
    myCoin = NULL;
    return droppedCoin;
}

bool Pirate::carriesCoin()
{
    if (myCoin)
        return true;
    else
        return false;
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

