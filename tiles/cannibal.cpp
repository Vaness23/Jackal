#include "cannibal.h"

Cannibal::Cannibal()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/cannibal.png").scaledToHeight(50);

    wait = 1;
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
