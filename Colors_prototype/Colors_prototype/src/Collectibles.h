#pragma once
#include "ofApp.h"
#include "player.h"
#include <vector>

class Circle : public GameObject {
private:
	int size = 10;
	bool alive;
	float count;

	ofImage red[6];
	ofImage green[6];
	ofImage blue[6];

public:
	int color;
	ofVec2f position; //mudei pra public mas não curt
	bool active;

	void init();
	void update(float time);
	void draw(const ofVec2f& posCamera);
	ofRectangle bounds();
	void collidedWith(GameObject* other);

	bool isAlive() const;
	void kill();

	~Circle();
};