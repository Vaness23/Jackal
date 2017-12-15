#include <tile.h>

class Ice: public Tile
{
public:
    Ice();
    void play(Pirate* pirate);
    tileType getTileType();
};
