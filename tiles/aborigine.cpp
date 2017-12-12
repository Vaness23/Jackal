#include "aborigine.h"

Aborigine::Aborigine()
{
    frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/aborigine.png";

    wait = 1;
}

void Aborigine::play(Player player)
{
    discovered = true;
}
