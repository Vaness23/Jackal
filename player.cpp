#include "player.h"

Player::Player()
{
    numberOfCoins = 0;
}

Player::Player(QString color)
{
    numberOfCoins = 0;

    QString piratePath = "/Users/Ivan/Documents/CPP/Jackal/img/pirate_" + color + ".png";

    for (int i = 0; i < 4; i++)
    {
        pirates[i].setPixmap(QPixmap(piratePath).scaledToHeight(50));
        pirates[i].setParentItem(&ship);
    }

    QString shipPath = "/Users/Ivan/Documents/CPP/Jackal/img/ship_" + color + ".png";

    ship.setPixmap(QPixmap(shipPath).scaledToHeight(50));
}
