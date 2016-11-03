#pragma once
#include "ofMain.h"

#include "Emitter.h"
#include "NewtonPhysics.h"
#include "ColoredBody.h"
#include "OFRenderer.h"
#include "Animation.h"

using namespace math;
using namespace particle;
using namespace particle::physics;
using namespace particle::body;

class Player {
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
	void setup();
	void update(float time);
	void draw(ofVec2f camera);
	void setColor(int r, int g, int b);
	void interpolateColor(int RGBMode, int value);
    
	ofVec2f getPosition();
	void setPosition(ofVec2f position);
    
    ofVec2f getDirection();
    void setDirection(ofVec2f direction);
	~Player();
};
