#pragma once
#include"MainCharacter.hpp"
#include"PA9.hpp"

class Player : public Character{
public:
	Player();
	virtual void loadTexture();
	virtual void setSprite();
	virtual void movement();
};

Player::Player() {
	Character::call();
}

void Player::setSprite() {
	characterSprite.setTexture(characterTex);
	characterSprite.setScale(0.18, 0.18);
	characterSprite.setPosition(400.0f, 895.0f);
}

void Player::movement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		characterSprite.move(-1.1f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		characterSprite.move(1.1f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		characterSprite.move(0.0f, -1.1f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		characterSprite.move(0.0f, 1.1f);
}

void Player::loadTexture() {
	characterTex.loadFromFile("textures/leb.PNG");
}
