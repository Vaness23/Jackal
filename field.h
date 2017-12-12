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

class Field
{
public:
    Field();
    void show(); // показать все клетки
    void hide(); // спрятать все клетки
    Tile* getTileAt(int x, int y);
    void shuffleMap(); // перемешать клетки БУДЕТ ПРИВАТНОЙ КАК ТАНЕЦ МУСУЛЬМАНКИ
private:
    void fill(); // заполнить поле клетками
    void shuffleArray(Tile *array[], int length); // перемешать массив
    Tile* map[13][13]; // поле
};
