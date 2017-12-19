#include "coin.h"

Coin::Coin()
{
    frontSide = QPixmap(":/coin.png").scaledToHeight(20);
    setPixmap(frontSide);
}

objectType Coin::getType()
{
    return coin;
}
