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
//Constructor
Platform::Platform() {
    this->call();
}
//Loads texture
void Platform::loadTexture() {
    objTex.loadFromFile("textures/RunnerTileSet1.PNG");
}
//Sets texture and scale
void Platform::setSprite() {
    objSprite.setTexture(objTex);
    objSprite.setScale(1.0, 0.5);
}
//Moves platform horizontally at a certain speed
void Platform::movePlatforms(float speed) {
    for (auto& platform : objects) {
        platform.move(-speed, 0.0f);
    }
}
//Generates them in the same spot every time
void Platform::generatePlatform() {
    newObj.setTexture(objTex);
    newObj.setScale(5, 5);
 
    newObj.setPosition(3000.0f, 1400.0f);
    objects.push_back(newObj);
}



