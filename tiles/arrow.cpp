#include "arrow.h"

Arrow::Arrow()
{
    int numPic = rand() % 6;

    for (int i = 0; i < 8; i++)
        movement[i] = false;

    wait = 0;

    switch (numPic)
    {
        case 0:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/arrow0.png").scaledToHeight(50);
            movement[E] = true;
            break;
        case 1:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/arrow1.png").scaledToHeight(50);
            movement[NE] = true;
            break;
        case 2:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/arrow2.png").scaledToHeight(50);
            movement[N] = movement[S] = true;
            break;
        case 3:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/arrow3.png").scaledToHeight(50);
            movement[NW] = movement[SE] = true;
            break;
        case 4:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/arrow4.png").scaledToHeight(50);
            movement[N] = movement[E] = movement[SW] = true;
            break;
        case 5:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/arrow5.png").scaledToHeight(50);
            movement[N] = movement[E] = movement[S] = movement[W] = true;
            break;
        case 6:
            frontSide = QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/arrow6.png").scaledToHeight(50);
            movement[NE] = movement[SE] = movement[SW] = movement[NW] = true;
            break;
    }
}

void Arrow::play(Pirate *pirate)
{
    pirate->movementPoints -= wait;
    discover();
}

tileType Arrow::getTileType()
{
    return arrow;
}
