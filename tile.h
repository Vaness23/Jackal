#ifndef TILE_H_
#define TILE_H_

#include <QString>
#include <player.h>
#include <cstdlib>
#include <QGraphicsPixmapItem>

#define N  0
#define NE 1
#define E  2
#define SE 3
#define S  4
#define SW 5
#define W  6
#define NW 7

enum tileType {empty, arrow, horse, spinner, ice, trap, crocodile, cannibal, fortress,
               aborigine, money, plane, balloon, gun, rum};

class Tile: public QGraphicsPixmapItem
{
public:
    Tile();
    bool discovered; // открыта ли клетка
    bool visible; // есть ли клетка на поле
    int wait; // количество ходов ожидания
    bool movement[8]; // направления следующего хода
    QString frontSidePath; // путь к изображению лицевой стороны клетки
    QPixmap backSide;
    int coins; // монеты на клетке
    virtual void play(Player player) = 0;
protected:
    int size; // размер клетки
    std::string backSidePath; // путь к изображению рубашки клетки
};

#endif
