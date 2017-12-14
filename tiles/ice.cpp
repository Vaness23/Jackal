#include "ice.h"

Ice::Ice()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/ice.png").scaledToHeight(50);

    wait = 0;
}

void Ice::play(Pirate pirate)
{
    Tile::play();
    pirate.movementPoints -= wait;
}
