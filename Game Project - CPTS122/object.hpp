#pragma once
#include"Game.hpp"

class Object {
public:
	virtual void call();
	virtual void loadTexture() = 0;
	virtual void setSprite() = 0;
	vector<Sprite>& getObjects();
	Sprite& getSprite();
protected:
	Texture objTex;
	vector<Sprite> objects;
	Sprite objSprite;
	Sprite newObj;
};

void Object::call() {
	loadTexture();
	setSprite();
}

vector<Sprite>& Object::getObjects() {
	return objects;
}

Sprite& Object::getSprite() {
	return objSprite;
}
