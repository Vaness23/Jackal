#include <tile.h>

class Money: public Tile
{
public:
    Money();
    Money(int coins);
    void play(Pirate pirate);
};
