#pragma once
#include "ofMain.h"

#include "Emitter.h"
#include "NewtonPhysics.h"
#include "ColoredBody.h"
#include "OFRenderer.h"
#include "Animation.h"
#include "GameObject.h"

using namespace math;
using namespace particle;
using namespace particle::physics;
using namespace particle::body;


class Player : public GameObject {
private:
	Emitter* emitter;
	ColoredBody* body;
	NewtonPhysics* physics;
    OFRenderer* renderer;
    
    Animation animation;
    
    ofVec2f position;
    ofVec2f direction;

public:    
	int size = 20;
	void init();
	void update(float time);
	void draw(const ofVec2f& posCamera);
	void setColor(int r, int g, int b);
	void interpolateColor(int RGBMode, int value);
    
	ofVec2f getPosition();
	void setPosition(ofVec2f position);
    
    ofVec2f getDirection();
    void setDirection(ofVec2f direction);
    bool isAlive() const;
    ofRectangle bounds();
    void collidedWith(GameObject* other);
    ofVec3f getColor() const;

	~Player();
};
