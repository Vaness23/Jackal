#include "trap.h"

Trap::Trap()
{
    frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/trap.png";

    wait = 1000;
}

void Trap::play(Player player)
{
    discovered = true;
}
