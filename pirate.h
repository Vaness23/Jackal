#include <QGraphicsItem>

class Pirate: public QGraphicsPixmapItem
{
public:
    Pirate();
    void moveTo(QGraphicsItem *nextTile); // сделать ход
    void pickUpCoin(); // поднять монеты
    void dropCoin(); // бросить монету
    bool carriesCoin(); //getter
    bool isAlive(); // getter
    void die(); // убить пирата
    void resurrect(); // воскресить пирата
private:
    bool alive;
    bool coin;
};
