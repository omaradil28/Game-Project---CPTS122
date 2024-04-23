#pragma once
#include"Game.hpp"
#include "Character.hpp"

//Alien 
class Alien : public Character {
public:
	Alien();
	virtual void loadTexture();
	virtual void setSprite();
	virtual void movement();
    void animation();

};
//Constructor
Alien::Alien() {
	Character::call();
}
//Sets texture
void Alien::loadTexture() {
	characterTex.loadFromFile("textures/MonsterWalkSpriteSheet.PNG");
}
//Sets sprites scale,texture, position
void Alien::setSprite() {
    IntRect rectAlienSprite(0, 30, 120, 120);
    setSpriteRect(rectAlienSprite);
    characterSprite.setTextureRect(rectAlienSprite);
	characterSprite.setTexture(characterTex);
	characterSprite.setScale(10.0, 10.0);
	characterSprite.setPosition(-700.0f, 460.0f);
}

void Alien::movement() {

}

void Alien::animation() {

    if (getSpriteRect().left == 5850) {
        getSpriteRect().left = 0;
    }
    else {
        getSpriteRect().left += 150;
    }
    
}



