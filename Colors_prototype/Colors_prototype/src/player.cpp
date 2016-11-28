#include "player.h"

#include "PointShape.h"
#include "DynamicManager.h"
#include "OFRenderer.h"
#include "Collectibles.h"

using namespace particle::manager;
using namespace particle::shape;

void Player::init() {

	animation.images = new ofImage[3];
	animation.images[0].load("img/a1.png");
	animation.images[0].setAnchorPercent(0.5, 0.5);
	animation.images[1].load("img/a2.png");
	animation.images[1].setAnchorPercent(0.5, 0.5);
	animation.images[2].load("img/a3.png");
	animation.images[2].setAnchorPercent(0.5, 0.5);
	animation.frame = 0;
	animation.count = 3;
	animation.repeat = true;
	animation.frameTime = 0.5;
	animation.time = 0;

	physics = new NewtonPhysics(
		Range<float>(1), //Mass
		Range<int>(-10, 10),  //Force
		Range<float>(ofDegToRad(0)), //Angle
		Range<float>(0),   //Initial angle
		Range<float>(0, 1000)); //Rotation speed
	physics->setGravity(ofVec2f(0, 100));

	//COOOOORRRRRRR AQUIIIIIII FOCOOOOOO
	body = new ColoredBody(0, 255, 0, //Color
		Range<int>(255, 100)); //Alpha variation

	renderer = new OFRenderer("img/ember.png", 1.5, true);


	emitter = new Emitter(ofVec2f(50, ofGetHeight() / 2),
		20, //Creations per second
		Range<float>(1.0f, 5.0f), //LifeTime
		new DynamicManager(), physics, body, renderer); //Managers

	emitter->setParticlesPerCreation(1);
}

void Player::update(float time) {
	position += direction * 30 * time;
	emitter->process(time);
	animation.update(time);
}

void Player::draw(const ofVec2f& camera) {
	renderer->setCamera(camera);
	emitter->setPosition(position);
	emitter->draw();
	animation.draw(position - camera);
}

ofVec2f Player::getPosition() {
	return position;
}

void Player::setPosition(ofVec2f position) {
	this->position = position;
}

void Player::setDirection(ofVec2f direction) {
	if (direction.length() > 15) {
		direction.normalize() *= 15;
	}

	this->direction = direction;
}

ofVec2f Player::getDirection() {
	return direction;
}

void Player::setColor(int r, int g, int b) {
	body->setColor(r, g, b);
}

void Player::interpolateColor(int RGBMode, int value)
{
	//preguiça de enum, portanto:
	//0 = red
	//1 = green
	//2 = blue

	ofVec3f currentColor = body->getColor();
	float t = (((float)100 * (float)value) / (float)255) / (float)100; // seta o intervalo no qual a interpolação vai estar
	ofVec3f newColor = ofVec3f();
	switch (RGBMode)
	{
	case 0: {
		newColor = ofVec3f(currentColor.x + (255 - currentColor.x) * t, currentColor.y + (0 - currentColor.y) * t, currentColor.z + (0 - currentColor.z) * t);

	}
			break;

	case 1: {

		newColor = ofVec3f(currentColor.x + (0 - currentColor.x) * t, currentColor.y + (255 - currentColor.y) * t, currentColor.z + (0 - currentColor.z) * t);
	}
			break;

	case 2: {

		newColor = ofVec3f(currentColor.x + (0 - currentColor.x) * t, currentColor.y + (0 - currentColor.y) * t, currentColor.z + (255 - currentColor.z) * t);
	}
			break;
	default:
		return;
		break;
	}

	body->setColor(newColor.x, newColor.y, newColor.z);
	cout << newColor << endl;
}

bool Player::isAlive() const {
	return true;
}

ofRectangle Player::bounds() {
	return ofRectangle(position, size, size);
}

void Player::collidedWith(GameObject* other) {
	Circle* circle = reinterpret_cast<Circle*>(other);
	if (circle != nullptr && circle->tag == "collectible" ) {
		interpolateColor(circle->color, 5);
	}
}

ofVec3f Player::getColor() const {
	return body->getColor();
}


Player::~Player() {
	delete emitter;
}