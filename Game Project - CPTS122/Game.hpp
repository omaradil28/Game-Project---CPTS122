#pragma once
#include"Contact.hpp"
#include"Textures.hpp"
#include"Menu.hpp"
#include"Collision.hpp"
#include"Player.hpp"
#include"Alien.hpp"
#include"Platform.hpp"
#include"Meteor.hpp"
#include"object.hpp"

#define WinWidth VideoMode().getDesktopMode().width // Window Height and Width
#define WinHeight VideoMode().getDesktopMode().height

class Game {
public:
    Game();
    void run();
    void runGame();
    void deleteObjects();

private:
    Player player;
    Alien alien;
    Platform platform;
    Meteor meteor;
    
    classTexture loader;

    RectangleShape menuBackground;
    RectangleShape gameBackground;
    RectangleShape optionsBackground;
    RectangleShape aboutBackground;

    Texture menuTexture;
    Texture gameTexture;
    Texture optionsTexture;
    Texture aboutTexture;

    Clock deleteClock;
    Font font;
    Text paused;
    Text paused2;
};

Game::Game() {
    srand(time(0));

    //Loads Font
    font.loadFromFile("textures/TH3 MACHINE.ttf");
    paused.setFont(font);

    //Loads Wallpapers
    loader.loadTexture(menuTexture, "textures/cool.png");
    loader.setTexture(menuBackground, menuTexture, sf::Vector2f(WinWidth, WinHeight));

    loader.loadTexture(gameTexture, "textures/space.jpeg");
    loader.setTexture(gameBackground, gameTexture, sf::Vector2f(WinWidth, WinHeight));

    loader.loadTexture(optionsTexture, "textures/options.jpeg");
    loader.setTexture(optionsBackground, optionsTexture, sf::Vector2f(WinWidth, WinHeight));

    loader.loadTexture(aboutTexture, "textures/about.jpeg");
    loader.setTexture(aboutBackground, aboutTexture, sf::Vector2f(WinWidth, WinHeight));
}

void Game::run() {
    RenderWindow MENU(VideoMode().getDesktopMode(), "Main Menu", Style::Default);
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
                    RenderWindow OPTIONS(VideoMode(WinWidth, WinHeight), "OPTIONS");
                    RenderWindow ABOUT(VideoMode(WinWidth, WinHeight), "ABOUT");

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

//Function that runs the actual game
void Game::runGame() {
    Clock platformClock;
    Time platformTime;

    Clock rockClock;
    Time rockTime;

    bool pause = false;

    RenderWindow Play(VideoMode(WinWidth, WinHeight), "Space Runner");

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
            if (newEvent.type == Event::KeyPressed) {
                if (newEvent.type == Event::KeyPressed && newEvent.key.code == sf::Keyboard::P){
                    pause = !pause;

                }
            }
        }

        if (!pause) {
            Play.clear();
            Play.draw(gameBackground);

            //Generates platforms every 2 seconds
            platformTime = platformClock.getElapsedTime();
            if (platformTime.asSeconds() >= 2) {
                platform.generatePlatform();
                platformClock.restart();
            }
            platform.movePlatforms(0.6f); //Platform speed
            for (auto& platformSprite : platform.getObjects()) {
                Play.draw(platformSprite);
            }

            //Generates rock every 10 seconds
            rockTime = rockClock.getElapsedTime();
            if (rockTime.asSeconds() >= 2) {
                meteor.location();
                rockClock.restart();
            }
            meteor.moveMeteors(1.0f); //Rock speed
            for (auto& meteorSprite : meteor.getObjects()) {
                Play.draw(meteorSprite);
            }

            //Deletes objects

            Play.draw(alien.getSprite());
            Play.draw(player.getSprite());
            player.movement();
            Play.display();

            //Collision detection for user and alien
            if (Collision::PixelPerfectTest(player.getSprite(), alien.getSprite())) {
                Play.close();
            }
            //Collision detection for user and rock
            for (const auto& meteorSprite : meteor.getObjects()) {
                if (Collision::PixelPerfectTest(player.getSprite(), meteorSprite)) {
                    Play.close();
                }
            }
        }
        else {
            paused.setString("Game Paused");
            paused.setCharacterSize(200);
            paused.setFillColor(Color::White);
            paused.setPosition(WinWidth / 2 - paused.getLocalBounds().width / 2, WinHeight / 2 - paused.getLocalBounds().height / 2);
            Play.draw(paused);
            Play.display();
        }
    }
}

void Game::deleteObjects() {
   
}