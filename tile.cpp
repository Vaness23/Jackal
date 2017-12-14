#include "tile.h"

Tile::Tile()
{
    discovered = false;
    visible = true;
    wait = 1; // на клетку тратится один ход
    for (int i = 0; i < 8; i++)
        movement[i] = true;
    coins = 0;
    backSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/tile.png").scaledToHeight(50);
    setPixmap(backSide);
    //frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/tile.png";
}

objectType Tile::getType()
{
    return tile;
}
