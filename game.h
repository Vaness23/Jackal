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

private:
    Ui::Game *ui;
    Field* field;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *item;

    void drawMap(); // нарисовать поле
protected:
    void paintEvent (QPaintEvent *event);
private slots:
    void on_shuffleBtn_clicked();
};

#endif // GAME_H
