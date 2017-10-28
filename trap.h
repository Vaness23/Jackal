#include <tile.h>

class Trap: public Tile
{
public:
    Trap();
    void play(Player player);
};
