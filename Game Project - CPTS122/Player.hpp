
// Player.hpp
#pragma once
#include"Character.hpp"
#include"PA9.hpp"

extern int playerMove;
IntRect rectPlayerSprite(0, 0, 46, 73);

class Player : public Character {
public:
	Player();
	virtual void loadTexture();
	virtual void setSprite();
	virtual void movement();
	void animation();
	void shrink();
private:

};

Player::Player() {
	Character::call();
}

void Player::setSprite() {
	characterSprite.setTextureRect(rectPlayerSprite);
	characterSprite.setTexture(characterTex);
	characterSprite.setScale(4, 4);
	characterSprite.setPosition(400.0f, 1205.0f);
}

// This changes the "Mode" for playerMove. This connects to Game.hpp that deals with animation.
void Player::movement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		playerMove = 2;
		characterSprite.move(0.0f, -1.5f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		playerMove = 2;
		characterSprite.move(0.0f, 1.5f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		playerMove = 1;
		characterSprite.move(-1.5f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		playerMove = 0;
		characterSprite.move(1.5f, 0.0f);
	}

	if (characterSprite.getPosition().y > 1205)
		characterSprite.setPosition(characterSprite.getPosition().x, 1205);
}

void Player::loadTexture() {
	characterTex.loadFromFile("textures/PLAYER_SPRITE.PNG");
}

void Player::shrink() {
	characterSprite.setScale(2.0, 2.0);
}


void Player::animation(){
    if (playerMove == 0) {
        rectPlayerSprite.height = 73;
        rectPlayerSprite.top = 73;

        if (rectPlayerSprite.left == 58) {
            rectPlayerSprite.left = 0;
            rectPlayerSprite.width = 58;
        }
        else {
            rectPlayerSprite.left = 58;
            rectPlayerSprite.width = 56;
        }
    }

    else if (playerMove == 1) {
        rectPlayerSprite.height = 73;
        rectPlayerSprite.top = 292;
        rectPlayerSprite.width = 48;

        if (rectPlayerSprite.left == 96) {
            rectPlayerSprite.left = 48;
        }
        else {
            rectPlayerSprite.left = 96;
        }
    }
    else {
        rectPlayerSprite.top = 0;
        rectPlayerSprite.height = 73;
        rectPlayerSprite.width = 46;


        if (rectPlayerSprite.left == 46) {
            rectPlayerSprite.left = 0;
        }
        else {
            rectPlayerSprite.left = 46;
        }
    }
}
