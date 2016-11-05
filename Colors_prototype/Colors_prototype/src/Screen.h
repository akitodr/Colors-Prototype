#pragma once

#include "ofMain.h"
#include "ScreenManager.h"

class Screen {

	public:

		virtual void init() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
		virtual Screen* nextScreen() = 0;

};