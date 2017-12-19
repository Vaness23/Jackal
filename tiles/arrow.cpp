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
            frontSide = QPixmap(":/arrow0.png").scaledToHeight(50);
            movement[E] = true;
            break;
        case 1:
            frontSide = QPixmap(":/arrow1.png").scaledToHeight(50);
            movement[NE] = true;
            break;
        case 2:
            frontSide = QPixmap(":/arrow2.png").scaledToHeight(50);
            movement[N] = movement[S] = true;
            break;
        case 3:
            frontSide = QPixmap(":/arrow3.png").scaledToHeight(50);
            movement[NW] = movement[SE] = true;
            break;
        case 4:
            frontSide = QPixmap(":/arrow4.png").scaledToHeight(50);
            movement[N] = movement[E] = movement[SW] = true;
            break;
        case 5:
            frontSide = QPixmap(":/arrow5.png").scaledToHeight(50);
            movement[N] = movement[E] = movement[S] = movement[W] = true;
            break;
        case 6:
            frontSide = QPixmap(":/arrow6.png").scaledToHeight(50);
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
