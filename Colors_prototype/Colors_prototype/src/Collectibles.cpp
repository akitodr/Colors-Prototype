#include "Collectibles.h"


void Circle::init() {
	position.x = 500;
	position.y = 500;
}
void Circle::update(float time) {

}

bool Circle::collided(Player* player) {
	ofVec2f playerPosition = player->getPosition();
	if ((playerPosition.x + player->size) >= position.x && playerPosition.x <= (position.x + size)
		&& playerPosition.y <= (position.y + size) && (playerPosition.y + player->size) >= position.y) {
		cout << "collided!" << endl;
		return true;
	}
	else {
		cout << "---" << endl;
		return false;
	}
}

void Circle::draw() {
	ofSetColor(ofColor::red);
	ofDrawCircle(position.x, position.y, 10);
}