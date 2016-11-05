#pragma once

#include "ofApp.h"
#include "player.h"

class Camera {

	private:
		ofVec2f SCREEN_CENTER;
		ofVec2f posCamera;

		float maxX, maxY;

	public:
		void Init(ofVec2f background);
		void Update(ofVec2f player);
		
		ofVec2f getPosition();

};