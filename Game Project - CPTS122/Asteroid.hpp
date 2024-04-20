#pragma once
#include"Object.hpp"

class Asteroid : public Object {
public:
    Asteroid();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void moveAsteroids(float speed);
    void location();
};

Asteroid::Asteroid() {
    this->call();
}

void Asteroid::loadTexture() {
    objTex.loadFromFile("textures/ast.PNG");
}

void Asteroid::setSprite() {
    objSprite.setTexture(objTex);
    objSprite.setScale(1.0, 0.5);
}

void Asteroid::moveAsteroids(float speed) {
    for (auto& asteroid : objects) {
        asteroid.move(-speed, 0.2);
    }
}

void Asteroid::location() {
    int num = 0;
    num = rand() % 2 + 1;
    if (num == 1) {
        newObj.setTexture(objTex);
        newObj.setScale(.5, 0.6);

        newObj.setPosition(2850.0f, 200.0f);
        objects.push_back(newObj);
    }
    else if (num == 2) {
        newObj.setTexture(objTex);
        newObj.setScale(.5, 0.6);

        newObj.setPosition(2800.0f, 900.0f);
        objects.push_back(newObj);
    }
}