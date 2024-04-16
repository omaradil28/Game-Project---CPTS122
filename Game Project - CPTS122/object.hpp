#pragma once
#include"Game.hpp"

class Object {
public:
	virtual void call();

	//template<class A, class B>
	//void eraseObjects(std::remove_if<A,B>);

	virtual void loadTexture() = 0;
	virtual void setSprite() = 0;
	vector<Sprite>& getObjects();

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