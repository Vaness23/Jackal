#include <tile.h>

class Spinner: public Tile
{
public:
    Spinner();
    void play(Pirate* pirate);
    tileType getTileType();
};
