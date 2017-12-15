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

void Tile::discover()
{
    if (!discovered)
    {
        discovered = true;
        setPixmap(frontSide);
    }
}

void Tile::play(Pirate *pirate)
{

}

objectType Tile::getType()
{
    return tile;
}

tileType Tile::getTileType()
{
    return default_tile;
}
