#include <tile.h>

class Empty: public Tile
{
public:
    Empty();
    void play(Pirate* pirate);
    tileType getTileType();
};
