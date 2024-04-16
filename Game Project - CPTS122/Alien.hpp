#pragma once
#include"Game.hpp"

class Alien : public Character {
public:
	Alien();
	virtual void loadTexture();
	virtual void setSprite();
	virtual void movement();

};

Alien::Alien() {
	Character::call();
}

void Alien::loadTexture() {
	characterTex.loadFromFile("textures/alien.PNG");
}

void Alien::setSprite() {
	characterSprite.setTexture(characterTex);
	characterSprite.setScale(1.0, 1.0);
	characterSprite.setPosition(-350.0f, 225.0f);
}

void Alien::movement() {

}


