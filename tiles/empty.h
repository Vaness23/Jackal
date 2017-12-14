#include <tile.h>

class Empty: public Tile
{
public:
    Empty();
    void play();
    static Tile* create();
};
