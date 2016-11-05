#pragma once

#include "ofMain.h"
#include "Screen.h"
#include "Buttons.h"
#include <vector>

class Menu : public Screen {

	private:
		vector <Button*> buttons;
		ofImage menuBackground;
		ofVec2f posButtonEnter;
		ofVec2f posButtonCredits;
		ofVec2f posButtonExit;

	public:
		void init();
		void update();
		void draw() const;
		Screen* nextScreen();
		~Menu() {};

};
