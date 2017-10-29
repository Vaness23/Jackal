#include <tile.h>

enum tileType {empty, arrow, horse, spinner, ice, trap, crocodile, cannibal, fortress,
               aborigine, money, plane, balloon, gun, rum};

class Field
{
public:
    Field();
    void show(); // показать все клетки
    void hide(); // спрятать все клетки
private:
    void shuffle(); // перемешать клеки
    tileType map[13][13]; // поле
};
