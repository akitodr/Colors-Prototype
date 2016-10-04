#include "Collectibles.h"

void Circle::init() {
	active = true;
	position.x = rand() % 1000;
	position.y = rand() % 760;
}
void Circle::update(float time) {

}

bool Circle::collided(Player* player) {
	ofVec2f playerPosition = player->getPosition();
	if ((playerPosition.x + player->size) >= position.x && playerPosition.x <= (position.x + size)
		&& playerPosition.y <= (position.y + size) && (playerPosition.y + player->size) >= position.y) {
		
		return true;
	}
	else {
		
		return false;
	}
}

void Circle::draw() {
		ofSetColor(ofColor::blue);
		ofDrawCircle(position.x, position.y, 10);
}
Circle::~Circle() {
	
}