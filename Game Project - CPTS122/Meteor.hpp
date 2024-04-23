#pragma once
#include"Object.hpp"

class Meteor : public Object {
public:
    Meteor();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void moveMeteors(float speed);
    void location();

private:
};
//Constructor
Meteor::Meteor() {
    this->call();
}
//Loads texture
void Meteor::loadTexture() {
    objTex.loadFromFile("textures/rock.PNG");
}
//Sets texture and scale
void Meteor::setSprite() {
    objSprite.setTexture(objTex);
    objSprite.setScale(1.0, 0.5);
}
//Moves the meteors at a certain speed and slightly diagonal angle
void Meteor::moveMeteors(float speed) {
    for (auto& meteor : objects) {
        meteor.move(-speed, 0.1);
    }

}
//Randomly generates one of the 3 locations for the meteors
void Meteor::location() {
    int num = 0;
    num = rand() % 3 + 1;
    if (num == 1) {
        newObj.setTexture(objTex);
        newObj.setScale(.1, 0.1);

        newObj.setPosition(2850.0f, 300.0f);
        objects.push_back(newObj);
    }
    else if (num == 2) {
        newObj.setTexture(objTex);
        newObj.setScale(.1, 0.1);

        newObj.setPosition(2800.0f, 800.0f);
        objects.push_back(newObj);
    }
    else if (num == 3) {
        newObj.setTexture(objTex);
        newObj.setScale(.1, 0.1);

        newObj.setPosition(2800.0f, 1100.0f);
        objects.push_back(newObj);
    }
}

