#ifndef TILE_H_
#define TILE_H_

#include <QString>
#include <cstdlib>
#include <gameobject.h>
#include <pirate.h>


enum direction {N, NE, E, SE, S, SW, W, NW};
enum tileType {default_tile, empty, arrow, horse, spinner, ice, trap, crocodile, cannibal, fortress,
               aborigine, money, plane, balloon, gun, rum, water};

class Tile: public GameObject
{
public:
    Tile();
    bool visible; // есть ли клетка на поле
    int wait; // количество ходов ожидания
    bool movement[8]; // направления следующего хода
//    int coins; // монеты на клетке
    void discover();
    virtual void play(Pirate* pirate);
    objectType getType();
    virtual tileType getTileType();
    bool isDiscovered();
protected:
    bool discovered; // открыта ли клетка
//    QString frontSidePath; // путь к изображению лицевой стороны клетки
    QPixmap backSide, frontSide;
};

#endif
