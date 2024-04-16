#pragma once
#include"Game.hpp"

class Player {
public:
	void call();
	void loadTexture();
	void setSprite();
	void movement();
	Sprite& getSprite();

private:
	Texture playerTex;
	Sprite playerSprite;
};

void Player::call() {
	loadTexture();
	setSprite();
}

void Player::loadTexture() {
	playerTex.loadFromFile("textures/leb.PNG");
}

void Player::setSprite() {
	playerSprite.setTexture(playerTex);
	playerSprite.setScale(0.2, 0.2);
	playerSprite.setPosition(400.0f, 875.0f);
}

void Player::movement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		playerSprite.move(-1.1f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		playerSprite.move(1.1f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		playerSprite.move(0.0f, -1.1f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		playerSprite.move(0.0f, 1.1f);
}

Sprite& Player::getSprite() {
	return playerSprite;
}
