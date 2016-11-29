//
//  Fase.h
//  colors
//
//  Created by BEPID on 08/11/16.
//
//

#ifndef Fase_h
#define Fase_h

#include "Screen.h"
#include "Camera.h"
#include "Collectibles.h"
#include "player.h"
#include "GameManager.h"

class Fase : public Screen{
    protected:
        Player* player;
        ofImage background;
		ofImage background2;
        Camera camera;
		ofSoundPlayer sound;
        int indoOuVoltano = 0;
        ofVec3f backgroundColor;

    
    public:

		ofVec2f convertPoint(ofVec2f from, ofVec2f to, ofVec2f position);
        void update(float secs, const MouseInfo& mouse);
        void draw();
    
        virtual void onPortal() = 0;
        virtual void interpolateColor(const ofVec3f& color) = 0;
};


#endif /* Fase_h */
