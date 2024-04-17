#pragma once
#include"Object.hpp"

class Platform : public Object {
public:
    Platform();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void movePlatforms(float speed);
    virtual void generatePlatform();
};

Platform::Platform() {
    this->call();
}

void Platform::loadTexture() {
    objTex.loadFromFile("textures/plat.PNG");
}

void Platform::setSprite() {
    objSprite.setTexture(objTex);
    objSprite.setScale(1.0, 0.5);
}

void Platform::movePlatforms(float speed) {
    for (auto& platform : objects) {
        platform.move(-speed, 0.0f);
    }
}

void Platform::generatePlatform() {
    newObj.setTexture(objTex);
    newObj.setScale(1.0, 0.5);
 
    newObj.setPosition(2000.0f, 1100.0f);
    objects.push_back(newObj);
}



