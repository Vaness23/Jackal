#include <tile.h>

class Fortress: public Tile
{
public:
    Fortress();
    void play(Pirate* pirate);
    tileType getTileType();
};
