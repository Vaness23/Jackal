#include <tile.h>
#include <coin.h>
#include <QGraphicsScene>

class Money: public Tile
{
public:
    Money();
    Money(int coins);
    void play(Pirate* pirate);
    tileType getTileType();
};
