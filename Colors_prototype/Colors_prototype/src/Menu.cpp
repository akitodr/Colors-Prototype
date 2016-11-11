#include "Menu.h"
#include "Fase1.h"

void Menu::init() {
    next = this;
    
	posButtonEnter.set(430, 430);
	posButtonCredits.set(430, 470);
	posButtonExit.set(430, 510);

	menuBackground.load("images/menu.png");
	sound.load("audio/white_light.wav");
	sound.play();
	Button* enter = new Button(posButtonEnter, "images/enterClicked.png", "images/enter.png");
	Button* credits = new Button(posButtonCredits, "images/creditsClicked.png", "images/credits.png");
	Button* exit = new Button(posButtonExit, "images/exitClicked.png", "images/exit.png");
    
	buttons.push_back(enter);
	buttons.push_back(credits);
	buttons.push_back(exit);
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
