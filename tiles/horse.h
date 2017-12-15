#include <tile.h>

class Horse: public Tile
{
public:
    Horse();
    void play(Pirate* pirate);
    tileType getTileType();
};
