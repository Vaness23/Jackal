#include "horse.h"

Horse::Horse()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/horse.png").scaledToHeight(50);

    wait = 0;
}

void Horse::play(Pirate pirate)
{
    Tile::play();
    pirate.movementPoints -= wait;
}
