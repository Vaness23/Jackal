#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    field = new Field;

}

Game::~Game()
{
    delete ui;
}

void Game::drawMap()
{
    int x, y = -50;

    for (int i = 0; i < 13; i++)
    {
        x = 0;
        y += 50;
        for(int j = 0; j < 13; j++)
        {
            QPixmap pic(field->getTileAt(i,j)->frontSidePath);
            item = scene->addPixmap(pic.scaledToHeight(50));
            item->moveBy(x,y);
            x += 50;
        }
    }
}

void Game::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    drawMap();
}

void Game::on_shuffleBtn_clicked()
{
    field->shuffleMap();
    ui->graphicsView->update();
}
