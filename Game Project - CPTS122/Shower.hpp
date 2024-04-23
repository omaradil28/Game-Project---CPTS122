#pragma once
#include"Object.hpp"
//Comet - Applies for all the class undereath as well
class Shower : public Object {
public:
    Shower();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void moveShower(float, float);
    void startShower();
private:
};
//Constructor
Shower::Shower() {
    this->call();
}
//Loads texture
void Shower::loadTexture() {
    objTex.loadFromFile("textures/shower.PNG");
}
//Sets texture and scales sprite
void Shower::setSprite() {
    objSprite.setTexture(objTex);
    objSprite.setScale(1.0, 0.5);
}
//Moves the speed of the comet
void Shower::moveShower(float speed, float angle) {
    for (auto& comet : objects) {
        comet.move(speed, angle);
    }
}
//Sets position and scale
void Shower::startShower() {
    newObj.setTexture(objTex);
    newObj.setScale(.3, 0.3);

    newObj.setPosition(1200.0f, -200.0f);
    objects.push_back(newObj);
}


//Alien 1
class Alien1 : public Object {
public:
    Alien1();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void moveAlien1(float, float);
    void startAlien1();
private:
};

Alien1::Alien1() {
    this->call();
}

void Alien1::loadTexture() {
    objTex.loadFromFile("textures/ice.PNG");
}

void Alien1::setSprite() {
    objSprite.setTexture(objTex);
    objSprite.setScale(1.0, 0.5);
}

void Alien1::moveAlien1(float speed, float angle) {
    for (auto& comet : objects) {
        comet.move(speed, angle);
    }
}

void Alien1::startAlien1() {
    newObj.setTexture(objTex);
    newObj.setScale(3.0, 3.0);

    newObj.setPosition(1600.0f, -300.0f);
    objects.push_back(newObj);
}


//Alien 2
class Alien2 : public Object {
public:
    Alien2();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void moveAlien2(float, float);
    void startAlien2();
private:
};

Alien2::Alien2() {
    this->call();
}

void Alien2::loadTexture() {
    objTex.loadFromFile("textures/lava.PNG");
}

void Alien2::setSprite() {
    objSprite.setTexture(objTex);
    objSprite.setScale(1.0, 0.5);
}

void Alien2::moveAlien2(float speed, float angle) {
    for (auto& comet : objects) {
        comet.move(speed, angle);
    }
}

void Alien2::startAlien2() {
    newObj.setTexture(objTex);
    newObj.setScale(3.0, 3.0);

    newObj.setPosition(2000.0f, -150.0f);
    objects.push_back(newObj);
}


//Alien 3
class Alien3 : public Object {
public:
    Alien3();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void moveAlien3(float, float);
    void startAlien3();
private:
};

Alien3::Alien3() {
    this->call();
}

void Alien3::loadTexture() {
    objTex.loadFromFile("textures/star.PNG");
}

void Alien3::setSprite() {
    objSprite.setTexture(objTex);
    objSprite.setScale(1.0, 0.5);
}

void Alien3::moveAlien3(float speed, float angle) {
    for (auto& comet : objects) {
        comet.move(speed, angle);
    }
}

void Alien3::startAlien3() {
    newObj.setTexture(objTex);
    newObj.setScale(3.0, 3.0);

    newObj.setPosition(2400.0f, -200.0f);
    objects.push_back(newObj);
}


//Alien 4
class Alien4 : public Object {
public:
    Alien4();
    virtual void loadTexture();
    virtual void setSprite();
    virtual void moveAlien4(float, float);
    void startAlien4();
private:
};

Alien4::Alien4() {
    this->call();
}

void Alien4::loadTexture() {
    objTex.loadFromFile("textures/galaxy.PNG");
}

void Alien4::setSprite() {
    objSprite.setTexture(objTex);
    objSprite.setScale(1.0, 0.5);
}

void Alien4::moveAlien4(float speed, float angle) {
    for (auto& comet : objects) {
        comet.move(speed, angle);
    }
}

void Alien4::startAlien4() {
    newObj.setTexture(objTex);
    newObj.setScale(4.0, 4.0);

    newObj.setPosition(2800.0f, -250.0f);
    objects.push_back(newObj);
}