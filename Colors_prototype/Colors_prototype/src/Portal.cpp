//
//  Portal.cpp
//  colors
//
//  Created by BEPID on 08/11/16.
//
//

#include "Portal.h"

Portal::Portal(Fase* level, const ofVec2f& pos, const ofVec3f& _color)
	: fase(level), position(pos), color(_color) {}

void Portal::init() {
	image.load("img/portal.png");
}

bool Portal::isAlive() const {
	return true;
}

void Portal::draw(const ofVec2f& camera) {
	image.draw(position - camera);
}

void Portal::update(float secs) {

}

ofRectangle Portal::bounds() {
	return ofRectangle(position, image.getWidth(), image.getHeight());
}

void Portal::collidedWith(GameObject* other) {
	Player* player = dynamic_cast<Player*>(other);
	if (player != nullptr) {
		float distance = (player->getColor() - color).length();
		if (distance <= 100)
			fase->onPortal();
	}
}