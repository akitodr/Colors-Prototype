#include "Camera.h"

void Camera::Init(ofVec2f background) {
	SCREEN_CENTER.set(ofGetWidth() /2, ofGetHeight() /2);
	
	
	maxX = background.x - ofGetWidth();
	maxY = background.y - ofGetHeight();

}

void Camera::Update(ofVec2f player) {
	posCamera = player - SCREEN_CENTER;

	if (posCamera.x <= 0) {
		posCamera.x = 0;
	}
	else if (posCamera.x >= maxX) {
		posCamera.x = maxX;
	}

	if (posCamera.y <= 0) {
		posCamera.y = 0;
	}
	else if (posCamera.y >= maxY) {
		posCamera.y = maxY;
	}
}

ofVec2f Camera::getPosition() {
	return posCamera;
}