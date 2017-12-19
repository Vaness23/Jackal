//#include <tile.h>
#include "tiles/empty.h"
#include "tiles/arrow.h"
#include "tiles/horse.h"
#include "tiles/spinner.h"
#include "tiles/ice.h"
#include "tiles/trap.h"
#include "tiles/crocodile.h"
#include "tiles/cannibal.h"
#include "tiles/fortress.h"
#include "tiles/aborigine.h"
#include "tiles/money.h"
#include "tiles/plane.h"
#include "tiles/balloon.h"
#include "tiles/gun.h"
#include "tiles/rum.h"
#include "tiles/water.h"

struct Index
{
    int x, y;
};

template <class T>
class Field
{
public:
    Field();
    void show(); // показать все клетки
    void hide(); // спрятать все клетки
    T getTileAt(int x, int y) {return map[x][y];}
    Index getTileIndex(T tile);
    bool isPirateMoveOk(T current, T next);
    bool isShipMoveOk(T current, T next);
    bool isPirateToShipOk(T pirateTile, T shipTile);
    void shuffleMap(); // перемешать клетки
    int coins;
private:
    void fill(); // заполнить поле клетками
    bool checkDirection(T current, Index nextIndex);
    T map[13][13]; // поле
    unsigned seed;
};
