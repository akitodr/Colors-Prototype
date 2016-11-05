#include "Menu.h"

void Menu::init() {

	posButtonEnter.set(430, 430);
	posButtonCredits.set(430, 470);
	posButtonExit.set(430, 510);

	menuBackground.load("images/menu.png");
	Button* enter = new Button(posButtonEnter, "images/enterClicked.png", "images/enter.png");
	Button* credits = new Button(posButtonCredits, "images/creditsClicked.png", "images/credits.png");
	Button* exit = new Button(posButtonExit, "images/exitClicked.png", "images/exit.png");
	buttons.push_back(enter);
	buttons.push_back(credits);
	buttons.push_back(exit);
}

void Menu::update() {
	for (int i = 0; i < 3; i++) {
		buttons[i]->Update();
	}
}

void Menu::draw() const {
	menuBackground.draw(0, 0, 1024, 768);
	for (int i = 0; i < 3; i++) {
		buttons[i]->Draw();
	}
}

Screen* Menu::nextScreen() {
	//return Fase1;
}
