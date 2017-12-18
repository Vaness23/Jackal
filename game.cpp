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
    for (int i = 0; i < 4; i++)
        if (players[activePlayerNum]->pirates[i].movementPoints == 0)
            players[activePlayerNum]->pirates[i].movementPoints++;

    switch(activePlayerNum)
    {
        case 0: ui->turnLbl->setText("Ходят: Белые");
            break;
        case 1: ui->turnLbl->setText("Ходят: Черные");
            break;
        case 2: ui->turnLbl->setText("Ходят: Красные");
            break;
        case 3: ui->turnLbl->setText("Ходят: Синие");
    }

    movement1 = movement2 = movement3 = movement4 = "";

    for (int i = 0; i < 4; i++)
    {
        movement1 = movement1 + QString::number(players[0]->pirates[i].movementPoints) + " ";
        movement2 = movement2 + QString::number(players[1]->pirates[i].movementPoints) + " ";
        movement3 = movement3 + QString::number(players[2]->pirates[i].movementPoints) + " ";
        movement4 = movement4 + QString::number(players[3]->pirates[i].movementPoints) + " ";
    }
    ui->whitePiratesLabel->setText(movement1);
    ui->blackPiratesLabel->setText(movement2);
    ui->redPiratesLabel->setText(movement3);
    ui->bluePiratesLabel->setText(movement4);
}

void Game::arrangeShips()
{
    players[0]->ship.setParentItem(field->getTileAt(0, 6));
    players[1]->ship.setParentItem(field->getTileAt(6, 12));
    players[2]->ship.setParentItem(field->getTileAt(12, 6));
    players[3]->ship.setParentItem(field->getTileAt(6, 0));
}

void Game::arrangeCoins()
{
    Coin* coin;
    for (int i = 0; i < scene->chosenTile->coins; i++)
    {
        coin = new Coin;
        // Добавление монеты в ту же сцену
        scene->addItem(coin);
        coin->setParentItem(scene->chosenTile);
    }
}

void Game::makeTurn()
{
    // если выбраны пират и клетка
    if ((scene->chosenPirate && scene->chosenTile) &&
        (   // если пират принадлежит активному игроку
            scene->chosenPirate == &players[activePlayerNum]->pirates[0]
            || scene->chosenPirate == &players[activePlayerNum]->pirates[1]
            || scene->chosenPirate == &players[activePlayerNum]->pirates[2]
            || scene->chosenPirate == &players[activePlayerNum]->pirates[3]
        )
        && checkTile(scene->chosenPirate, scene->chosenTile)) // если пирату доступна клетка
    {
        if (scene->chosenPirate->movementPoints <= 0)
        {
            // пират пропускает ходы
        }
        else
        {
            scene->chosenPirate->moveTo(scene->chosenTile);
            if (scene->chosenTile->getTileType() == money && !scene->chosenTile->isDiscovered())
                arrangeCoins();
            scene->chosenTile->play(scene->chosenPirate);
            ui->graphicsView->update();
        }


        if (scene->chosenPirate->movementPoints <= 0)
            endTurn();
    }

    // если выбраны корабль и клетка
    else if (scene->chosenShip && scene->chosenTile
        && scene->chosenShip == &players[activePlayerNum]->ship // если корабль принадлежит активному игроку
        && checkTile(scene->chosenShip, scene->chosenTile)) // если кораблю доступна клетка
    {
        scene->chosenShip->moveTo(scene->chosenTile);
        ui->graphicsView->update();
        endTurn();
    }

    // если выбраны пират и корабль
    else if (scene->chosenPirate && scene->chosenShip &&
        (   // если пират принадлежит активному игроку
            scene->chosenPirate == &players[activePlayerNum]->pirates[0]
            || scene->chosenPirate == &players[activePlayerNum]->pirates[1]
            || scene->chosenPirate == &players[activePlayerNum]->pirates[2]
            || scene->chosenPirate == &players[activePlayerNum]->pirates[3]
        )
        && checkShip(scene->chosenPirate, scene->chosenShip)) // если пирату доступен переход на корабль
    {
        // если пират пришел с другой клетки
        if (scene->chosenPirate->movementPoints == 1)
        {
            scene->chosenPirate->moveTo(scene->chosenShip);
            ui->graphicsView->update();
        }
        if (scene->chosenPirate->movementPoints <= 0)
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

    beginTurn();
}

bool Game::checkTile(Pirate *chosenPirate, Tile *chosenTile)
{
    Tile* currentTile = static_cast<Tile*>(chosenPirate->parentItem());

    // если пират выходит с корабля на сушу
//    if (currentTile->getType() == ship)
//        currentTile = static_cast<Tile*>(currentTile->parentItem());

    // если пират находится на обычной клетке
    if (currentTile->getType() != ship)
    {
        // пират стоит на клетке с задержкой передвижения
        if (currentTile->getTileType() == spinner || currentTile->getTileType() == trap ||
            currentTile->getTileType() == rum) /*chosenPirate->movementPoints < 0*/
        {
            if (currentTile == chosenTile && chosenPirate->movementPoints < 0)
            {
                chosenPirate->movementPoints++;
                return true;
            }
            else if (chosenPirate->movementPoints == 1)
                return field->isPirateMoveOk(currentTile, chosenTile);
            else return false; // уходит с клетки раньше времени
        }
    }

    return field->isPirateMoveOk(currentTile, chosenTile);
}

bool Game::checkTile(Ship *chosenShip, Tile *chosenTile)
{
    Tile* currentTile = static_cast<Tile*>(chosenShip->parentItem());
    return field->isShipMoveOk(currentTile, chosenTile);
}

bool Game::checkShip(Pirate *chosenPirate, Ship *chosenShip)
{
    Tile* pirateTile = static_cast<Tile*>(chosenPirate->parentItem());
    Tile* shipTile = static_cast<Tile*>(chosenShip->parentItem());
    return field->isPirateToShipOk(pirateTile, shipTile);
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


void Game::on_pickUpCoinButton_clicked()
{
    if (scene->chosenPirate)
    {
        Tile* pirateTile = static_cast<Tile*>(scene->chosenPirate->parentItem());
        GameObject *item;
        Coin* myCoin;

        // если на клетке есть монеты, у пирата монет нет
        if (pirateTile->coins > 0 && !scene->chosenPirate->carriesCoin())
        {
            //`Поиск монетки среди объектов на клетке
            QList<QGraphicsItem*> objectsOnTile;
            objectsOnTile = pirateTile->childItems();
            for (auto obj = objectsOnTile.begin(); obj < objectsOnTile.end(); obj++)
            {
                item = static_cast<GameObject*>(*obj);
                if (item && item->getType() == coin)
                    myCoin = static_cast<Coin*>(item);
            }
            scene->chosenPirate->pickUpCoin(myCoin);
        }
    }

    ui->graphicsView->update();

}

void Game::on_dropCoinButton_clicked()
{
    if (scene->chosenPirate && scene->chosenPirate->carriesCoin())
    {
        scene->chosenPirate->dropCoin();
        ui->graphicsView->update();
    }
}
