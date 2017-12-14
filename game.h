#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QPoint>
#include <gamescene.h>
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
    void beginTurn(); // начать ход

private:
    Ui::Game *ui;
    GameScene *scene;
    QGraphicsItem *tile;

    Field* field;
    Player* players[4]; // список игроков
    int activePlayerNum; // номер активного игрока
    void arrangeShips(); // расставить корабли и пиратов
    void makeTurn(); // сделать ход (передвижение)
    void endTurn(); // завершить ход

protected:
    void paintEvent (QPaintEvent *event);
    void mousePressEvent(QMouseEvent *mouseEvent);
private slots:
    void on_shuffleBtn_clicked();
};

#endif // GAME_H
