#include "plane.h"

Plane::Plane()
{
    frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/plane.png";

    wait = 0;
}

void Plane::play(Player player)
{
    discovered = true;
}
