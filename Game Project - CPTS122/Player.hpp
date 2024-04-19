#pragma once
#include"Character.hpp"
#include"PA9.hpp"

extern int playerMove;
extern IntRect rectSourceSprite;

class Player : public Character{
public:
	Player();
	virtual void loadTexture();
	virtual void setSprite();
	virtual void movement();

private:
};

Player::Player() {
	Character::call();
}

void Player::setSprite() {
	characterSprite.setTextureRect(rectSourceSprite);

	characterSprite.setTexture(characterTex);
	characterSprite.setScale(4, 4);
	characterSprite.setPosition(400.0f, 1200.0f);
}

// This changes the "Mode" for playerMove. This connects to Game.hpp that deals with animation.
void Player::movement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		playerMove = 1;
		characterSprite.move(-1.1f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		playerMove = 0;
		characterSprite.move(1.1f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		playerMove = 2;
		characterSprite.move(0.0f, -1.1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		playerMove = 2;
		characterSprite.move(0.0f, 1.1f);
	}

	if (characterSprite.getPosition().y > 1205)
		characterSprite.setPosition(characterSprite.getPosition().x, 1205);
}

void Player::loadTexture() {
	characterTex.loadFromFile("textures/PLAYER_SPRITE.PNG");
}
