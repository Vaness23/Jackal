#include <tile.h>

enum tileType {empty, arrow, horse, spinner, ice, trap, crocodile, cannibal, fortress, aborigine, chest, treasure,
              plane, carramba, balloon, gun, lighthouse, BenGann, missioner, Friday, bottle, barrel, cave, earthquake,
              jungle, grass};

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
