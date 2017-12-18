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

class Field
{
public:
    Field();
    void show(); // показать все клетки
    void hide(); // спрятать все клетки
    Tile* getTileAt(int x, int y) {return map[x][y];}
    Index getTileIndex(Tile* tile);
    bool isPirateMoveOk(Tile* current, Tile* next);
    bool isShipMoveOk(Tile* current, Tile* next);
    bool isPirateToShipOk(Tile* pirateTile, Tile* shipTile);
    void shuffleMap(); // перемешать клетки

private:
    void fill(); // заполнить поле клетками
    bool checkDirection(Tile* current, Index nextIndex);
    Tile* map[13][13]; // поле
};
