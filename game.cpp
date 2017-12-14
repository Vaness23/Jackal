#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    field = new Field;
    scene = new GameScene(this);
//    scene->setSceneRect(0, 0, 650, 650);
    ui->graphicsView->setScene(scene);

    players[0] = new Player("white");
    players[1] = new Player("black");
    players[2] = new Player("red");
    players[3] = new Player("blue");

    activePlayerNum = 0;
}

Game::~Game()
{
    delete ui;
}

void Game::drawMap()
{
    int x = 0, y = -50;

    for (int i = 0; i < 13; i++, x = 0, y += 50)
    {
        for(int j = 0; j < 13; j++)
        {       
            tile = field->getTileAt(i,j);
            tile->setPos(x,y);
            scene->addItem(tile);

            x += 50;
        }
    }
    arrangeShips();
//    ui->graphicsView->rotate(90);
}

void Game::beginTurn()
{
//    ui->graphicsView->rotate(90);
}

void Game::arrangeShips()
{
    players[0]->ship.setParentItem(field->getTileAt(0, 6));
    players[1]->ship.setParentItem(field->getTileAt(6, 12));
    players[2]->ship.setParentItem(field->getTileAt(12, 6));
    players[3]->ship.setParentItem(field->getTileAt(6, 0));
}

void Game::makeTurn()
{
    if ((scene->chosenPirate && scene->chosenTile) && // если выбраны пират и клетка
        (   // если пират принадлежит активному игроку
            scene->chosenPirate == &players[activePlayerNum]->pirates[0]
            || scene->chosenPirate == &players[activePlayerNum]->pirates[1]
            || scene->chosenPirate == &players[activePlayerNum]->pirates[2]
            || scene->chosenPirate == &players[activePlayerNum]->pirates[3]
        )
        && checkTile(scene->chosenPirate, scene->chosenTile)) // если пирату доступна клетка
    {
        scene->chosenPirate->moveTo(scene->chosenTile);
        scene->chosenTile->play();
        ui->graphicsView->update();
        endTurn();
    }
    else if (scene->chosenShip && scene->chosenTile // если выбраны корабль и клетка
        && scene->chosenShip == &players[activePlayerNum]->ship // если корабль принадлежит активному игроку
        && checkTile(scene->chosenShip, scene->chosenTile)) // если кораблю доступна клетка
    {
        scene->chosenShip->moveTo(scene->chosenTile);
        ui->graphicsView->update();
        endTurn();
    }
    else if (scene->chosenPirate && scene->chosenShip && // если выбраны пират и корабль
        (   // если пират принадлежит активному игроку
            scene->chosenPirate == &players[activePlayerNum]->pirates[0]
            || scene->chosenPirate == &players[activePlayerNum]->pirates[1]
            || scene->chosenPirate == &players[activePlayerNum]->pirates[2]
            || scene->chosenPirate == &players[activePlayerNum]->pirates[3]
        )
        && checkShip(scene->chosenPirate, scene->chosenShip)) // если пирату доступен переход на корабль
    {
        scene->chosenPirate->moveTo(scene->chosenShip);
        ui->graphicsView->update();
        endTurn();
    }
}

void Game::endTurn()
{
    activePlayerNum++;

    if (activePlayerNum == 4)
        activePlayerNum = 0;

    scene->chosenPirate = NULL;
    scene->chosenShip = NULL;
    scene->chosenTile = NULL;
}

bool Game::checkTile(Pirate *chosenPirate, Tile *chosenTile)
{
    Tile* currentTile = static_cast<Tile*>(chosenPirate->parentItem());

    if (currentTile->getType() == ship)
        currentTile = static_cast<Tile*>(currentTile->parentItem());

    if (currentTile == chosenTile && (currentTile->wait) > 1) // для клеток с задержкой передвижения
    {
        chosenPirate->movementPoints++;
    }
    else
        return field->isPirateMoveOk(currentTile, chosenTile);
}

bool Game::checkTile(Ship *chosenShip, Tile *chosenTile)
{
    Tile* currentTile = static_cast<Tile*>(chosenShip->parentItem());
    return field->isShipMoveOk(currentTile, chosenTile);
}

void Game::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

//    drawMap();
}

void Game::on_shuffleBtn_clicked()
{
    field->shuffleMap();
    drawMap();
    ui->graphicsView->update();
}

void Game::mousePressEvent(QMouseEvent *mouseEvent)
{
//    if (mouseEvent->windowPos().x() >= scene->sceneRect().left() && mouseEvent->windowPos().x() <= scene->sceneRect().right()
//        && mouseEvent->windowPos().y() >= scene->sceneRect().bottom() && mouseEvent->windowPos().y() <= scene->sceneRect().top())
//    {
        if (scene->chosenPirate && scene->chosenTile
            || scene->chosenPirate && scene->chosenShip
            || scene->chosenShip && scene->chosenTile)
        {
            makeTurn();
        }

        //    }
}

bool Game::checkShip(Pirate *chosenPirate, Ship *chosenShip)
{
    Tile* pirateTile = static_cast<Tile*>(chosenPirate->parentItem());
    Tile* shipTile = static_cast<Tile*>(chosenShip->parentItem());
    return field->isPirateToShipOk(pirateTile, shipTile);
}

//начать ход (активирует нужные фишки и переворачивает поле)
//сделать ход (передвижения)
//завершить ход (поменять игрока, занулить выбранные клетки/фишки)






