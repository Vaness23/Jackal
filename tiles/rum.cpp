#include "rum.h"

Rum::Rum()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/rum.png").scaledToHeight(50);

    wait = 2;
}

void Rum::play(Pirate pirate)
{
    Tile::play();
    pirate.movementPoints -= wait;
}
