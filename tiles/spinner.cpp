#include "spinner.h"

Spinner::Spinner()
{
    int i, spinner[12];

    for (i = 0; i < 5; i++)
        spinner[i] = 0;

    for (i = 5; i < 9; i++)
        spinner[i] = 1;

    for (i = 9; i < 11; i++)
        spinner[i] = 2;

    spinner[11] = 3;

    int numPic = rand() % 11;

    switch (spinner[numPic])
    {
        case 0:
            frontSide = QPixmap(":/spinner0.png").scaledToHeight(50);
            wait = 2;
            break;
        case 1:
            frontSide = QPixmap(":/spinner1.png").scaledToHeight(50);
            wait = 3;
            break;
        case 2:
            frontSide = QPixmap(":/spinner2.png").scaledToHeight(50);
            wait = 4;
            break;
        case 3:
            frontSide = QPixmap(":/spinner3.png").scaledToHeight(50);
            wait = 5;
            break;
    }

}

void Spinner::play(Pirate *pirate)
{
    pirate->movementPoints -= wait;
    discover();
}

tileType Spinner::getTileType()
{
    return spinner;
}
