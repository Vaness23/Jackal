#include "trap.h"

Trap::Trap()
{
    frontSide = QPixmap(":/trap.png").scaledToHeight(50);

    wait = 3;
}

void Trap::play(Pirate *pirate)
{
    pirate->movementPoints -= wait;
    discover();
}

tileType Trap::getTileType()
{
    return trap;
}
