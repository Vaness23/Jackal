#include "water.h"

Water::Water()
{
//    frontSidePath = ":/water.png";
    setPixmap(QPixmap(":/water.png").scaledToHeight(50));
    wait = 1;
    discovered = true;
}

void Water::play(Pirate *pirate)
{
    pirate->movementPoints -= wait;
    discover();
}

tileType Water::getTileType()
{
    return water;
}
