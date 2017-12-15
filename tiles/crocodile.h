#include <tile.h>

class Crocodile: public Tile
{
public:
    Crocodile();
    void play(Pirate* pirate);
    tileType getTileType();
};
