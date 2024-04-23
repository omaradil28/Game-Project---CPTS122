#pragma once
#include"Object.hpp"

class Zeno : public Object {
public:
    Zeno();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void moveZeno(float speed);
    virtual void generateZeno();
};
//Constructor
Zeno::Zeno() {
    this->call();
}
//Loads texture
void Zeno::loadTexture() {
    objTex.loadFromFile("textures/zeno.PNG");
}
//Sets texture and size
void Zeno::setSprite() {
    objSprite.setTexture(objTex);
    objSprite.setScale(0.5, 0.5);
}
//Sets speed. Gives the illusion that the zeno is on top of the platform
void Zeno::moveZeno(float speed) {
    for (auto& platform : objects) {
        platform.move(-speed, 0.0f);
    }
}
//Sets scale and position then pushes into vector
void Zeno::generateZeno() {
    newObj.setTexture(objTex);
    newObj.setScale(0.4, 0.4);
    newObj.setPosition(2850.0f, 960.0f);
    objects.push_back(newObj);
}
