#pragma once

#include "ofMain.h"
#include "Fase1.h"
#include "Buttons.h"
#include <vector>

class Menu : public Fase {

	private:
		vector <Button*> buttons;
        Screen* next;
    
		ofImage menuBackground;
		ofSoundPlayer sound;
		ofVec2f posButtonEnter;
		ofVec2f posButtonCredits;
		ofVec2f posButtonExit;

	public:
		void init();
		void update(float secs, const MouseInfo& mouse);
		void draw();
		Screen* nextScreen();
		void onPortal() {};
		void interpolateColor(const ofVec3f& color);
		~Menu() {};

};
