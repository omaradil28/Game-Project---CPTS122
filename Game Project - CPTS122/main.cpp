#pragma once
#include "Test.hpp"
#include"Game.hpp"

int main()
{
    srand(time(0));
    Game obj;
    obj.run();

    /*Test test;
    test.testAsteroid();
    test.testPlayer();*/

    return 0;
}