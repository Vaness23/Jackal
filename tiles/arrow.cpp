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
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/arrow0.png";
            movement[E] = true;
            break;
        case 1:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/arrow1.png";
            movement[NE] = true;
            break;
        case 2:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/arrow2.png";
            movement[N] = movement[S] = true;
            break;
        case 3:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/arrow3.png";
            movement[NW] = movement[SE] = true;
            break;
        case 4:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/arrow4.png";
            movement[N] = movement[E] = movement[SW] = true;
            break;
        case 5:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/arrow5.png";
            movement[N] = movement[E] = movement[S] = movement[W] = true;
            break;
        case 6:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/arrow6.png";
            movement[NE] = movement[SE] = movement[SW] = movement[NW] = true;
            break;
    }
}

void Arrow::play(Player player)
{
    discovered = true;
}
