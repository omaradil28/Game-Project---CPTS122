#pragma once
#include "Asteroid.hpp"
#include "Player.hpp"

//Emili: This tests the Asteroids Scale and position, and also Player movement

class Test
{
	bool isEqual(double first, double second);
public:
	void testAsteroid();
	void testPlayer();
};

bool Test::isEqual(double first, double second)
{
	return abs(first - second) < 0.001; //For checking player movement is what it is supposed to be
}

void Test::testAsteroid()
{
	Asteroid test;
	bool success = true;

	//Test location function//
	srand(0);
	test.location();
	Sprite latest = test.objects.back();

	//Testing Scale of Asteroid
	if (abs(latest.getScale().x - 0.4) < 0.001 && abs(latest.getScale().y - 0.4) < 0.001) 
	{
		cout << "Scale Set Properly" << endl;
	}
	else
	{
		cout << "Scale Set Incorrectly x; " << latest.getScale().x << " y; " << latest.getScale().y << endl;
		success = false;
	}

	//Testing Location of Asteroid
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
		//Case 1 - Up//
	auto spriteBefore = test.getSprite();
	sf::Vector2f SPosition = spriteBefore.getPosition();  //Postion Before moving
	cout << SPosition.x << ", " << SPosition.y << endl;

	test.handleMovement(1); //Movement

	auto spriteAfter = test.getSprite();
	sf::Vector2f EPosition = spriteAfter.getPosition(); //Position After moving
	cout << EPosition.x << ", " << EPosition.y << endl;

	if (isEqual(EPosition.x, SPosition.x) && isEqual(SPosition.y - 1.5, EPosition.y))
	{
		cout << "Movement Successful" << endl;
	}
	else
	{
		cout << "Movement Unsuccessful" << endl;
		success = false;
	}

		//Case 2 - Down//
	auto spriteBefore2 = test.getSprite();
	sf::Vector2f SPosition2 = spriteBefore2.getPosition();
	cout << SPosition2.x << ", " << SPosition2.y << endl;

	test.handleMovement(2);

	auto spriteAfter2 = test.getSprite();
	sf::Vector2f EPosition2 = spriteAfter2.getPosition();
	cout << EPosition2.x << ", " << EPosition2.y << endl;

	if (isEqual(EPosition2.x, SPosition2.x) && isEqual(SPosition2.y + 1.5, EPosition2.y))
	{
		cout << "Movement Successful" << endl;
	}
	else
	{
		cout << "Movement Unsuccessful" << endl;
		success = false;
	}

		//Case 3 - Left//
	auto spriteBefore3 = test.getSprite();
	sf::Vector2f SPosition3 = spriteBefore3.getPosition();
	cout << SPosition3.x << ", " << SPosition3.y << endl;

	test.handleMovement(3);

	auto spriteAfter3 = test.getSprite();
	sf::Vector2f EPosition3 = spriteAfter3.getPosition();
	cout << EPosition3.x << ", " << EPosition3.y << endl;

	if (isEqual(EPosition3.x, SPosition3.x - 1.5) && isEqual(SPosition3.y, EPosition3.y))
	{
		cout << "Movement Successful" << endl;
	}
	else
	{
		cout << "Movement Unsuccessful" << endl;
		success = false;
	}

		//Case 4 - Right//
	auto spriteBefore4 = test.getSprite();
	sf::Vector2f SPosition4 = spriteBefore4.getPosition();
	cout << SPosition4.x << ", " << SPosition4.y << endl;

	test.handleMovement(4);

	auto spriteAfter4 = test.getSprite();
	sf::Vector2f EPosition4 = spriteAfter4.getPosition();
	cout << EPosition4.x << ", " << EPosition4.y << endl;

	if (isEqual(EPosition4.x, SPosition4.x + 1.5) && isEqual(SPosition4.y, EPosition4.y))
	{
		cout << "Movement Successful" << endl;
	}
	else
	{
		cout << "Movement Unsuccessful" << endl;
		success = false;
	}


	if (success)
	{
		cout << "All Player Tests Pass" << endl;
	}
}