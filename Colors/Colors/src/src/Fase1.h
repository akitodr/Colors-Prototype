#pragma once

#include "ofMain.h"
#include "Screen.h"
#include "player.h"
#include "Collectibles.h"
#include "Camera.h"

class Fase1 : public Screen {

	private:
		Player* player;
		Camera camera;
		ofImage background;

	public:
		void init();
		void update(float secs, const MouseInfo& mouse);
		void draw();
        Screen* nextScreen();
		~Fase1() {};
};
