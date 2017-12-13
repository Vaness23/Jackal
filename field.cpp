#include "field.h"
#include <chrono>
#include <random>

Field::Field(){
    fill(); // заполнение поля клетками
    shuffleMap();
}

void Field::fill()
{
    int col, row;

    for (col = 0; col <= 12; col++) // 1-я строка поля - 11 воды
        map[0][col] = static_cast<Tile*>(new Water);

    for (col = 0; col <= 1; col++) // 2-я строка поля - 2 воды
        map[1][col] = static_cast<Tile*>(new Water);

    for (col = 2; col <= 10; col++) // 2-я строка поля - 9 пустышек
        map[1][col] = static_cast<Tile*>(new Empty);

    for (col = 11; col <= 12; col++) // 2-я строка поля - 2 воды
        map[1][col] = static_cast<Tile*>(new Water);

    for (col = 1; col <= 11; col++) // 3-я строка поля - 11 пустышек
        map[2][col] = static_cast<Tile*>(new Empty);

    for (col = 1; col <= 11; col++) // 4-я строка поля - 11 пустышек
        map[3][col] = static_cast<Tile*>(new Empty);

    for (col = 1; col <= 9; col++) // 5-я строка поля - 9 пустышек
        map[4][col] = static_cast<Tile*>(new Empty);

    for (col = 10; col <= 11; col++) // 5-я строка поля - 2 коня
        map[4][col] = static_cast<Tile*>(new Horse);

    for (col = 1; col <= 11; col++) // 6-я строка поля - 11 стрелок
        map[5][col] = static_cast<Tile*>(new Arrow);

    for (col = 1; col <= 10; col++) // 7-я строка поля - 10 стрелок
        map[6][col] = static_cast<Tile*>(new Arrow);

    map[6][11] = static_cast<Tile*>(new Spinner); // 7-я строка поля - 1 вертушка

    for (col = 1; col <= 11; col++) // 8-я строка поля - 11 вертушек
        map[7][col] = static_cast<Tile*>(new Spinner);

    for (col = 1; col <= 6; col++) // 9-я строка поля - 6 льдин
        map[8][col] = static_cast<Tile*>(new Ice);

    for (col = 7; col <= 9; col++) // 9-я строка поля - 3 ловушки
        map[8][col] = static_cast<Tile*>(new Trap);

    for (col = 10; col <= 11; col++) // 9-я строка поля - 2 пушки
        map[8][col] = static_cast<Tile*>(new Gun);

    for (col = 1; col <= 2; col++) // 10-я строка поля - 2 крепости
        map[9][col] = static_cast<Tile*>(new Fortress);

    map[9][3] = static_cast<Tile*>(new Aborigine); // 10-я строка поля - 1 аборигенка

    for (col = 4; col <= 7; col++) // 10-я строка поля - 4 рома
        map[9][col] = static_cast<Tile*>(new Rum);

    for (col = 8; col <= 11; col++) // 10-я строка поля - 4 крокодила
        map[9][col] = static_cast<Tile*>(new Crocodile);

    map[10][1] = static_cast<Tile*>(new Cannibal); // 11-я строка поля - 1 людоед

    for (col = 2; col <= 3; col++) // 11-я строка поля - 2 воздушных шара
        map[10][col] = static_cast<Tile*>(new Balloon);

    map[10][4] = static_cast<Tile*>(new Plane); // 11-я строка поля - 1 самолет

    for (col = 5; col <= 11; col++) // 11-я строка поля - 7 монет
        map[10][col] = static_cast<Tile*>(new Money);

    for (col = 0; col <= 1; col++) // 12-я строка поля - 2 воды
        map[11][col] = static_cast<Tile*>(new Water);

    for (col = 2; col <= 10; col++) // 12-я строка поля - 9 монет
        map[11][col] = static_cast<Tile*>(new Money);

    for (col = 11; col <= 12; col++) // 12-я строка поля - 2 воды
        map[11][col] = static_cast<Tile*>(new Water);

    for (col = 0; col <= 12; col++) // 13-я строка поля - 11 воды
        map[12][col] = static_cast<Tile*>(new Water);

    for (row = 2; row <= 10; row++) // 1-й и 13-й столбцы поля - 9 воды в каждом столбце
    {
        map[row][0] = static_cast<Tile*>(new Water);
        map[row][12] = static_cast<Tile*>(new Water);
    }
}

void Field::shuffleMap()
{
    Tile *smallArray[9], *largeArray[11];
    int row;

    // Сортировка 1-го столбца суши

    for (row = 2; row <= 10; row++)
        smallArray[row-2] = map[row][1];

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(&smallArray[0], &smallArray[9], std::default_random_engine(seed));

    for (row = 2; row <= 10; row++)
        map[row][1] = smallArray[row-2];

    // Сортировка со 2-го по 10-й столбец суши

    for (int col = 2; col <= 10; col++)
    {
        for (row = 1; row <= 11; row++)
            largeArray[row-1] = map[row][col];

        seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(&largeArray[0], &largeArray[11], std::default_random_engine(seed));

        for (row = 1; row <= 11; row++)
            map[row][col] = largeArray[row-1];
    }

    // Сортировка 11-го столбца суши

    for (row = 2; row <= 10; row++)
        smallArray[row-2] = map[row][11];

    seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(&smallArray[0], &smallArray[9], std::default_random_engine(seed));

    for (row = 2; row <= 10; row++)
        map[row][11] = smallArray[row-2];

    // Сортировка 1-й строки суши

    seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(&map[1][2], &map[1][11], std::default_random_engine(seed));

    // Сортировка со 2-й по 10-ю строку суши

    for (row = 2; row <= 10; row++)
    {
        seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(&map[row][1], &map[row][12], std::default_random_engine(seed));
    }

    // Сортировка 11-й строки суши

    seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(&map[11][2], &map[11][11], std::default_random_engine(seed));
}


