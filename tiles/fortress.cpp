#include "fortress.h"

Fortress::Fortress()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/fortress.png").scaledToHeight(50);

    wait = 1;
}

void Fortress::play(Pirate *pirate)
{
    pirate->movementPoints -= wait;
    discover();
}

tileType Fortress::getTileType()
{
    return fortress;
}
