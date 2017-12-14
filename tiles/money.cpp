#include "money.h"

Money::Money()
{
    int i, chest[16];

    wait = 1;

    for (i = 0; i < 5; i++)
        chest[i] = 1;

    for (i = 5; i < 10; i++)
        chest[i] = 2;

    for (i = 10; i < 13; i++)
        chest[i] = 3;

    for (i = 13; i < 15; i++)
        chest[i] = 4;

    chest[15] = 5;

    int numPic = rand() % 15;

    coins = chest[numPic]; // кол-во монет в сундуке

    switch (chest[numPic])
    {
        case 1:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/money1.png").scaledToHeight(50);
            break;
        case 2:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/money2.png").scaledToHeight(50);
            break;
        case 3:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/money3.png").scaledToHeight(50);
            break;
        case 4:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/money4.png").scaledToHeight(50);
            break;
        case 5:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/money5.png").scaledToHeight(50);
            break;
    }
}

Money::Money(int coins)
{
    wait = 1;

    this->coins = coins;

    switch (coins)
    {
        case 1:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/money1.png").scaledToHeight(50);
            break;
        case 2:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/money2.png").scaledToHeight(50);
            break;
        case 3:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/money3.png").scaledToHeight(50);
            break;
        case 4:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/money4.png").scaledToHeight(50);
            break;
        case 5:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/money5.png").scaledToHeight(50);
            break;
    }
}

void Money::play(Pirate pirate)
{
    Tile::play();
    pirate.movementPoints -= wait;
}
