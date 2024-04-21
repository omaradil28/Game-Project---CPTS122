#pragma once
#include"Game.hpp"

class Object {
public:
	virtual void call();
	virtual void loadTexture() = 0;
	virtual void setSprite() = 0;
	vector<Sprite>& getObjects();
	Sprite& getSprite();
	bool outOfBounds(float screenWidth);
protected:
	Texture objTex;
	vector<Sprite> objects;
	vector<Sprite> objects2;
	vector<Sprite> objects3;
	vector<Sprite> objects4;
	vector<Sprite> objects5;
	Sprite objSprite;
	Sprite newObj;
	Clock deleteClock;
	sf::Vector2f position;
};

void Object::call() {
	loadTexture();
	setSprite();
}

vector<Sprite>& Object::getObjects() {
	return objects;
}

Sprite& Object::getSprite() {
	return objSprite;
}

inline bool Object::outOfBounds(float screenWidth)
{
	if (position.x + objSprite.getLocalBounds().width < 0 || position.x > screenWidth)
	{
		return true;
	}
	return false;
}
