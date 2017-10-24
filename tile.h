#include <string>

class Tile
{
public:
    Tile();
    bool discovered; // открыта ли клетка
    bool visible; // есть ли клетка на поле
private:
    int size; // размер клетки
    std::string backSidePath; // путь к изображению рубашки клетки
};
