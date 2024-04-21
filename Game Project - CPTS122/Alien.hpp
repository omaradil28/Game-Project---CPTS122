#pragma once
#include"Game.hpp"
#include "Character.hpp"


class Alien : public Character {
public:
	Alien();
	virtual void loadTexture();
	virtual void setSprite();
	virtual void movement();
    void animation();

};

Alien::Alien() {
	Character::call();
}

void Alien::loadTexture() {
	characterTex.loadFromFile("textures/Red-Alien.PNG");
}

void Alien::setSprite() {
    IntRect rectAlienSprite(0, 40, 390, 376);
    setSpriteRect(rectAlienSprite);
    characterSprite.setTextureRect(rectAlienSprite);
	characterSprite.setTexture(characterTex);
	characterSprite.setScale(3.0, 3.0);
	characterSprite.setPosition(-750.0f, 225.0f);
}

void Alien::movement() {

}

void Alien::animation() {

    if (getAnimSeq() == 0) {
        getSpriteRect().top = 40;

        if (getSpriteRect().left == 0) {
            getSpriteRect().left = 3584;
        }
        else {
            getSpriteRect().left -= 512;
        }
    }

    else if (getAnimSeq() == 1) {
        getSpriteRect().top = 512;

        if (getSpriteRect().left == 0) {
            getSpriteRect().left = 3584;
        }
        else {
            getSpriteRect().left -= 512;
        }
    }
}



