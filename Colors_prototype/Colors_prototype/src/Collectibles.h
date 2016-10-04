#pragma once
#include "ofApp.h"
#include "player.h"
#include <vector>

class Circle {
private:
	int size = 10;
public:
	ofVec2f position; //mudei pra public mas não curto
	bool active;
	void init();
	void update(float time);
	bool collided(Player* player);
	void draw();
	~Circle();
};