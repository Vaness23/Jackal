#include "player.h"

Player::Player()
{
    coins = 0;
    shipPlayed = piratePlayed = false;
}

Player::Player(QString color)
{
    coins = 0;
    shipPlayed = piratePlayed = false;

    QString piratePath = ":/pirate_" + color + ".png";

    for (int i = 0; i < 4; i++)
    {
        pirates[i].setPixmap(QPixmap(piratePath).scaledToHeight(50));
        pirates[i].setParentItem(&ship);
    }

    QString shipPath = ":/ship_" + color + ".png";

    ship.setPixmap(QPixmap(shipPath).scaledToHeight(50));
}
