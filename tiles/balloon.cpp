#include "balloon.h"

Balloon::Balloon()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/balloon.png").scaledToHeight(50);

    wait = 0;
}

void Balloon::play()
{
    Tile::play();
}
