#include "aborigine.h"

Aborigine::Aborigine()
{
//    frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/aborigine.png";

    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/aborigine.png").scaledToHeight(50);

    wait = 1;
}

void Aborigine::play(Pirate* pirate)
{
    pirate->movementPoints -= wait;
    pirate->resurrect();
    discover();
}

tileType Aborigine::getTileType()
{
    return aborigine;
}
