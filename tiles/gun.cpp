#include "gun.h"

Gun::Gun()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/gun.png").scaledToHeight(50);

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
