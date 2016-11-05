#include "Collectibles.h"

void Circle::init() {
	active = true;
	position.x = rand() % 1000;
	position.y = rand() % 760;
	color = rand() % 3;
    alive = true;
}
void Circle::update(float time) {

}

void Circle::collidedWith(GameObject* other) {
    alive = false;
}

void Circle::draw(const ofVec2f& posCamera) {
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
	ofDrawCircle(position.x - posCamera.x, position.y - posCamera.y, 10);
}

bool Circle::isAlive() const {
    return alive;
}

void Circle::kill() {
    alive = false;
}

ofRectangle Circle::bounds() {
    return ofRectangle(position, size, size);
}



Circle::~Circle() {

}
