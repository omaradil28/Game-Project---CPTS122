#pragma once
//#include"Game.hpp"
#include "PA9.hpp"

//Base function for the player and alien
class Character {
public:
	virtual void call();
	virtual void loadTexture() = 0;
	virtual void setSprite() = 0;
	virtual void movement() = 0;
	Sprite& getSprite();
	int getAnimSeq();
	void setAnimSeq(int animSeqIn);
	IntRect& getSpriteRect();
	void setSpriteRect(IntRect spriteRectIn);
	//SpriteSound charSound;

protected:
	IntRect spriteRect;
	int animationSeq;
	Texture characterTex;
	Sprite characterSprite;

};

/// Constructor
void Character::call() {
	loadTexture();
	setSprite();
}

//Getter
Sprite& Character::getSprite() {
	return characterSprite;
}

int Character::getAnimSeq() {
	return animationSeq;
}

void Character::setAnimSeq(int animSeqIn) {
	animationSeq = animSeqIn;
}

IntRect& Character::getSpriteRect() {
	return spriteRect;
}

void Character::setSpriteRect(IntRect spriteRectIn) {
	spriteRect = spriteRectIn;
}
