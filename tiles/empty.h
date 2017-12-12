#include <tile.h>

class Empty: public Tile
{
public:
    Empty();
    void play(Player player);
    static Tile* create();
};
