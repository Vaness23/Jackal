#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    field = new Field;
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    players[0] = new Player("white");
    players[1] = new Player("black");
    players[2] = new Player("red");
    players[3] = new Player("blue");


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
//        x = 0;
//        y += 50;
        for(int j = 0; j < 13; j++)
        {
            //QPixmap pic(field->getTileAt(i,j)->frontSidePath);
            //item = scene->addPixmap(pic.scaledToHeight(50));
            tile = field->getTileAt(i,j);
//            tile->moveBy(0, 0);
            tile->setPos(x,y);
            scene->addItem(tile);

            x += 50;
        }
    }
    //tile = scene->addPixmap(QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/pirate.png"));
    //tile->setFlag(QGraphicsItem::ItemIsMovable);
}

void Game::arrangeShips()
{
    players[0]->ship.setParentItem(field->getTileAt(0, 6));
    players[1]->ship.setParentItem(field->getTileAt(6, 12));
    players[2]->ship.setParentItem(field->getTileAt(12, 6));
    players[3]->ship.setParentItem(field->getTileAt(6, 0));
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
    arrangeShips();
    ui->graphicsView->update();
}
