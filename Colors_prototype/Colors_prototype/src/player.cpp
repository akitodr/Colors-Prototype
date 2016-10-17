#include "player.h"

#include "PointShape.h"
#include "DynamicManager.h"
#include "OFRenderer.h"

using namespace particle::manager;
using namespace particle::shape;

void Player::setup() {
	physics = new NewtonPhysics(
		Range<float>(1), //Mass
		Range<int>(-10, 10),  //Force
		Range<float>(ofDegToRad(0)), //Angle
		Range<float>(0),   //Initial angle
		Range<float>(0, 1000)); //Rotation speed
	physics->setGravity(ofVec2f(0, 100));

	body = new ColoredBody(0, 255, 0, //Color
		Range<int>(255)); //Alpha variation

	ParticleRenderer* renderer = new OFRenderer("img/ember.png", 1.5, true);


	emitter = new Emitter(ofVec2f(50, ofGetHeight() / 2),
		20, //Creations per second
		Range<float>(1.0f, 5.0f), //LifeTime
		new DynamicManager(), physics, body, renderer); //Managers

	emitter->setParticlesPerCreation(1);
}

void Player::update(float time) {
	emitter->process(time);
}

void Player::draw(ofVec2f camera) {
	emitter->setPosition(position - camera);
	emitter->draw();
}

ofVec2f Player::getPosition() {
	return position;
}

void Player::setPosition(ofVec2f pos) {
	position = pos;;
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
}

Player::~Player() {
	delete emitter;
}
