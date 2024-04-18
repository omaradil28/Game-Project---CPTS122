#pragma once
#include"Game.hpp"

class Character {
public:
	virtual void call();
	virtual void loadTexture() = 0;
	virtual void setSprite() = 0;
	virtual void movement() = 0;
	Sprite& getSprite();

protected:
	Texture characterTex;
	Sprite characterSprite;
};

void Character::call() {
	loadTexture();
	setSprite();
}

Sprite& Character::getSprite() {
	return characterSprite;
}