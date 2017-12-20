#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QPoint>
#include <gamescene.h>
#include <player.h>
#include <field.h>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT


//начать ход (активирует нужные фишки и переворачивает поле)
//сделать ход (передвижения)
//завершить ход (поменять игрока, занулить выбранные клетки/фишки)

public:
    explicit Game(QWidget *parent = 0);
    ~Game();
    void drawMap(); // нарисовать поле
    void beginTurn(); // начать ход

private:
    Ui::Game *ui;
    GameScene *scene;
    QGraphicsItem *tile;

    Field<Tile*>* field;
    Player* players[4]; // список игроков
    int activePlayerNum; // номер активного игрока
    Pirate* activePirate;
    void arrangeShips(); // расставить корабли и пиратов
    void arrangeCoins(); // разложить монеты
    void makeTurn(); // сделать ход (передвижение)
    void endTurn(); // завершить ход
    bool checkTile(Pirate* chosenPirate, Tile* chosenTile);
    bool checkTile(Ship* chosenShip, Tile* chosenTile);
    bool checkShip(Pirate* chosenPirate, Ship* chosenShip);
    QString movement1, movement2, movement3, movement4; // вывод ОП игроков на экран
    void updateScore();
    bool gameOver();
    void buttonsEnableCheck(); // активность кнопок для монет
    bool pirateBelongsToActivePlayer(Pirate* pirate);
protected:
    void paintEvent (QPaintEvent *event);
    void mousePressEvent(QMouseEvent *mouseEvent);
private slots:
    void on_shuffleBtn_clicked();
    void on_pickUpCoinButton_clicked();
    void on_dropCoinButton_clicked();
};

#endif // GAME_H
