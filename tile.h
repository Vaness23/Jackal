#include <string>
#include <player.h>
#include <cstdlib>

#define N  0
#define NE 1
#define E  2
#define SE 3
#define S  4
#define SW 5
#define W  6
#define NW 7

class Tile
{
public:
    Tile();
    bool discovered; // открыта ли клетка
    bool visible; // есть ли клетка на поле
    int wait; // колличество ходов ожидания
    bool movement[8]; // направления следующего хода
    char * frontSidePath; // путь к изображению лицевой стороны клетки
    int coins; // монеты на клетке
private:
    int size; // размер клетки
    std::string backSidePath; // путь к изображению рубашки клетки
};
