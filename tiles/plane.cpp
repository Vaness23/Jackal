#include "plane.h"

Plane::Plane()
{
    frontSide = QPixmap(":/plane.png").scaledToHeight(50);

    wait = 0;
}

void Plane::play(Pirate *pirate)
{
    pirate->movementPoints -= wait;
    discover();
}

tileType Plane::getTileType()
{
    return plane;
}
