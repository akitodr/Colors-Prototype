#pragma once
#include "ofApp.h"
#include "player.h"

class Circle {
private:
	ofVec2f position;
	int size = 10;
public:
	bool active;
	void init();
	void update(float time);
	bool Circle::collided(Player* player);
	void draw();
	~Circle();
};