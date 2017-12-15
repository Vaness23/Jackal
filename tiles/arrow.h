#include <tile.h>

class Arrow: public Tile
{
public:
    Arrow();
    void play(Pirate *pirate);
    tileType getTileType();
};
