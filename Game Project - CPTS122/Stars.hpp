#pragma once
#include"Game.hpp"

class StarShrink : public Object {
public:
    StarShrink();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void moveStar(float speed);
    void location();

private:
};

StarShrink::StarShrink() {
    this->call();
}

void StarShrink::loadTexture() {
    objTex.loadFromFile("textures/shrink.PNG");
}

void StarShrink::setSprite() {
    objSprite.setTexture(objTex);
    objSprite.setScale(1.0, 0.5);
}

void StarShrink::moveStar(float speed) {
    for (auto& meteor : objects) {
        meteor.move(-speed, 0.1);
    }

}

void StarShrink::location() {
    int num = 0;
    num = rand() % 3 + 1;
    if (num == 1) {
        newObj.setTexture(objTex);
        newObj.setScale(.1, 0.1);

        newObj.setPosition(2850.0f, 700.0f);
        objects.push_back(newObj);
    }
    else if (num == 2) {
        newObj.setTexture(objTex);
        newObj.setScale(.1, 0.1);

        newObj.setPosition(2800.0f, 900.0f);
        objects.push_back(newObj);
    }
    else if (num == 3) {
        newObj.setTexture(objTex);
        newObj.setScale(.1, 0.1);

        newObj.setPosition(2800.0f, 1100.0f);
        objects.push_back(newObj);
    }
}