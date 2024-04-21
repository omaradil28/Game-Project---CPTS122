#pragma once
#include"Game.hpp"


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

protected:
	IntRect spriteRect;
	int animationSeq;
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
