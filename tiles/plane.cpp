#include "plane.h"

Plane::Plane()
{
    frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/plane.png").scaledToHeight(50);

    wait = 0;
}

void Plane::play()
{
    Tile::play();
}
