#pragma once

#include "ofApp.h"

class Menu {

private:

	//ofVec2f posMouse;
	//ofVec2f posButton;
	ofImage menuBackground;
	ofImage menuEnter;
	ofImage menuCredits;
	ofImage menuExit;
	ofImage credits;
	//ofImage back;

	

public:
	bool click = false;
	void init();
	void update();
	void draw();

};
