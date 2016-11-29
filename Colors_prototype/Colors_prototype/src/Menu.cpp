#include "Menu.h"


void Menu::init() {
	next = this;
	player = new Player();
	posButtonEnter.set(430, 430);
	posButtonCredits.set(430, 470);
	posButtonExit.set(430, 510);

	menuBackground.load("images/menu.png");
	sound.load("audio/white_light_master.wav");
	sound.play();
	Button* enter = new Button(posButtonEnter, "images/enterClicked.png", "images/enter.png");
	Button* credits = new Button(posButtonCredits, "images/creditsClicked.png", "images/credits.png");
	Button* exit = new Button(posButtonExit, "images/exitClicked.png", "images/exit.png");

	backgroundColor = ofVec3f(150, 200, 150);

	buttons.push_back(enter);
	buttons.push_back(credits);
	buttons.push_back(exit);

	GAMEMANAGER.add(player);
	player->setPosition(ofVec2f(background.getWidth() / 2, background.getHeight() / 2));
}

void Menu::interpolateColor(const ofVec3f& color) {
	ofVec3f newColor = color;

	if (newColor.x >= 120 && newColor.y >= 210 && newColor.z >= 120)
	{
		indoOuVoltano = 0;
	}

	if (newColor.x <= 0 && newColor.y <= 120 && newColor.z <= 0)
	{
		indoOuVoltano = 1;
	}

	if (indoOuVoltano == 0)
	{
		if (newColor.x >= 0 && newColor.z >= 0)
		{
			newColor.x -= 0.5;
			newColor.z -= 0.5;
		}
		else if (newColor.y >= 120)
		{
			newColor.y -= 0.5;
		}
	}
	else if (indoOuVoltano == 1)
	{
		if (newColor.y <= 210)
		{
			newColor.y += 0.5;

		}
		else if (newColor.x <= 120 && newColor.z <= 120)
		{
			newColor.x += 0.5;
			newColor.z += 0.5;
		}

	}
	backgroundColor = newColor;
}

void Menu::update(float secs, const MouseInfo& mouse) {
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i]->Update(secs);
		if (mouse.clicked && buttons[i]->Check(mouse.pos)) {
			buttons[i]->SetClick();
		}

		if (buttons[i]->isClickFinished()) {
			if (i == 0) {
				next = new Fase1();
				sound.stop();
			}
			if (i == 2) {
				exit(0);
			}
		}
	}
}

void Menu::draw() {
	menuBackground.draw(0, 0, 1024, 768);
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i]->Draw();
	}
}

Screen* Menu::nextScreen() {
	return next;
}