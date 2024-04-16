#pragma once
#include"Contact.hpp"
#include"Textures.hpp"
#include"Menu.hpp"
#include"Collision.hpp"
#include"Player.hpp"
#include"Alien.hpp"
#include"Platform.hpp"

class Game {
public:
    Game();
    void run();
    void runGame();

private:
    Player player;
    Alien alien;
    Platform platform;

    classTexture loader;

    RectangleShape menuBackground;
    RectangleShape gameBackground;
    RectangleShape optionsBackground;
    RectangleShape aboutBackground;

    Texture menuTexture;
    Texture gameTexture;
    Texture optionsTexture;
    Texture aboutTexture;
};


Game::Game() {
    player.call();

    alien.call();

    platform.call();

    loader.loadTexture(menuTexture, "textures/cool.png");
    loader.setTexture(menuBackground, menuTexture, sf::Vector2f(2000, 1300));

    loader.loadTexture(gameTexture, "textures/space.jpeg");
    loader.setTexture(gameBackground, gameTexture, sf::Vector2f(2000, 1300));

    loader.loadTexture(optionsTexture, "textures/options.jpeg");
    loader.setTexture(optionsBackground, optionsTexture, sf::Vector2f(2000, 1300));

    loader.loadTexture(aboutTexture, "textures/about.jpeg");
    loader.setTexture(aboutBackground, aboutTexture, sf::Vector2f(2000, 1300));
}


void Game::run() {
    RenderWindow MENU(VideoMode(2000, 1300), "Main Menu", Style::Default);
    Menu mainMenu(MENU.getSize().x, MENU.getSize().y);

    while (MENU.isOpen()) {
        Event event;
        while (MENU.pollEvent(event)) {
            if (event.type == Event::Closed) {
                MENU.close();
            }
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Up) {
                    mainMenu.up();
                    break;
                }
                if (event.key.code == Keyboard::Down) {
                    mainMenu.down();
                    break;
                }
                if (event.key.code == Keyboard::Return) {
                    RenderWindow OPTIONS(VideoMode(2000, 1300), "OPTIONS");
                    RenderWindow ABOUT(VideoMode(2000, 1300), "ABOUT");

                    int x = mainMenu.pressed();
                    if (x == 0) {
                        runGame();
                    }
                    if (x == 1) {
                        while (OPTIONS.isOpen()) {
                            Event newEvent;
                            while (OPTIONS.pollEvent(newEvent)) {
                                if (newEvent.type == Event::Closed) {
                                    OPTIONS.close();
                                }
                                if (newEvent.type == Event::KeyPressed) {
                                    if (newEvent.key.code == Keyboard::Escape) {
                                        OPTIONS.close();
                                    }
                                }
                            }
                            OPTIONS.clear();
                            OPTIONS.draw(optionsBackground);
                            ABOUT.close();
                            OPTIONS.display();
                        }
                    }
                    if (x == 2) {
                        while (ABOUT.isOpen()) {
                            Event newEvent;
                            while (ABOUT.pollEvent(newEvent)) {
                                if (newEvent.type == Event::Closed) {
                                    ABOUT.close();
                                }
                                if (newEvent.type == Event::KeyPressed) {
                                    if (newEvent.key.code == Keyboard::Escape) {
                                        ABOUT.close();
                                    }
                                }
                            }
                            OPTIONS.clear();
                            ABOUT.clear();
                            ABOUT.draw(aboutBackground);
                            ABOUT.display();
                        }
                    }
                    if (x == 3) {
                        MENU.close();
                        break;
                    }
                }
            }
        }
        MENU.clear();
        MENU.draw(menuBackground);
        mainMenu.draw(MENU);
        MENU.display();
    }
}

void Game::runGame() {
    Clock clock; 
    Time elapsedTime; 

    RenderWindow Play(VideoMode(2000, 1300), "Space Runner");
    while (Play.isOpen()) {
        Event newEvent;
        while (Play.pollEvent(newEvent)) {
            if (newEvent.type == Event::Closed) {
                Play.close();
            }
            if (newEvent.type == Event::KeyPressed) {
                if (newEvent.key.code == Keyboard::Escape) {
                    Play.close();
                }
            }
        }
        Play.clear();

        Play.draw(gameBackground);

        elapsedTime = clock.getElapsedTime();
        if (elapsedTime.asSeconds() >= 2) {
            platform.generatePlatform();
            clock.restart();
        }
        platform.movePlatforms(0.5f); 
        for (auto& platformSprite : platform.getPlatforms()) {
            Play.draw(platformSprite);
        }
        //Figure out how to delete the platforms that are off the screen so its not as laggy.

        Play.draw(alien.getSprite());
        Play.draw(player.getSprite());
        player.movement();

        Play.display();

        if (Collision::PixelPerfectTest(player.getSprite(), alien.getSprite())) {
            Play.close();
        }
    }
}


