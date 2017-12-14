#include "gamescene.h"

GameScene::GameScene()
{
    chosenPirate = NULL;
    chosenShip = NULL;
    chosenTile = NULL;
}

GameScene::GameScene(QObject *parent): QGraphicsScene(parent)
{
    chosenPirate = NULL;
    chosenShip = NULL;
    chosenTile = NULL;
}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QGraphicsItem *item = itemAt(mouseEvent->scenePos(), QTransform());
    GameObject *object = static_cast<GameObject*>(item);

    switch(object->getType())
    {
        case ship:
            chosenShip = static_cast<Ship*>(object);
            return;
        case pirate:
            chosenPirate = static_cast<Pirate*>(object);
            return;
        case tile:
            chosenTile = static_cast<Tile*>(object);
            return;
    }
}
