#pragma once
#include"Game.hpp"

class Rocket : public Object {
public:
    Rocket();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void moveRocket(float speed);
    void location();

private:
};

//Constructor
Rocket::Rocket() {
    this->call();
}
//Sets texture
void Rocket::loadTexture() {
    objTex.loadFromFile("textures/satellite.PNG");
}

//Sets texture and scale
void Rocket::setSprite() {
    objSprite.setTexture(objTex);
    objSprite.setScale(1.0, 0.5);
}
//Sets angle, and allows speed change in game.hpp
void Rocket::moveRocket(float speed) {
    for (auto& meteor : objects) {
        meteor.move(-speed, 1.9);
    }

}

//Sets the rockets position and pushes it in the vector
void Rocket::location() {
    newObj.setTexture(objTex);
    newObj.setScale(.6, 0.6);
    newObj.setRotation(170);
    newObj.setPosition(3550.0f, -100.0f);
    objects.push_back(newObj);
}