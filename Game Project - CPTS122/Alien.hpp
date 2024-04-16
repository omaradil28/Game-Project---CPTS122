#pragma once
#include"Game.hpp"

class Alien : public Character {
public:
	void call();
	void loadTexture();
	void setSprite();
	void movement();
	Sprite& getSprite();

private:
	Texture alienTex;
	Sprite alienSprite;
};

void Alien::call() {
	loadTexture();
	setSprite();
}

void Alien::loadTexture() {
	alienTex.loadFromFile("textures/alien.PNG");
}

void Alien::setSprite() {
	alienSprite.setTexture(alienTex);
	alienSprite.setScale(1.0, 1.0);
	alienSprite.setPosition(-350.0f, 225.0f);
}

void Alien::movement() {

}

Sprite& Alien::getSprite() {
	return alienSprite;
}
