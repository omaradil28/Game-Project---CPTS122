#pragma once
#include "PA9.hpp"

class Menu {
public:
	Menu(float, float);
	~Menu();

	void draw(sf::RenderWindow&);
	void up();
	void down();

	int pressed() {
		return selected;
	}

private:
	int selected;
	Font font;
	Text menu[Max_main_menu];
	Text title;
};

Menu::Menu(float width, float height) {
	if (!font.loadFromFile("textures/TH3 MACHINE.ttf")) {
		cout << "No font loaded";
	}

	//Title
	title.setFont(font);
	title.setFillColor(Color::White);
	title.setString("Space\n  Runner");
	title.setCharacterSize(200);
	title.setPosition(1000, 100);

	//Play
	menu[0].setFont(font);
	menu[0].setFillColor(Color::Cyan);
	menu[0].setString("PLAY");
	menu[0].setCharacterSize(120);
	menu[0].setPosition(150, 100);

	//Options
	menu[1].setFont(font);
	menu[1].setFillColor(Color::Red);
	menu[1].setString("CONTROLS");
	menu[1].setCharacterSize(120);
	menu[1].setPosition(150, 400);

	//About
	menu[2].setFont(font);
	menu[2].setFillColor(Color::Red);
	menu[2].setString("ABOUT");
	menu[2].setCharacterSize(120);
	menu[2].setPosition(150, 700);

	//Exit
	menu[3].setFont(font);
	menu[3].setFillColor(Color::Red);
	menu[3].setString("EXIT");
	menu[3].setCharacterSize(120);
	menu[3].setPosition(150, 1000);

	selected = 0;
}

Menu::~Menu(){}

void Menu::draw(RenderWindow& window) {
	window.draw(title);
	for (int i = 0; i < Max_main_menu; ++i) {
		window.draw(menu[i]);
	}
}

//Allows for user to scroll up
void Menu::up() {
	if (selected - 1 >= 0) {
		menu[selected].setFillColor(Color::Red);
		selected--;
		if (selected == -1) {
			selected = 2;
		}
		menu[selected].setFillColor(Color::Cyan);
	}
}

//Allows for user to scroll down
void Menu::down() {
	if (selected + 1 <= Max_main_menu) {
		menu[selected].setFillColor(Color::Red);
		selected++;
		if (selected == 4) {
			selected = 0;
		}
		menu[selected].setFillColor(Color::Cyan);
	}
}