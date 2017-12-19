#include "ice.h"

Ice::Ice()
{
    frontSide = QPixmap(":/ice.png").scaledToHeight(50);

    wait = 0;
}

void Ice::play(Pirate* pirate)
{
    pirate->movementPoints -= wait;
    discover();
}

tileType Ice::getTileType()
{
    return ice;
}
