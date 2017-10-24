#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPainter>
#include <QPoint>
#include <QPicture>
#include <QImage>
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

private:
    Ui::Game *ui;
    void drawMap(QPainter *painter); // нарисовать поле
protected:
    void paintEvent (QPaintEvent *event);
};

#endif // GAME_H
