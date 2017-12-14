#include "trap.h"

Trap::Trap()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/trap.png").scaledToHeight(50);

    wait = 1000;
}

void Trap::play()
{
    Tile::play();
}
