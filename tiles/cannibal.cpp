#include "cannibal.h"

Cannibal::Cannibal()
{
    frontSide = QPixmap(":/cannibal.png").scaledToHeight(50);

    wait = 100;
}

void Cannibal::play(Pirate *pirate)
{
    pirate->movementPoints -= wait;
    pirate->die();
    discover();
}

tileType Cannibal::getTileType()
{
    return cannibal;
}
