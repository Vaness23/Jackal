#include "field.h"
#include <chrono>
#include <random>
#include <cmath>

template <class T>
Field<T>::Field()
{
    fill(); // заполнение поля клетками
    seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffleMap();
    shuffleMap();
    coins = 37;
}

template <class T>
Index Field<T>::getTileIndex(T tile)
{
    Index coordinates;
    coordinates.x = -1;
    coordinates.y = -1;

    for (int i = 0; i < 13 && coordinates.x == -1; i++)
        for (int j = 0; j < 13 && coordinates.x == -1; j++)
            if (map[i][j] == tile)
            {
                coordinates.x = j;
                coordinates.y = i;
            }

    return coordinates;
}

template <class T>
bool Field<T>::isPirateMoveOk(T current, T next)
{
    //-------------------С суши или моря на корабль-------------------
    if (next->getType() == ship)
        return isPirateToShipOk(current, next);

    Index currentIndex, nextIndex = getTileIndex(next);

    // -------------------С корабля на сушу------------------
    if (current->getType() == ship && next->getTileType() != water)
    {
        current = static_cast<T>(current->parentItem());
        currentIndex = getTileIndex(current);
        if (abs(nextIndex.x - currentIndex.x) == 1
                && nextIndex.y == currentIndex.y
            || abs(nextIndex.y - currentIndex.y) == 1
                && nextIndex.x == currentIndex.x)
            return true;
        else
            return false;
    }

    // ------------------С корабля в воду----------------------
    if (current->getType() == ship && next->getTileType() == water)
        return false;

    currentIndex = getTileIndex(current);


    // -------------------С суши в воду-----------------
    if (current->getTileType() != water && next->getTileType() == water)
    {
        // если пирата перебрасывает со стрелки
        if (current->getTileType() == arrow)
            return checkDirection(current, nextIndex);
        //пират не может сам залезть в воду
        else
            return false;
    }

    // ----------------------В воде-----------------------
    if (current->getTileType() == water && next->getTileType() == water)
    {
        if (abs(nextIndex.x - currentIndex.x) == 1 /*&& nextIndex.y == currentIndex.y*/
                || abs(nextIndex.y - currentIndex.y) == 1 /*&& nextIndex.x == currentIndex.x*/)
            return true;
    }

    // -----------------Из воды на сушу------------------
    else if (current->getTileType() == water && next->getTileType() != water)
        return false;

    // ---------------------По суше-------------------------
    else if ((abs(nextIndex.x - currentIndex.x) <= 1)
             && (abs(nextIndex.y - currentIndex.y) <= 1))
        return checkDirection(current, nextIndex);
    else
        return false;
}

template <class T>
bool Field<T>::isShipMoveOk(T current, T next)
{
    Index currentIndex = getTileIndex(current);
    Index nextIndex = getTileIndex(next);

    //вертикально двигающиеся корабли
    if (nextIndex.y >= 2 && nextIndex.y <= 10
        && (
            currentIndex.x == 0 && nextIndex.x == 0
                && abs(nextIndex.y - currentIndex.y) == 1
            || currentIndex.x == 12 && nextIndex.x == 12
                && abs(nextIndex.y - currentIndex.y) == 1
           )
        )
        return true;

    //горизонтально двигающиеся корабли
    if (nextIndex.x >= 2 && nextIndex.x <= 10
             && (
                currentIndex.y == 0 && nextIndex.y == 0
                    && abs(nextIndex.x - currentIndex.x) == 1
                || currentIndex.y == 12 && nextIndex.y == 12
                    && abs(nextIndex.x - currentIndex.x) == 1
                )
        )
            return true;
    else
        return false;
}

template <class T>
bool Field<T>::isPirateToShipOk(T pirateTile, T shipTile)
{
    Index pirateIndex = getTileIndex(pirateTile);
    Index shipIndex = getTileIndex(shipTile);

    if (abs(pirateIndex.x - shipIndex.x) <= 1
            && abs(pirateIndex.y - shipIndex.y) <= 1)
        return checkDirection(pirateTile, shipIndex);
    else
        return false;
}

template <class T>
void Field<T>::fill()
{
    int col, row;

    for (col = 0; col <= 12; col++) // 1-я строка поля - 11 воды
        map[0][col] = static_cast<T>(new Water);

    for (col = 0; col <= 1; col++) // 2-я строка поля - 2 воды
        map[1][col] = static_cast<T>(new Water);

    for (col = 2; col <= 10; col++) // 2-я строка поля - 9 пустышек
        map[1][col] = static_cast<T>(new Empty);

    for (col = 11; col <= 12; col++) // 2-я строка поля - 2 воды
        map[1][col] = static_cast<T>(new Water);

    for (col = 1; col <= 11; col++) // 3-я строка поля - 11 пустышек
        map[2][col] = static_cast<T>(new Empty);

    for (col = 1; col <= 11; col++) // 4-я строка поля - 11 пустышек
        map[3][col] = static_cast<T>(new Empty);

    for (col = 1; col <= 9; col++) // 5-я строка поля - 9 пустышек
        map[4][col] = static_cast<T>(new Empty);

    for (col = 10; col <= 11; col++) // 5-я строка поля - 2 коня
        map[4][col] = static_cast<T>(new Horse);

    for (col = 1; col <= 11; col++) // 6-я строка поля - 11 стрелок
        map[5][col] = static_cast<T>(new Arrow);

    for (col = 1; col <= 10; col++) // 7-я строка поля - 10 стрелок
        map[6][col] = static_cast<T>(new Arrow);

    map[6][11] = static_cast<T>(new Spinner); // 7-я строка поля - 1 вертушка

    for (col = 1; col <= 11; col++) // 8-я строка поля - 11 вертушек
        map[7][col] = static_cast<T>(new Spinner);

    for (col = 1; col <= 6; col++) // 9-я строка поля - 6 льдин
        map[8][col] = static_cast<T>(new Ice);

    for (col = 7; col <= 9; col++) // 9-я строка поля - 3 ловушки
        map[8][col] = static_cast<T>(new Trap);

    for (col = 10; col <= 11; col++) // 9-я строка поля - 2 пушки
        map[8][col] = static_cast<T>(new Gun);

    for (col = 1; col <= 2; col++) // 10-я строка поля - 2 крепости
        map[9][col] = static_cast<T>(new Fortress);

    map[9][3] = static_cast<T>(new Aborigine); // 10-я строка поля - 1 аборигенка

    for (col = 4; col <= 7; col++) // 10-я строка поля - 4 рома
        map[9][col] = static_cast<T>(new Rum);

    for (col = 8; col <= 11; col++) // 10-я строка поля - 4 крокодила
        map[9][col] = static_cast<T>(new Crocodile);

    map[10][1] = static_cast<T>(new Cannibal); // 11-я строка поля - 1 людоед

    for (col = 2; col <= 3; col++) // 11-я строка поля - 2 воздушных шара
        map[10][col] = static_cast<T>(new Balloon);

    map[10][4] = static_cast<T>(new Plane); // 11-я строка поля - 1 самолет

    for (col = 5; col <= 9; col++) // 11-я строка поля - 5 сундуков по 1
        map[10][col] = static_cast<T>(new Money(1));

    for (col = 10; col <= 11; col++) // 11-я строка поля - 2 сундука по 2
        map[10][col] = static_cast<T>(new Money(2));

    for (col = 0; col <= 1; col++) // 12-я строка поля - 2 воды
        map[11][col] = static_cast<T>(new Water);

    for (col = 2; col <= 4; col++) // 12-я строка поля - 3 сундука по 2
        map[11][col] = static_cast<T>(new Money(2));

    for (col = 5; col <= 7; col++) // 12-я строка поля - 3 сундука по 3
        map[11][col] = static_cast<T>(new Money(3));

    for (col = 8; col <= 9; col++) // 12-я строка поля - 2 сундука по 4
        map[11][col] = static_cast<T>(new Money(4));

    map[11][10] = static_cast<T>(new Money(5));// 12-я строка поля - 1 сундук с 5

    for (col = 11; col <= 12; col++) // 12-я строка поля - 2 воды
        map[11][col] = static_cast<T>(new Water);

    for (col = 0; col <= 12; col++) // 13-я строка поля - 11 воды
        map[12][col] = static_cast<T>(new Water);

    // 1-й и 13-й столбцы поля - 9 воды в каждом столбце
    for (row = 2; row <= 10; row++)
    {
        map[row][0] = static_cast<T>(new Water);
        map[row][12] = static_cast<T>(new Water);
    }
}

template <class T>
bool Field<T>::checkDirection(T current, Index nextIndex)
{
    Index currentIndex = getTileIndex(current);
    bool result = false;
    // Смещение:
    // север: х = 0, у = 1
    if (current->movement[N] && nextIndex.x - currentIndex.x == 0
            && nextIndex.y - currentIndex.y == -1)
        return true;

    // северо-восток: х = 1, у = 1
    if (current->movement[NE] && nextIndex.x - currentIndex.x == 1
            && nextIndex.y - currentIndex.y == -1)
        return true;

    // восток: х = 1, у = 0
    if (current->movement[E] && nextIndex.x - currentIndex.x == 1
            && nextIndex.y - currentIndex.y == 0)
        return true;

    // юго-восток: х = 1, у = -1
    if (current->movement[SE] && nextIndex.x - currentIndex.x == 1
            && nextIndex.y - currentIndex.y == 1)
        return true;

    // юг: х = 0, у = -1
    if (current->movement[S] && nextIndex.x - currentIndex.x == 0
            && nextIndex.y - currentIndex.y == 1)
        return true;

    // юго-запад: х = -1, у  = -1
    if (current->movement[SW] && nextIndex.x - currentIndex.x == -1
            && nextIndex.y - currentIndex.y == 1)
        return true;

    // запад: х = -1, у = 0
    if (current->movement[W] && nextIndex.x - currentIndex.x == -1
            && nextIndex.y - currentIndex.y == 0)
        return true;

    // северо-запад: х = -1, у = 1
    if (current->movement[NW] && nextIndex.x - currentIndex.x == -1
            && nextIndex.y - currentIndex.y == -1)
        return true;

    return false;
}

template <class T>
void Field<T>::shuffleMap()
{
    std::default_random_engine engine(seed);
    T smallArray[9], largeArray[11];
    int row;

    // Сортировка 1-го столбца суши

    for (row = 2; row <= 10; row++)
        smallArray[row-2] = map[row][1];
//    seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(&smallArray[0], &smallArray[9], engine);
            //std::default_random_engine(seed));

    for (row = 2; row <= 10; row++)
        map[row][1] = smallArray[row-2];

    // Сортировка со 2-го по 10-й столбец суши

    for (int col = 2; col <= 10; col++)
    {
        for (row = 1; row <= 11; row++)
            largeArray[row-1] = map[row][col];

//        seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(&largeArray[0], &largeArray[11], engine);
                //std::default_random_engine(seed));

        for (row = 1; row <= 11; row++)
            map[row][col] = largeArray[row-1];
    }

    // Сортировка 11-го столбца суши

    for (row = 2; row <= 10; row++)
        smallArray[row-2] = map[row][11];

//    seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(&smallArray[0], &smallArray[9], engine);
            //std::default_random_engine(seed));

    for (row = 2; row <= 10; row++)
        map[row][11] = smallArray[row-2];

    // Сортировка 1-й строки суши

//    seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(&map[1][2], &map[1][11], engine);//std::default_random_engine(seed));

    // Сортировка со 2-й по 10-ю строку суши

    for (row = 2; row <= 10; row++)
    {
//        seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(&map[row][1], &map[row][12], engine);
                //std::default_random_engine(seed));
    }

    // Сортировка 11-й строки суши

//    seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(&map[11][2], &map[11][11], engine);//std::default_random_engine(seed));
}

template class Field<Tile*>;
