#pragma once
#include"Game.hpp"

class Character {
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

void Character::call() {
	loadTexture();
	setSprite();
}

void Character::loadTexture() {
	playerTex.loadFromFile("textures/leb.PNG");
}

void Character::setSprite() {
	playerSprite.setTexture(playerTex);
	playerSprite.setScale(0.18, 0.18);
	playerSprite.setPosition(400.0f, 895.0f);
}

void Character::movement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		playerSprite.move(-1.1f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		playerSprite.move(1.1f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		playerSprite.move(0.0f, -1.1f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		playerSprite.move(0.0f, 1.1f);
}

Sprite& Character::getSprite() {
	return playerSprite;
}