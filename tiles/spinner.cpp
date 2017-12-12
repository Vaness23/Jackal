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
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/spinner0.png";
            wait = 2;
            break;
        case 1:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/spinner1.png";
            wait = 3;
            break;
        case 2:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/spinner2.png";
            wait = 4;
            break;
        case 3:
            frontSidePath = "/Users/Ivan/Documents/CPP/Jackal/img/spinner3.png";
            wait = 5;
            break;
    }
}

void Spinner::play(Player player)
{
    discovered = true;
}
