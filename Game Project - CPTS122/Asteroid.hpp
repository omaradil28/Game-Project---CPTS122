#pragma once
#include"Object.hpp"

class Test;

class Asteroid : public Object {
public:
    Asteroid();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void moveAsteroids(float speed);
    void location();
    friend Test;
};

//Constructor
Asteroid::Asteroid() {
    this->call();
}

//Loads texture
void Asteroid::loadTexture() {
    objTex.loadFromFile("textures/asteroid.PNG");
}


//Sets texture and scale
void Asteroid::setSprite() {
    objSprite.setTexture(objTex);
    objSprite.setScale(0.4, 0.4);
}
//Moves asteroid at a slight angle and certain speed
void Asteroid::moveAsteroids(float speed) {
    for (auto& asteroid : objects) {
        asteroid.move(-speed, 0.2);
    }
}

//Prints asteroid at one of two locations
void Asteroid::location() {
    int num = 0;
    num = rand() % 2 + 1;
    if (num == 1) {
        newObj.setTexture(objTex);
        newObj.setScale(0.4, 0.4);

        newObj.setPosition(2850.0f, 200.0f);
        objects.push_back(newObj);
    }
    else if (num == 2) {
        newObj.setTexture(objTex);
        newObj.setScale(0.4, 0.4);

        newObj.setPosition(2800.0f, 900.0f);
        objects.push_back(newObj);
    }
}