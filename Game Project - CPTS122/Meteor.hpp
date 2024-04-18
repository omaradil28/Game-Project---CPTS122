#pragma once
#include"Object.hpp"

class Meteor : public Object {
public:
    Meteor();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void moveMeteors(float speed);
    void location();
};

Meteor::Meteor() {
    this->call();
}

void Meteor::loadTexture() {
    objTex.loadFromFile("textures/rock.PNG");
}

void Meteor::setSprite() {
    objSprite.setTexture(objTex);
    objSprite.setScale(1.0, 0.5);
}

void Meteor::moveMeteors(float speed) {
    for (auto& meteor : objects) {
        meteor.move(-speed, 0.1f);
    }
}

void Meteor::location() {
    int num = 0;
    num = rand() % 3 + 1;
    if (num == 1) {
        newObj.setTexture(objTex);
        newObj.setScale(.1, 0.1);

        newObj.setPosition(3000.0f, 800.0f);
        objects.push_back(newObj);
    }
    else if (num == 2) {
        newObj.setTexture(objTex);
        newObj.setScale(.1, 0.1);

        newObj.setPosition(3000.0f, 1050.0f);
        objects.push_back(newObj);
    }
    else if (num == 3) {
        newObj.setTexture(objTex);
        newObj.setScale(.1, 0.1);

        newObj.setPosition(3000.0f, 1300.0f);
        objects.push_back(newObj);
    }
}