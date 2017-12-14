#include <QGraphicsScene>
#include <pirate.h>
#include <ship.h>
#include <tile.h>
#include <QGraphicsSceneMouseEvent>
#include <QPoint>

class GameScene: public QGraphicsScene
{
public:
    GameScene();
    GameScene(QObject *parent = __null);
    Pirate *chosenPirate;
    Ship *chosenShip;
    Tile *chosenTile;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
};
