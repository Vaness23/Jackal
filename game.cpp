#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
//    drawMap();

}

Game::~Game()
{
    delete ui;
}

void Game::drawMap(QPainter *painter)
{
//    QPicture tilePicture;
//    tilePicture.load("tile.png");

    QImage img("/Users/Ivan/Documents/CPP/Jackal/img/aborigine.png");

    painter->drawImage(0, 0, img);
}

void Game::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    drawMap(&painter);
//    QPicture tilePicture;
//    tilePicture.load("tile.png");

//    painter.drawPicture(0, 0, tilePicture);
}
