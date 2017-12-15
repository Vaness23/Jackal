#include <tile.h>

class Rum: public Tile
{
public:
    Rum();
    void play(Pirate* pirate);
    tileType getTileType();
};
