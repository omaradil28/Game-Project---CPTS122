#pragma once
#include "Asteroid.hpp"

class Test
{
public:
	void testAsteroid();
};


void Test::testAsteroid()
{
	Asteroid test;
	bool success = true;

	////Test resource/image loaded for asteroid//
	if (test.objTex.hasImage())
	{
		cout << "Asteroid Loaded Image" << endl;
	}
	else
	{
		cout << "Asteroid Failed to Load" << endl;

		success = false;
	}

	//Test location function//
	srand(0);
	test.location();
	Sprite latest = test.objects.pop_back();

	if (latest.getScale().x == 0.5 && latest.getScale().y == 0.6)
	{
		cout << "Scale Set Properly" << endl;
	}
	else
	{
		cout << "Scale Set Incorrectly" << endl;
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