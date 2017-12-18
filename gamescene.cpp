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
    if (item)
    {
        GameObject *object = static_cast<GameObject*>(item);

        switch(object->getType())
        {
//            case coin:
//                object = object->parentItem();
            case ship:
                chosenShip = static_cast<Ship*>(object);
                break;
            case pirate:
                if (chosenPirate)
                    chosenTile = static_cast<Tile*>(object->parentItem());
                else
                    chosenPirate = static_cast<Pirate*>(object);
                break;
            case tile:
                chosenTile = static_cast<Tile*>(object);
                break;
        }
    }
}
