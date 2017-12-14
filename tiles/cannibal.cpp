#include "cannibal.h"

Cannibal::Cannibal()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/cannibal.png").scaledToHeight(50);

    wait = 1000;
}

void Cannibal::play()
{
    Tile::play();
}
