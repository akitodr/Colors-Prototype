#include "Collectibles.h"


void Circle::init() {
	position.x = 500;
	position.y = 500;
}
void Circle::update(float time) {
	
}

bool Circle::collided(Player* player) {
	ofVec2f playerPosition = player->getPosition();
	if (playerPosition == position) {
		return true;
	}
	else {
		return false;
	}
}

void Circle::draw() {
	ofSetColor(ofColor::red);
	ofDrawCircle(position.x, position.y, 10);
}