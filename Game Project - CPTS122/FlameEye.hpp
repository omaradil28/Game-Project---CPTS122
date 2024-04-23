#pragma once
#include"Object.hpp"

class FlameEye : public Object {
public:
    FlameEye();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void moveFlameEye(float speed);
    void location();
    void animation();
};
//Constructor
FlameEye::FlameEye() {
    this->call();
}
//Loads texture
void FlameEye::loadTexture() {
    objTex.loadFromFile("textures/BlueEyeMonster.PNG");
}
//Sets texture and scale
void FlameEye::setSprite() {
    IntRect rectFlameEye(0, 0, 32, 24);
    setSpriteRect(rectFlameEye);
    objSprite.setTextureRect(getSpriteRect());
    objSprite.setTexture(objTex);
    objSprite.setScale(5, 5);
}

//Moves the flameeye at a certain speed and slightly diagonal angle
void FlameEye::moveFlameEye(float speed) {
    for (auto& FlameEye : objects) {
        FlameEye.move(-speed, 0.1);
    }

}
//Randomly generates one of the 3 locations for the flameeyes
void FlameEye::location() {

    int num = 0;
    num = rand() % 3 + 1;
    if (num == 1) {
        animation();
        newObj.setTextureRect(objSprite.getTextureRect());
        newObj.setTexture(objTex);
        newObj.setScale(5, 5);
        newObj.setPosition(2850.0f, 300.0f);
        objects.push_back(newObj);
        
    }
    else if (num == 2) {
        newObj.setTextureRect(objSprite.getTextureRect());
        newObj.setTexture(objTex);
        newObj.setScale(5, 5);
        newObj.setPosition(2800.0f, 800.0f);
        objects.push_back(newObj);
    }
    else if (num == 3) {
        newObj.setTextureRect(objSprite.getTextureRect());
        newObj.setTexture(objTex);
        newObj.setScale(5, 5);
        newObj.setPosition(2800.0f, 1100.0f);
        objects.push_back(newObj);

    }
}

void FlameEye::animation() {
    if (getSpriteRect().left == 192) {
        getSpriteRect().left = 0;
    }
    else {
        getSpriteRect().left += 32;
    }
} 

