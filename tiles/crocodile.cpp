#include "crocodile.h"

Crocodile::Crocodile()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/crocodile.png").scaledToHeight(50);

    wait = 0;
}

void Crocodile::play(Pirate *pirate)
{
    pirate->movementPoints -= wait;
    discover();
}

tileType Crocodile::getTileType()
{
    return crocodile;
}
