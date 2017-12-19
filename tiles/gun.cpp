#include "gun.h"

Gun::Gun()
{
    frontSide = QPixmap(":/gun.png").scaledToHeight(50);

    wait = 0;
}

void Gun::play(Pirate *pirate)
{
    pirate->movementPoints -= wait;
    discover();
}

tileType Gun::getTileType()
{
    return gun;
}
