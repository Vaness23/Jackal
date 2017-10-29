#include "balloon.h"

Balloon::Balloon()
{
    frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/balloon.png";

    wait = 0;
}

void Balloon::play(Player player)
{
    discovered = true;
}
