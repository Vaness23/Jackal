#include "coin.h"

Coin::Coin()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/coin.png").scaledToHeight(20);
    setPixmap(frontSide);
}

objectType Coin::getType()
{
    return coin;
}
