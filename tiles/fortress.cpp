#include "fortress.h"

Fortress::Fortress()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/fortress.png").scaledToHeight(50);

    wait = 1;
}

void Fortress::play(Pirate pirate)
{
    Tile::play();
    pirate.movementPoints -= wait;
}
