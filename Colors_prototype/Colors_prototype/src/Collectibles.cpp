#include "Collectibles.h"

void Circle::init() {
	active = true;
	position.x = rand() % 1000;
	position.y = rand() % 760;
    color = rand() % 3;
}
void Circle::update(float time) {

}

bool Circle::collided(Player* player) {
	ofVec2f playerPosition = player->getPosition();
	return ((playerPosition.x + player->size) >= position.x && playerPosition.x <= (position.x + size)
            && playerPosition.y <= (position.y + size) && (playerPosition.y + player->size) >= position.y);
}

void Circle::draw() {
    switch (color) {
        case 0:
            ofSetColor(ofColor::red);
            break;
        case 1:
            ofSetColor(ofColor::green);
            break;
        default:
            ofSetColor(ofColor::blue);
            break;
    }
        ofDrawCircle(position.x, position.y, 10);
}
Circle::~Circle() {
	
}