#pragma once
#include "ofApp.h"
#include "player.h"

#define COLLIDED true
#define NOTCOLLIDED false

class Circle {
private:
	ofVec2f position;
public:
	void init();
	void update(float time);
	bool Circle::collided(Player* player);
	void draw();
};