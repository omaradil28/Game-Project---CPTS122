#pragma once
#include"Object.hpp"

class Spore : public Object {
public:
    Spore();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void moveSpore(float speed);
    virtual void generateSpore();
    void animation();
};

//Constructor
Spore::Spore() {
    this->call();
}

//Loads texture
void Spore::loadTexture() {
    objTex.loadFromFile("textures/Eggsplosion.PNG");
}

//Sets texture and size
void Spore::setSprite() {
    IntRect rectSpore(0, 5, 32, 27);
    setSpriteRect(rectSpore);
    setSpriteRect(getSpriteRect());
    objSprite.setTexture(objTex);
    objSprite.setScale(15, 15);
}

//Sets speed. Gives the illusion that the zeno is on top of the platform
void Spore::moveSpore(float speed) {
    for (auto& platform : objects) {
        platform.move(-speed, 0.0f);
    }
}

//Sets scale and position then pushes into vector
void Spore::generateSpore() {
    newObj.setTexture(objTex);
    newObj.setScale(15, 15);
    newObj.setPosition(2850.0f, 1100.0f);
    objects.push_back(newObj);
}

void Spore::animation() {
    if (getSpriteRect().left == 96 && getSpriteRect().top == 5) {
        getSpriteRect().left = 0;
        getSpriteRect().top = 37;
    }
    else if (getSpriteRect().left == 96 && getSpriteRect().top == 37) {
        getSpriteRect().left = 0;
        getSpriteRect().top = 5;
    }
    else {
        getSpriteRect().left += 32;
    }
}