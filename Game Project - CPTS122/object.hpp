#pragma once
#include"Game.hpp"
//Base function for all the objects, typically projectiles, in the game.
class Object {

	IntRect rectSprite;
public:
	virtual void call();
	virtual void loadTexture() = 0;
	virtual void setSprite() = 0;
	vector<Sprite>& getObjects();
	Sprite& getSprite();
	void setSpriteRect(IntRect rectSpriteIn);
	IntRect& getSpriteRect();

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

//Constructor
void Object::call() {
	loadTexture();
	setSprite();
}

//Getters
vector<Sprite>& Object::getObjects() {
	return objects;
}
Sprite& Object::getSprite() {
	return objSprite;
}

IntRect& Object::getSpriteRect() {
	return rectSprite;
}

void Object::setSpriteRect(IntRect rectSpriteIn) {
	rectSprite = rectSpriteIn;
}
