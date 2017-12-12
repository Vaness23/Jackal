#include "tile.h"

Tile::Tile()
{
    discovered = false;
    visible = true;
    wait = 1; // на клетку тратится один ход
    for (int i = 0; i < 8; i++)
        movement[i] = true;
    coins = 0;
    frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/tile.png";
}
