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

IntRect rectSourceSprite(0, 0, 46, 73);

int playerMove;

class Game {
public:
    Game();
    void run();
    void runGame(RenderWindow& window);
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

    int restart = 0;
};

Game::Game() {

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
    RenderWindow WINDOW(VideoMode().getDesktopMode(), "Main Menu", Style::Default);
    Menu mainMenu(WINDOW.getSize().x, WINDOW.getSize().y);

    while (WINDOW.isOpen()) {

        Event event;
        while (WINDOW.pollEvent(event)) {
            if (event.type == Event::Closed) {
                WINDOW.close();
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

                    int x = mainMenu.pressed();
                    if (x == 0) {
                        WINDOW.clear();
                        runGame(WINDOW);

                    }
                    if (x == 1) {
                        WINDOW.clear();
                        WINDOW.draw(optionsBackground);
                        WINDOW.display();

                        while (true) {
                            Event newEvent;

                            while (WINDOW.pollEvent(newEvent)) {
                                if (newEvent.type == Event::Closed) {
                                    WINDOW.close();
                                }

                                if (newEvent.type == Event::KeyPressed) {
                                    goto MENUSCREEN;
                                }
                            }

                        }

                    }

                    if (x == 2) {
                        WINDOW.clear();
                        WINDOW.draw(aboutBackground);
                        WINDOW.display();

                        while (true) {
                            Event newEvent;

                            while (WINDOW.pollEvent(newEvent)) {
                                if (newEvent.type == Event::Closed) {
                                    WINDOW.close();
                                }

                                if (newEvent.type == Event::KeyPressed) {
                                    goto MENUSCREEN;
                                }
                            }

                        }

                    }
                MENUSCREEN:

                    if (x == 3) {
                        WINDOW.close();
                        break;
                    }

                }

            }
        }
        WINDOW.clear();
        WINDOW.draw(menuBackground);
        mainMenu.draw(WINDOW);
        WINDOW.display();
    }

}

//Function that runs the actual game
void Game::runGame(RenderWindow& Play) {
    Clock platformClock;
    Time platformTime;

    Clock rockClock;
    Time rockTime;

    Clock playerClock;


    bool pause = false;


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

            //Generates rock every 7 seconds
            rockTime = rockClock.getElapsedTime();

            if (rockTime.asSeconds() >= 7) {
                meteor.location();
                rockClock.restart();
            }
            meteor.moveMeteors(2.5f); //Rock speed
            for (auto& meteorSprite : meteor.getObjects()) {
                Play.draw(meteorSprite);
            }

            //Deletes objects
           
            
            playerMove = 2;
            player.getSprite().setTextureRect(rectSourceSprite);
            Play.draw(alien.getSprite());
            Play.draw(player.getSprite());
            player.movement();
            Play.display();


            // Player Animation Code. Gets reads from the player movement function, then animates accordingly.
            if (playerClock.getElapsedTime().asSeconds() > 1.0f) {

                if (playerMove == 0) {
                    rectSourceSprite.height = 73;
                    rectSourceSprite.top = 73;

                    if (rectSourceSprite.left == 58) {
                        rectSourceSprite.left = 0;
                        rectSourceSprite.width = 58;
                    }
                    else {
                        rectSourceSprite.left = 58;
                        rectSourceSprite.width = 56;
                    }
                }

                else if (playerMove == 1) {
                    rectSourceSprite.height = 73;
                    rectSourceSprite.top = 292;
                    rectSourceSprite.width = 48;

                    if (rectSourceSprite.left == 96) {
                        rectSourceSprite.left = 48;
                    }
                    else {
                        rectSourceSprite.left = 96;
                    }
                }
                else {
                    rectSourceSprite.top = 0;
                    rectSourceSprite.height = 73;
                    rectSourceSprite.width = 46;


                    if (rectSourceSprite.left == 46) {
                        rectSourceSprite.left = 0;
                    }
                    else {
                        rectSourceSprite.left = 46;
                    }
                }
            }




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
