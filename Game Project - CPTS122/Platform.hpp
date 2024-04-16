#pragma once
#include"Game.hpp"
class Platform : public Character {
public:
    Platform();
    void call();
    void loadTexture();
    void setSprite();
    void movePlatforms(float speed);
    void generatePlatform();
    vector<Sprite>& getPlatforms();

private:
    Texture platTex;
    vector<Sprite> platforms;
    Sprite platSprite;
    Sprite newPlat;
};

Platform::Platform() {
    call();
}

void Platform::call() {
    loadTexture();
    setSprite();
}

void Platform::loadTexture() {
    platTex.loadFromFile("textures/plat.PNG");
}

void Platform::setSprite() {
    platSprite.setTexture(platTex);
    platSprite.setScale(1.0, 0.5);
}

void Platform::movePlatforms(float speed) {
    for (auto& platform : platforms) {
        platform.move(-speed, 0.0f);
    }
}

void Platform::generatePlatform() {
    newPlat.setTexture(platTex);
    newPlat.setScale(1.0, 0.5);
 
    newPlat.setPosition(2000.0f, 1100.0f);
    platforms.push_back(newPlat);
}

vector<Sprite>& Platform::getPlatforms() {
    return platforms;
}


