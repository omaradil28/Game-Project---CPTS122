#pragma once
#include "Asteroid.hpp"
#include "Player.hpp"

class Test
{
	bool isEqual(double first, double second);
public:
	void testAsteroid();
	void testPlayer();
};

bool Test::isEqual(double first, double second)
{
	return abs(first - second) < 0.001;
}

void Test::testAsteroid()
{
	Asteroid test;
	bool success = true;

	//Test location function//
	srand(0);
	test.location();
	Sprite latest = test.objects.back();

	if (abs(latest.getScale().x - 0.5) < 0.001 && abs(latest.getScale().y - 0.6) < 0.001)
	{
		cout << "Scale Set Properly" << endl;
	}
	else
	{
		cout << "Scale Set Incorrectly x; " << latest.getScale().x << " y; " << latest.getScale().y << endl;
		success = false;
	}

	srand(0);
	if (rand() % 2 + 1 == 1)
	{
		if (latest.getPosition().x == 2850.0f && latest.getPosition().y == 200.0f)
		{
			cout << "Position Set Correctly" << endl;
		}
		else
		{
			cout << "Position Set Incorrectly" << endl;
			success = false;
		}
	}
	else
	{
		if (latest.getPosition().x == 2800.0f && latest.getPosition().y == 900.0f)
		{
			cout << "Position Set Correctly" << endl;
		}
		else
		{
			cout << "Position Set Incorrectly" << endl;
			success = false;
		}
	}

	if (success)
	{
		cout << "All Asteroid Tests Pass" << endl;
	}
}

void Test::testPlayer()
{
	Player test;

	bool success = true;

	//Test player movement//
		//Case 1//
	/*sf::Vector2f startPosition = test.getSprite().getPostition();

	test.handleMovement(1);

	sf::Vector2f endPosition = test.getSprite().getPosition();

	if (isEqual(endPosition.x, startPosition.x) && isEqual(startPosition.y - 1.5, endPosition.y))
	{
		cout << "Movement Successful" << endl;
	}
	else
	{
		cout << "Movement Unsuccessful" << endl;
		success = false;
	}*/

		//Case 2//
	/*sf::Vector2f startPosition = test.getSprite().getPostition();

	test.handleMovement(2);

	sf::Vector2f endPosition = test.getSprite().getPosition();

	if (isEqual(endPosition.x, startPosition.x) && isEqual(startPosition.y - 1.5, endPosition.y))
	{
		cout << "Movement Successful" << endl;
	}
	else
	{
		cout << "Movement Unsuccessful" << endl;
	}*/
}