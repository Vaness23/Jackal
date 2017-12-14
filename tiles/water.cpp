#include "water.h"

Water::Water()
{
//    frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/water.png";
    setPixmap(QPixmap("/Users/Ivan/Documents/CPP/Jackal/img/water.png").scaledToHeight(50));
    wait = 0;
}

void Water::play()
{

}
