#include "Menu.h"

void Menu::init() {

	//ofVec2f posButtonBack(900, 700);

	menuBackground.load("images/menu.png");
	menuEnter.load("images/menuenter.png");
	menuCredits.load("images/menucredits.png");
	menuExit.load("images/menuExit.png");
	credits.load("images/credits.jpg");
	//back.load("images/back.png");
}

void Menu::update() {

}

void Menu::draw() {

	ofVec2f posMouse;
	ofVec2f posButtonEnter(430, 430);
	ofVec2f posButtonCredits(430, 470);
	ofVec2f posButtonExit(430, 510);

	menuBackground.draw(0, 0, 1024, 780);
	menuEnter.draw(posButtonEnter.x, posButtonEnter.y);
	menuCredits.draw(posButtonCredits.x, posButtonCredits.y);
	menuExit.draw(posButtonExit.x, posButtonExit.y);
	//credits.draw(0, 0);	

	if (click)
	{
		if (posButtonEnter.x && posButtonEnter.y)
		{
			credits.draw(0, 0);
			//back.draw(posButtonBack.x, posButtonBack.y);
		}
	}
}