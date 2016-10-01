//
//  player.h
//  colors
//
//  Created by ViniGodoy on 30/09/16.
//
//

#pragma once
#include "ofMain.h"

#include "Emitter.h"
#include "NewtonPhysics.h"
#include "ColoredBody.h"

using namespace math;
using namespace particle;
using namespace particle::physics;
using namespace particle::body;

class Player {
    private:
        Emitter* emitter;
        ColoredBody* body;
        NewtonPhysics* physics;
    
    public:
        void setup();
        void update(float time);
        void draw();
        void setColor(int r, int g, int b);
        ofVec2f getPosition();
        void setPosition(ofVec2f position);
        ~Player();
};
