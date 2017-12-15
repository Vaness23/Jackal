#include "empty.h"

Empty::Empty()
{
    wait = 1;

    int numPic = rand() % 4;

    switch (numPic)
    {
        case 0:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/empty0.png").scaledToHeight(50);
            break;
        case 1:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/empty1.png").scaledToHeight(50);
            break;
        case 2:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/empty2.png").scaledToHeight(50);
            break;
        case 3:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/empty3.png").scaledToHeight(50);
            break;
    }
}

void Empty::play(Pirate *pirate)
{
    pirate->movementPoints -= wait;
    discover();
}

tileType Empty::getTileType()
{
    return empty;
}
