#include <tile.h>

class Balloon: public Tile
{
public:
    Balloon();
    void play(Pirate* pirate);
    tileType getTileType();
};
