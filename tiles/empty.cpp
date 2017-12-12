#include "empty.h"

Empty::Empty()
{
    int numPic = rand() % 4;

    switch (numPic)
    {
        case 0:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/empty0.png";
            break;
        case 1:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/empty1.png";
            break;
        case 2:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/empty2.png";
            break;
        case 3:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/empty3.png";
            break;
    }
}

void Empty::play(Player player)
{
    discovered = true;
}

Tile *Empty::create()
{
    return new Empty;
}
