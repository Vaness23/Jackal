#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <field.h>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();
    void drawMap(); // нарисовать поле

private:
    Ui::Game *ui;
    QGraphicsScene *scene;
    QGraphicsItem *tile;

    Field* field;
    Player* players[4]; // список игроков
    void arrangeShips(); // расставить корабли и пиратов

protected:
    void paintEvent (QPaintEvent *event);
private slots:
    void on_shuffleBtn_clicked();
};

#endif // GAME_H
