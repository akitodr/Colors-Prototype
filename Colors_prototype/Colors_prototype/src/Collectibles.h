#pragma once
#include "ofApp.h"
#include "player.h"
#include <vector>

class Circle {
private:
	int size = 10;
public:
    int color;
	ofVec2f position; //mudei pra public mas não curt
	bool active;
	void init();
	void update(float time);
	bool collided(Player* player);
	void draw(ofVec2f posCamera);
	~Circle();
};