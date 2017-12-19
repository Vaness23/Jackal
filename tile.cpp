#include "tile.h"

Tile::Tile()
{
    discovered = false;
    visible = true;
    wait = 1; // на клетку тратится один ход
    for (int i = 0; i < 8; i++)
        movement[i] = true;
    coins = 0;
    backSide = QPixmap(":/tile.png").scaledToHeight(50);
    setPixmap(backSide);
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

bool Tile::isDiscovered()
{
    return discovered;
}
