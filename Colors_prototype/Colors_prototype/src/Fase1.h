#pragma once

#include "ofMain.h"
#include "Screen.h"
#include "player.h"
#include "Collectibles.h"
#include "Camera.h"

class Fase1 : public Screen {

	private:
		Player player;
		Camera camera;
		ofImage background;
		vector<Circle*> objects;

	public:
		void init();
		void update(float secs, ofVec2f& mousePos, ofVec2f& mousePressedPos, bool mouseDown);
		void draw();
		~Fase1() {};
};
