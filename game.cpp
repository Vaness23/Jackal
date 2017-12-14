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
    ui->graphicsView->rotate(90);
}

void Game::beginTurn()
{
    ui->graphicsView->rotate(90);
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
    if (scene->chosenPirate && scene->chosenTile)
    {
        scene->chosenPirate->moveTo(scene->chosenTile);
        scene->chosenTile->play();
        ui->graphicsView->update();
    }
    if (scene->chosenShip && scene->chosenTile)
    {
        scene->chosenShip->moveTo(scene->chosenTile);
        ui->graphicsView->update();
    }
    if (scene->chosenPirate && scene->chosenShip)
    {
        scene->chosenPirate->moveTo(scene->chosenShip);
        ui->graphicsView->update();
    }
    endTurn();
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

//начать ход (активирует нужные фишки и переворачивает поле)
//сделать ход (передвижения)
//завершить ход (поменять игрока, занулить выбранные клетки/фишки)






