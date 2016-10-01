//
//  player.cpp
//  colors
//
//  Created by ViniGodoy on 30/09/16.
//
//

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
    physics->setGravity(ofVec2f(0,100));
    
    body = new ColoredBody(200, 100, 0, //Color
                                 Range<int>(255)); //Alpha variation
    
    ParticleRenderer* renderer = new OFRenderer("img/sparkle.png", 1.5, true);
    
    emitter = new Emitter(ofVec2f(50, ofGetHeight() / 2),
                          10, //Creations per second
                          Range<float>(1.0f, 5.0f), //LifeTime
                          new DynamicManager(), physics, body, renderer); //Managers
    
    emitter->setParticlesPerCreation(1);
}

void Player::update(float time) {
    emitter->process(time);
}

void Player::draw() {
    emitter->draw();
}

ofVec2f Player::getPosition() {
    return emitter->getPosition();
}

void Player::setPosition(ofVec2f position) {
    emitter->setPosition(position);
}

void Player::setColor(int r, int g, int b) {
    body->setColor(r, g, b);
}

Player::~Player()
{
    delete emitter;
}
