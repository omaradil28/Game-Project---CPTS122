#pragma once
#include"Contact.hpp"
#include"Textures.hpp"
#include"Menu.hpp"
#include"Collision.hpp"
#include"Player.hpp"
#include"Alien.hpp"
#include"Platform.hpp" // Object
#include"FlameEye.hpp"
#include"Object.hpp"
#include"Asteroid.hpp"
#include"Shower.hpp"
#include"Spore.hpp"
#include"Stars.hpp"
#include"Rockets.hpp"

//Moved to Libraries.hpp:
#define WinWidth VideoMode().getDesktopMode().width // Window Height and Width
#define WinHeight VideoMode().getDesktopMode().height


class Game {
public:
    Game();
    void run();
    void runGame(RenderWindow& window);
    void collision(RenderWindow&, Time);
    void death(RenderWindow&);
    void scoreDisplay(RenderWindow&);
    void musicPlayer(string songDir, Music& musicIn, bool looped, int volume);
    void soundPlayer(string soundName, Sound& sound, SoundBuffer& buffer, bool looped, int volume);

    
private:
    //All objects 
    Player player;
    Alien alien;
    Alien1 alien1;
    Alien2 alien2;
    Alien3 alien3; 
    Alien4 alien4;
    Spore spore;
    Platform platform;
    FlameEye flameeye;
    Asteroid asteroid;
    Shower shower;
    StarShrink shrink;
    Rocket rocket;
    classTexture loader;

    //Backgrounds
    RectangleShape menuBackground;
    RectangleShape gameBackground;
    RectangleShape optionsBackground;
    RectangleShape aboutBackground;

    Texture menuTexture;
    Texture gameTexture;
    Texture optionsTexture;
    Texture aboutTexture;

    //Clocks for timers

    Clock abilityClock;
    Clock deleteClock;
    Font font;

    //Text for menu,score, and pause
    Text paused;
    Text options;
    Text options2;
    Text about;
    Text about2;
    Text score;

    //Sound and Music variables
    SoundBuffer buffer1;
    SoundBuffer buffer2;
    SoundBuffer buffer3;
    SoundBuffer buffer4;
    Sound alienGroan;
    Sound wind;
    Sound sporeSound;
    Sound flameeyeSound;
    Music jetpack;
    Music music;


    //Score Variable
    int scoring;

    //CODE FOR INFINITE-SCROLLING BACKGROUND

    int restart = 0;
};

Game::Game() {
    //Loads Font
    font.loadFromFile("textures/SaucerBB.ttf");
    paused.setFont(font);

    options.setFont(font);
    options2.setFont(font);

    about.setFont(font);
    about2.setFont(font);

    score.setFont(font);

    //Loads Wallpapers
    loader.loadTexture(menuTexture, "textures/gray planet.jpg");
    loader.setTexture(menuBackground, menuTexture, sf::Vector2f(WinWidth, WinHeight));


    loader.loadTexture(gameTexture, "textures/InfiniteBackground.png");
    loader.setTexture(gameBackground, gameTexture, sf::Vector2f(WinWidth * 10, WinHeight));

    loader.loadTexture(optionsTexture, "textures/options.jpeg");
    loader.setTexture(optionsBackground, optionsTexture, sf::Vector2f(WinWidth, WinHeight));

    loader.loadTexture(aboutTexture, "textures/about.jpeg");
    loader.setTexture(aboutBackground, aboutTexture, sf::Vector2f(WinWidth, WinHeight));
}

void Game::run() {

    RenderWindow WINDOW(VideoMode().getDesktopMode(), "Main Menu", Style::Default);
    Menu mainMenu(WINDOW.getSize().x, WINDOW.getSize().y);
    musicPlayer("Sounds/HEARTLESS.mp3", music, true, 3);
    
    //Main menu that allows user to traverse between playing, controls, about, and exit using up and down keys. Press return to enter the windows
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
                        //Runs the game when entering winodw
                        WINDOW.clear();
                        runGame(WINDOW);

                    }
                    if (x == 1) {

                        //Runs the controls window and displays how to play the game
                        WINDOW.clear();
                        options.setString("Controls/Tips:");
                        options.setCharacterSize(200);
                        options.setFillColor(Color::Green);
                        options.setPosition(100,100);

                        options2.setString("1. Up Arrow Key = UP. Down Arrow Key = DOWN. \nLeft Arrow Key = LEFT. Right Arrow Key = RIGHT.\n2. Press P to Pause or Escape to Close App.\n3. When dead, press space to quit.\n4. Avoid all the objects and projectiles\nfor as long as you can.\n5. Touch the star for an ability for 30 seconds!");
                        options2.setCharacterSize(80);
                        options2.setFillColor(Color::Cyan);
                        options2.setPosition(100, 400);

                        WINDOW.draw(optionsBackground);
                        WINDOW.draw(options);
                        WINDOW.draw(options2);
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

                        //Runs the about window showing more details on the project
                        WINDOW.clear();
                        about.setString("About:");
                        about.setCharacterSize(200);
                        about.setFillColor(Color::Magenta);
                        about.setPosition(100, 100);

                        about2.setString("Computer Science 122 Programming Assignment 9\nCreated by:\nAlejandro Ramirez\nEmili Adachi\nOmar Adil\n\nFly through space while trying to dodge \nvarious environmental hazards!");
                        about2.setCharacterSize(80);
                        about2.setFillColor(Color::Red);
                        about2.setPosition(100, 400);

                        WINDOW.draw(aboutBackground);
                        WINDOW.draw(about);
                        WINDOW.draw(about2);
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
    //Clock that prints each object at certain times, in seconds
    Clock platformClock;
    Time platformTime;

    Clock rockClock;
    Time rockTime;

    Clock astClock;
    Time astTime;

    Clock showerClock;
    Time showerTime;

    Clock sporeClock;
    Time sporeTime;

    Clock shrinkClock;
    Time shrinkTime;

    Clock rocketClock;
    Time rocketTime;

    Clock flameeyeDeleteClock;
    Clock astDeleteClock;
    Clock rocketDeleteClock;
    Clock sporeDeleteClock;

    Clock animationClock;
    Clock alienSoundClock;

    //Helps pause game
    bool pause = false;


    // Jetpack Sound
    // Creates jetpack sound at game start, and plays it.
    musicPlayer("Sounds/jetpack-thrust.wav", jetpack, true, 2);

    while (Play.isOpen()) {
        //Closes game if pressing escape, pauses if pressing P
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
                if (newEvent.type == Event::KeyPressed && newEvent.key.code == sf::Keyboard::P) {
                    pause = !pause;

                }
            }
        }


        Play.clear();

        if (!pause) {
            //If game is not paused, runs this code.
            Play.draw(gameBackground);
            gameBackground.move(Vector2f(-0.1, 0));



            // Player Animation Code. Gets reads from the player movement function, then animates accordingly.
            if (animationClock.getElapsedTime().asSeconds() > 0.05f) {
                player.animation();
                flameeye.animation();
                alien.animation();
                spore.animation();
                animationClock.restart();
            }

            // Alien Groaning Sound. Picks random of 4 sounds, and plays it.
            if (alienSoundClock.getElapsedTime().asSeconds() > 8.0f) {
                int num = rand() % 4;

                if (num == 0) {
                    soundPlayer("Sounds/Monster_Groan1.mp3", alienGroan, buffer4, false, 5);
                }
                else if (num == 1) {
                    soundPlayer("Sounds/Monster_Groan1a.mp3", alienGroan, buffer4, false,5);
                }
                else if (num == 2) {
                    soundPlayer("Sounds/Monster_Groan2.mp3", alienGroan, buffer4, false, 5);
                }
                else if (num == 4) {
                    soundPlayer("Sounds/Monster_Groan3.mp3", alienGroan, buffer4, false, 5);
                }
                alienSoundClock.restart();
            }

            //Generates platforms every 2 seconds
            platformTime = platformClock.getElapsedTime();
            if (platformTime.asSeconds() >= 1) {
                platform.generatePlatform();
                platformClock.restart();
            }
            platform.movePlatforms(1.0f); //Platform speed
            for (auto& platformSprite : platform.getObjects()) {
                Play.draw(platformSprite);
            }

            //Generates platforms every 7 seconds
            sporeTime = sporeClock.getElapsedTime();
            if (sporeTime.asSeconds() >= 15) {
                soundPlayer("Sounds/SPORE.mp3", sporeSound, buffer1, false, 6);
                spore.generateSpore();
                sporeClock.restart();
            }
            spore.moveSpore(1.0f); //Platform speed
            for (auto& sporeSprite : spore.getObjects()) {
                sporeSprite.setTextureRect(spore.getSpriteRect());
                Play.draw(sporeSprite);
            }

            //Generates FlameEye every 3 seconds. Can generate any where from 1 to 3 flameeyes, all projecting at unique locations.
            rockTime = rockClock.getElapsedTime();

            if (rockTime.asSeconds() >= 2) {
                soundPlayer("Sounds/FlameEyeWhistle.mp3", flameeyeSound, buffer2, false, 15);
                int num = rand() % 3 + 1;
                if (num == 1) {
                    flameeye.location();
                }
                else if (num == 2) {
                    flameeye.location();
                    flameeye.location();
                }
                else if (num == 3) {
                    flameeye.location();
                    flameeye.location();
                    flameeye.location();
                }
                flameeye.getSpawnVector().push_back(num);
                rockClock.restart();
            }
            flameeye.moveFlameEye(2.5f); //FlameEye speed
            for (auto& FlameEyeSprite : flameeye.getObjects()) {
 
                FlameEyeSprite.setTextureRect(flameeye.getSpriteRect());
                Play.draw(FlameEyeSprite);
            }

            //Prints the big asteroid every 10 seconds
            astTime = astClock.getElapsedTime();
            if (astTime.asSeconds() >= 10) {
                soundPlayer("Sounds/Wind.mp3", wind, buffer3, false, 100);
                asteroid.location();
                astClock.restart();
            }
            asteroid.moveAsteroids(1.5f); //Rock speed

            for (auto& astSprite : asteroid.getObjects()) {
                Play.draw(astSprite);
            }

            //Prints the rocket every 20 seconds
            rocketTime = rocketClock.getElapsedTime();
            if (rocketTime.asSeconds() >= 20) {
                rocket.location();
                rocketClock.restart();
            }
            rocket.moveRocket(2.0f); //Rocket speed
            for (auto& rocketSprite : rocket.getObjects()) {
                Play.draw(rocketSprite);
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

            //Prints the star every 30 seconds
            shrinkTime = shrinkClock.getElapsedTime();
            if (shrinkTime.asSeconds() >= 30) {
                shrink.location();
                shrinkClock.restart();
            }
            shrink.moveStar(1.5f); //Star speed
            for (auto& shrinkSprite : shrink.getObjects()) {
                Play.draw(shrinkSprite);
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

    


            //Deletes FlameEye
            if (flameeyeDeleteClock.getElapsedTime().asSeconds() > 2.05f) {
                flameeye.deleteFlameEye();
                flameeyeDeleteClock.restart();
            }

            //Deletes Asteroid
            if (astDeleteClock.getElapsedTime().asSeconds() > 20.0f) {
                asteroid.getObjects().erase(asteroid.getObjects().begin());
                astDeleteClock.restart();
            }

            //Deletes rocket (possibly satellite)
            if (rocketDeleteClock.getElapsedTime().asSeconds() > 40.0f) {
                rocket.getObjects().erase(rocket.getObjects().begin());
                rocketDeleteClock.restart();

            }

            // Deletes Spore
            if (sporeDeleteClock.getElapsedTime().asSeconds() > 30.0f) {
                spore.getObjects().erase(spore.getObjects().begin());
                sporeDeleteClock.restart();

            }
            


            scoreDisplay(Play);
            alien.setAnimSeq(0);
            player.setAnimSeq(2);
            player.getSprite().setTextureRect(player.getSpriteRect());
            alien.getSprite().setTextureRect(alien.getSpriteRect());
            Play.draw(alien.getSprite());
            Play.draw(player.getSprite());
            player.movement();
            Play.display();

            collision(Play, abilityClock.getElapsedTime());

        }
        else {
            //Runs the paused menu when pressing P
            paused.setString("Game Paused");
            paused.setCharacterSize(200);
            paused.setFillColor(Color::White);
            paused.setPosition(WinWidth / 2 - paused.getLocalBounds().width / 2, WinHeight / 2 - paused.getLocalBounds().height / 2);
            Play.draw(paused);
            Play.display();
        }
    }
}


//Collision detection function, created so its cleaner in the actual game function.
void Game::collision(RenderWindow& Play, Time time) {
    //Collision detection for user and alien
    if (Collision::PixelPerfectTest(player.getSprite(), alien.getSprite())) {
        death(Play);
    }

    //Collision detection for user and rock
    for (const auto& FlameEyeSprite : flameeye.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), FlameEyeSprite)) {
            death(Play);
        }
    }
    //Collision detection for user and asteroid
    for (const auto& astSprite : asteroid.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), astSprite)) {
            death(Play);
        }
    }

    //Collision detection for user and Aliens/Comet
    for (const auto& showerSprite : shower.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), showerSprite)) {
            death(Play);
        }
    }
    for (const auto& alien1Sprite : alien1.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), alien1Sprite)) {
            death(Play);
        }
    }
    for (const auto& alien2Sprite : alien2.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), alien2Sprite)) {
            death(Play);
        }
    }
    for (const auto& alien3Sprite : alien3.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), alien3Sprite)) {
            death(Play);
        }
    }
    for (const auto& alien4Sprite : alien4.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), alien4Sprite)) {
            death(Play);
        }
    }

    //Collision for user and Spore
    for (const auto& sporeSprite : spore.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), sporeSprite)) {
            death(Play);
        }
    }

    //Collision for user and rocket
    for (const auto& rocketSprite : rocket.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), rocketSprite)) {
            death(Play);
        }
    }

    //Collision for user and star that creates temporary shrink ability
    for (const auto& shrinkSprite : shrink.getObjects()) {
        if (Collision::PixelPerfectTest(player.getSprite(), shrinkSprite)) {
            abilityClock.restart();
            player.getSprite().setScale(2.0f, 2.0f);
            shrink.getObjects().erase(shrink.getObjects().begin());
        }
    }
    if (abilityClock.getElapsedTime().asSeconds() >= 30) {
        player.getSprite().setScale(3.5f, 3.5f);
    }

}

//Function that prints that you are dead and the score. Pressing space closes app.
void Game::death(RenderWindow& window) {
    window.clear();

    Text deathText;
    deathText.setFont(font);
    deathText.setString(" You Died\nScore: " + to_string(scoring));
    deathText.setCharacterSize(100);
    deathText.setFillColor(Color::Red);
    deathText.setPosition(WinWidth / 2 - deathText.getLocalBounds().width / 2, WinHeight / 2 - deathText.getLocalBounds().height / 2);


    // Pauses all music and sounds.
    music.pause();
    jetpack.pause();
    alienGroan.pause();
    flameeyeSound.pause();
    sporeSound.pause();
    wind.pause();

    window.draw(deathText);
    window.display();
  
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return;
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                window.close();
                return;
            }
        }
    }
}

//Displays the score by 1 in the top left of the screen. Increments everytime the game is looped, so extremely fast.
void Game:: scoreDisplay(RenderWindow& window) {
    scoring++;
    score.setFont(font);
    score.setString("Score: " + to_string(scoring));
    score.setCharacterSize(30);
    score.setFillColor(Color::White);
    score.setPosition(20, 20); 

    window.draw(score);
}


// Plays sound using the SFML audio library. It sets volume, whether it loops or not, and plays the audio.
void Game::musicPlayer(string songDir, Music& musicIn, bool looped, int volume) {
    if (!musicIn.openFromFile(songDir))
        cout << "Error" << endl;
    musicIn.setLoop(looped);
    musicIn.setVolume(volume);
    musicIn.play();

}

// Plays sound using the SFML audio library. It sets volume, whether it loops or not, and plays the audio.
void Game::soundPlayer(string soundName, Sound& sound, SoundBuffer& buffer, bool looped, int volume) {
    sound.setBuffer(buffer);
    if (!buffer.loadFromFile(soundName))
        cout << "Unable to open " << soundName << endl;
    sound.setLoop(looped);
    sound.setVolume(volume);
    sound.play();
}
