#include "Collectibles.h"

void Circle::init() {
	active = true;
	position.x = rand() % 10000;
	position.y = rand() % 760;
	color = rand() % 3;
	tag = "collectible";
	alive = true;

	for (int i = 0; i < 6; i++)
	{
		red[i].load("img/")
	}
}
void Circle::update(float time) {
	if (!alive) {
		count += time;
		if (count > 10)
			alive = true;
	}

}

void Circle::collidedWith(GameObject* other) {
	if (!alive) return;
	alive = false;
	count = 0;
}

void Circle::draw(const ofVec2f& posCamera) {
	if (!alive) return;
	for (int i = 0; i < 6; i++) {
		red[i].draw(position);
		blue[i].draw(position);
		green[i].draw(position);
	}
}

bool Circle::isAlive() const {
	return true;
}

void Circle::kill() {
	alive = false;
}

ofRectangle Circle::bounds() {
	return ofRectangle(position, size, size);
}



Circle::~Circle() {

}