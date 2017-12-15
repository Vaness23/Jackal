#include "balloon.h"

Balloon::Balloon()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/balloon.png").scaledToHeight(50);

    wait = 0;
}

void Balloon::play(Pirate *pirate)
{
    discover();
    pirate->movementPoints -= wait;
}

tileType Balloon::getTileType()
{
    return balloon;
}
