#pragma once
#include"Game.hpp"


class Obstacle : public Object
{  
public:
    Obstacle();

    void call();
    void loadTexture();
    void setSprite();
    void moveObstacle(float speed);
    void generateObstacle();
    vector<Sprite>& getObstacle();
    sf::vector2f getRandomPosition();

private:
    Texture ObstacleTex;
    vector<Sprite> Asteroids;
    Sprite ObstacleSprite;
    Sprite newObstacle;
};

Obstacle::Obstacle()
{
    call();
}

void Obstacle::call()
{
    loadTexture();
    setSprite();
}

void Obstacle::loadTexture()
{
    ObstacleTex.loadFromFile("textures/asteroid.png");
}

void Obstacle::setSprite()
{
    ObstacleSprite.setTexture(ObstacleTex);
    ObstacleSprite.setScale(1.0, 1.0);
}

void Obstacle::moveObstacle(float speed)
{

}

void Obstacle::generateObstacle()
{

}

vector<Sprite>& Obstacle::getObstacle()
{

}

inline sf::vector2f Obstacle::getRandomPosition()
{

}