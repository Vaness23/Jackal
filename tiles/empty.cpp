#include "empty.h"

Empty::Empty()
{
    wait = 1;

    int numPic = rand() % 4;

    switch (numPic)
    {
        case 0:
            frontSide = QPixmap(":/empty0.png").scaledToHeight(50);
            break;
        case 1:
            frontSide = QPixmap(":/empty1.png").scaledToHeight(50);
            break;
        case 2:
            frontSide = QPixmap(":/empty2.png").scaledToHeight(50);
            break;
        case 3:
            frontSide = QPixmap(":/empty3.png").scaledToHeight(50);
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
