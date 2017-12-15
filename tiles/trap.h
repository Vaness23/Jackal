#include <tile.h>

class Trap: public Tile
{
public:
    Trap();
    void play(Pirate* pirate);
    tileType getTileType();
};
