#pragma once

#include "ofMain.h"
#include "Screen.h"

class ScreenManager {
	
	private:
		Screen* current;

	public:
		ScreenManager(Screen& screen);
		void update();

};
