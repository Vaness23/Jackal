#include "trap.h"

Trap::Trap()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/trap.png").scaledToHeight(50);

    wait = 3;
}

void Trap::play(Pirate pirate)
{
    Tile::play();
    pirate.movementPoints -= wait;
}
