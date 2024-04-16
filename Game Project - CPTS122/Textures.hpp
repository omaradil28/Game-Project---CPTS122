#pragma once
#include"PA9.hpp"

class classTexture {
public:
    classTexture() {}
    bool loadTexture(Texture&, const std::string&);
    void setTexture(RectangleShape&, Texture&, const Vector2f&);
private:

};

//Loads Textures
bool classTexture::loadTexture(Texture& texture, const std::string& file) {
    return texture.loadFromFile(file);
}

//Sets textures for wallpapers
void classTexture::setTexture(RectangleShape& background, Texture& texture, const Vector2f& size) {
    background.setSize(size);
    background.setTexture(&texture);
}
