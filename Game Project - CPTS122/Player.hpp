
// Player.hpp
#pragma once
#include"Character.hpp"
#include"PA9.hpp"

class Player : public Character {
public:
	Player();
	virtual void loadTexture();
	virtual void setSprite();
	virtual void movement();
	void animation();
private:

};

//Contructor
Player::Player() {
	Character::call();
}

//Sets sprite size, texture, scale, position, and animation variables.
void Player::setSprite() {
    IntRect rectPlayerSprite(0, 0, 73, 73);
    setSpriteRect(rectPlayerSprite);
	characterSprite.setTextureRect(getSpriteRect());
	characterSprite.setTexture(characterTex);
	characterSprite.setScale(4, 4);
	characterSprite.setPosition(1000.0f, 1205.0f);
}

// This changes the animation sequence for the player based on movement.
void Player::movement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        setAnimSeq(2);
        characterSprite.move(0.0f, -1.5f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        setAnimSeq(2);
		characterSprite.move(0.0f, 1.5f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        setAnimSeq(1);
        characterSprite.move(-1.5f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        setAnimSeq(0);
        characterSprite.move(1.5f, 0.0f);
	}

	if (characterSprite.getPosition().y > 1205)
		characterSprite.setPosition(characterSprite.getPosition().x, 1205);
}

//Loads texture
void Player::loadTexture() {
	characterTex.loadFromFile("textures/PLAYER_SPRITE.PNG");
}

void Player::animation(){
    if (getAnimSeq() == 0) {
        getSpriteRect().height = 73;
        getSpriteRect().top = 73;

        if (getSpriteRect().left == 58) {
            getSpriteRect().left = 0;
            getSpriteRect().width = 58;
        }
        else {
            getSpriteRect().left = 58;
            getSpriteRect().width = 56;
        }
    }

    else if (getAnimSeq() == 1) {
        getSpriteRect().height = 73;
        getSpriteRect().top = 292;
        getSpriteRect().width = 48;

        if (getSpriteRect().left == 96) {
            getSpriteRect().left = 48;
        }
        else {
            getSpriteRect().left = 96;
        }
    }
    else {
        getSpriteRect().top = 0;
        getSpriteRect().height = 73;
        getSpriteRect().width = 46;


        if (getSpriteRect().left == 46) {
            getSpriteRect().left = 0;
        }
        else {
            getSpriteRect().left = 46;
        }
    }
}
