#include "money.h"

Money::Money()
{
    int i, chest[16];

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
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/money1.png";
            break;
        case 2:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/money2.png";
            break;
        case 3:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/money3.png";
            break;
        case 4:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/money4.png";
            break;
        case 5:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/money5.png";
            break;
    }
}

Money::Money(int coins)
{
    this->coins = coins;

    switch (coins)
    {
        case 1:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/money1.png";
            break;
        case 2:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/money2.png";
            break;
        case 3:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/money3.png";
            break;
        case 4:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/money4.png";
            break;
        case 5:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/money5.png";
            break;
    }
}

void Money::play(Player player)
{
    discovered = true;
}
