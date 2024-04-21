#pragma once
#include"Contact.hpp"
#include"Textures.hpp"
#include"Menu.hpp"
#include"Collision.hpp"
#include"Player.hpp"
#include"Alien.hpp"
#include"Platform.hpp"
#include"Meteor.hpp"
#include"Object.hpp"
#include"Asteroid.hpp"
#include"Shower.hpp"
#include"Zeno.hpp"

#define WinWidth VideoMode().getDesktopMode().width // Window Height and Width
#define WinHeight VideoMode().getDesktopMode().height

int playerMove;

class Game {
public:
    Game();
    void run();
    void runGame(RenderWindow& window);
    void collision(RenderWindow&);

private:
    Player player;
    Alien alien;
    Alien1 alien1;
    Alien2 alien2;
    Alien3 alien3; 
    Alien4 alien4;
    Zeno zeno;
    Platform platform;
    Meteor meteor;
    Asteroid asteroid;
    Shower shower;

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

    Clock astClock;
    Time astTime;

    Clock showerClock;
    Time showerTime;

    Clock zenoClock;
    Time zenoTime;

    Clock playerClock;


    bool pause = false;
    bool printedOnce = false;

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

            // Player Animation Code. Gets reads from the player movement function, then animates accordingly.
            if (playerClock.getElapsedTime().asSeconds() > 1.0f) player.animation();

            //Generates platforms every 2 seconds
            platformTime = platformClock.getElapsedTime();
            if (platformTime.asSeconds() >= 2) {
                platform.generatePlatform();
                platformClock.restart();
            }
            platform.movePlatforms(1.0f); //Platform speed
            for (auto& platformSprite : platform.getObjects()) {
                Play.draw(platformSprite);
            }

            //Generates platforms every 7 seconds
            zenoTime = zenoClock.getElapsedTime();
            if (zenoTime.asSeconds() >= 7) {
                zeno.generateZeno();
                zenoClock.restart();
            }
            zeno.moveZeno(1.0f); //Platform speed
            for (auto& zenoSprite : zeno.getObjects()) {
                Play.draw(zenoSprite);
            }

            //Generates meteor every 3 seconds
            rockTime = rockClock.getElapsedTime();
            if (rockTime.asSeconds() >= 3) {
                int num = rand() % 3 + 1;
                if (num == 1) {
                    meteor.location();
                }
                else if (num == 2) {
                    meteor.location(); 
                    meteor.location();
                }
                else if (num ==3) {
                    meteor.location();
                    meteor.location();
                    meteor.location();
                }
                rockClock.restart();
            }
            meteor.moveMeteors(2.5f); //Meteor speed
            for (auto& meteorSprite : meteor.getObjects()) {
                Play.draw(meteorSprite);
            }
            

            //Prints the big asteroid every 10 seconds
            astTime = astClock.getElapsedTime();
            if (astTime.asSeconds() >= 10) {
                asteroid.location();
                astClock.restart();
            }
            asteroid.moveAsteroids(1.5f); //Rock speed
            for (auto& astSprite : asteroid.getObjects()) {
                Play.draw(astSprite);
            }

            //Prints the space traffic every 45 seconds;
            showerTime = showerClock.getElapsedTime();
            if (showerTime.asSeconds() >= 45) {
                shower.startShower();
                alien2.startAlien2();
                alien3.startAlien3();
                alien4.startAlien4();
                alien1.startAlien1();
                showerClock.restart();
            }
            shower.moveShower(-1.5, 1.9); //Speed - Angle
            for (auto& showerSprite : shower.getObjects()) {
                Play.draw(showerSprite);
            }
            alien1.moveAlien1(-1.1, 2.3); //Speed - Angle
            for (auto& alien1Sprite : alien1.getObjects()) {
                Play.draw(alien1Sprite);
            }
            alien2.moveAlien2(-1.2, 1.2); //Speed - Angle
            for (auto& alien2Sprite : alien2.getObjects()) {
                Play.draw(alien2Sprite);
            }
            alien3.moveAlien3(-0.5, 0.7); //Speed - Angle
            for (auto& alien3Sprite : alien3.getObjects()) {
                Play.draw(alien3Sprite);
            }
            alien4.moveAlien4(-1.1, 0.9); //Speed - Angle
            for (auto& alien4Sprite : alien4.getObjects()) {
                Play.draw(alien4Sprite);
            }

            playerMove = 2;
            player.getSprite().setTextureRect(rectPlayerSprite);
            Play.draw(alien.getSprite());
            Play.draw(player.getSprite());
            player.movement();
            Play.display();
           
            collision(Play);
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

void Game::collision(RenderWindow& Play) {
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
    //Collision detection for user and asteroid
    for (const auto& astSprite : asteroid.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), astSprite)) {
            Play.close();
        }
    }

    //Collision detection for user and Aliens/Comet
    for (const auto& showerSprite : shower.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), showerSprite)) {
            Play.close();
        }
    }
    for (const auto& alien1Sprite : alien1.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), alien1Sprite)) {
            Play.close();
        }
    }
    for (const auto& alien2Sprite : alien2.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), alien2Sprite)) {
            Play.close();
        }
    }
    for (const auto& alien3Sprite : alien3.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), alien3Sprite)) {
            Play.close();
        }
    }
    for (const auto& alien4Sprite : alien4.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), alien4Sprite)) {
            Play.close();
        }
    }
    for (const auto& zenoSprite : zeno.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), zenoSprite)) {
            Play.close();
        }
    }
}